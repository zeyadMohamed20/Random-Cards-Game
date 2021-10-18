#include<conio.h>
#include<ctime>
#include <iostream>
#include<string>
#include<vector>
using namespace std;


int search_queen(char *A, int size)
{
	int i{};
	for (i = 0; i < size; i++)
	{
		if (A[i] == 'Q')
		{
			break;
		}
	}
	return i;
}

void swaping(char *a, char* b)
{
	char temp{};
	temp = *a;
	*a = *b;
	*b = temp;
}

void random_cards(char* A, int size)
{
	unsigned short int oldNumber{};
	unsigned short int newNumber{};

	oldNumber = search_queen(A, size);
	srand((unsigned int)time(nullptr));
	newNumber = rand() % 3;
	swaping(A + oldNumber , A + newNumber);
}

void print_array(char* A, int size)
{
	cout << "The order is ";
	for (int i = 0; i < size; i++)
	{
		if (A[i] == 'Q')
		{
			cout << "Queen ";
		}
		else if (A[i] == 'K')
		{
			cout << "King ";
		}
		else if (A[i] == 'J')
		{
			cout << "Joker ";
		}
	}
}

int main()
{
	unsigned short int bet{};
	int money{100};
	int queenNumber{};
	char A[4]{ 'Q','K','J','\0'};
	int size = sizeof(A) / sizeof(A[0]);

	cout << "Visual studio casino!!\n";
	cout << "You have 100 $\n\n";

	while (money > 0)
	{
		cout << "What is your bet $\n";
		cin >> bet;
		if (bet > 0 && bet <= money)
		{
			random_cards(A, size);
			cout << "shuffling.....\n";
			cout << "Guess the queen number\n";
			cin >> queenNumber;

			if (A[queenNumber - 1] == 'Q')
			{
				cout << "You win\n";
				money = money + 3 * bet;
				print_array(A, size);
				cout << "\n";
				cout << "Now you have " << money << "$" << "\n";
			}
			else if (A[queenNumber - 1] != 'Q')
			{
				cout << "You lose\n";
				money = money - bet;
				print_array(A, size);
				cout << "\n";
				cout << "Now you have " << money << "$" << "\n";
			}
			cout << "*****************************************\n";
		}
		
	}
	

}


