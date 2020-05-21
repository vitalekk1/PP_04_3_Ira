// PP_04_3_CPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <malloc.h>
#include <conio.h>
#include <stdio.h>
void ShellSort(int n, int mass[]);
int main()
{
	setlocale(LC_ALL, "Russian");
	//ввод N
	int N;
	printf("Введите количество элементов: ");
	scanf_s("%d", &N);
	//выделение памяти под массив
	int* mass;
	mass = (int*)malloc(N * sizeof(int));
	//ввод элементов массива
	printf("Введите элементы:\n");
	for (int i = 0; i < N; i++)
		scanf_s("%d", &mass[i]);
	//сортировка методом Шелла
	ShellSort(N, mass);
	//вывод отсортированного массива на экран
	printf("Отсортированные элементы:\n");
	for (int i = 0; i < N; i++)
		printf("%d ", mass[i]);
	printf("\n");
	//освобождение памяти
	free(mass);
	_getch();
	return 0;
}

void ShellSort(int n, int mass[])
{
	int i, j, step;
	int tmp;
	int chunk = 5;
	#pragma omp parallel for default(shared) schedule(dynamic, chunk)
	{
		for (step = n / 2; step > 0; step /= 2)
		{
			for (i = step; i < n; i++)
			{
				tmp = mass[i];
				for (j = i; j >= step; j -= step)
				{
					if (tmp < mass[j - step])
						mass[j] = mass[j - step];
					else
						break;
				}
				mass[j] = tmp;
			}
		}
	}
}


