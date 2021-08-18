#include <iostream>
#include <windows.h>
using namespace std;

template<class X>
void createArray(X*& arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = (rand() % (1000 - 0 + 1) + 0)/double(10);
	}
}

void createArray(char*& arr, const int size, char A, char B)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = char(rand() % (int(B) - int(A) + 1) + int(A));
	}
}

template<class X>
void printArray(X* arr, const int size)
{
		cout << "Массив: ";
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
}

template<class X>
void findMin(X* arr, const int size)
{
	int i, m=0;
	X min = arr[0];
	for (i = 1; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			m = i;
		}
	}
	cout << "Минимальный элемент: " << min<<"     "<< "Индекс: " << m<<endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	int size;
	cout << "Введите размерность массива: ";
	cin >> size;
	char A, B;
	int* intArray = new int[size];
	char* charArray = new char[size];
	double* doubleArray = new double[size];
	cout << "Введите диапазон символов (к примеру a-z)"<<endl;
	cout << "Введите начало диапазона: ";
	cin >> A;
	cout << "Введите конец диапазона: ";
	cin >> B;
	if (int(A) > int(B))
	{
		cout<<"Неверный диапазон! Попробуйте еще"<<endl;
		return 0;
	}
	cout << endl;
	createArray(charArray, size, A, B);
	createArray(doubleArray, size);
	createArray(intArray, size);
	printArray(charArray, size);
	printArray(doubleArray, size);
	printArray(intArray, size);
	cout << endl;
	findMin(charArray, size);
	findMin(doubleArray, size);
	findMin(intArray, size);
	delete[] charArray;
	delete[] doubleArray;
	delete[] intArray;
}