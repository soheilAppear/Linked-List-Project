

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <time.h>

using namespace std;

class Node
{
public:

	friend void input_Class_Parameters_And_Print_Menu(); 


	void traverse( Node * x)
	{
		Node * temp;
		temp = x;
		cout << endl;
		cout << "\t\t << All Nodes >> "<<endl;
		while (temp != NULL)
		{
			cout <<"\n\n\t\t-----------------\n\n\t\t\t"<< temp -> data;
			temp = temp -> link;
		}
	}

	void insertNode( Node * x , int insertKey/* , int insertNumberNode*/)
	{

		
		Node * temp;
		Node * y;
		y = new Node;   // so we conclude that in the own class with dynamic memory allocation we can create a variable form that own class

		y -> data = insertKey;
		y -> link = NULL;

		if(x -> link == NULL) // if we have just one Node ( our Node has a constant number ( 0 ) ) insert the Node after the first Node.
		{
			 x -> link = y;
			 cout << "added after first node (infact first node)\n" ;
		}

	//else if (x -> link != NULL)  // How can i create it
	//{
	//	temp = x;
	//	while (temp -> data == insertNumberNode)
	//	{
	//		x = y -> link;
	//		temp -> link = y;
	//		
	//           printf("added later\n");
	//           break; // Change 3
	//	}
	//}

	  else
	  {
        //else loop through the list and find the last
        //node, insert next to it
       
		  temp = x;

			while (true)   // Can we use here while ( temp != NULL) { // Do ...} ??
			{
				 if(temp -> link == NULL)
				 {
                temp -> link = y;
                cout << "added at last node\n"<<endl;
                break; // after using this if , exit from it.
				 }

				 temp = temp -> link;
		  };

		}
		 
	}

				
		


	void deleteNode(Node * x, int deleteKey)
	{
		Node * temp;
		Node * y;
		temp = x;
		y = x;

		while (temp != NULL)
		{

			if (temp -> data == deleteKey)
			{
				if (x == temp)  // if our link list has one member , delete temp
				{
					x = x->link;
					delete(temp);
				}
				else
				{
					y = x;

					while(y -> link != temp) 
					{
						y = y->link;
					}
					y->link = temp->link;
					delete(temp);
				} 

				break;
			}

				temp = temp -> link;	
		}

	}

	void MinAndMax(Node *x)
	{
	    Node * temp;
		temp = x;
		int max , min;
		max = min = temp -> data;

		while (temp != NULL)
		{
			if(temp-> data > max)
			{
			 max = temp -> data;
			}

			else if (temp -> data < min)
			{
             min = temp -> data;
			}

			temp = temp -> link;
		}

		cout << "\nMin is : " << min << "\nMax is : " << max << endl;
	}

	Node * searchNode(Node * x , int key)
	{
		Node * temp;

		temp = x;
	
	while(temp!=NULL)
	{
		if (temp -> data == key)
		{
			cout << "Found it"; // please return temp address
			cout << "\nThe address of your node is : " << (&temp);		// We should put & befor themp, cause we need temp's pointing address. if we wanted pointer's address we just need temp address
			return (/*temp -> link*/ temp);
		    break;
		}

		temp = temp->link;
	}
		if (temp == NULL)
		{
			cout << "Not Found\n"; // return null
			cout <<"NULL is : "<< NULL<<endl;
			return NULL;
		}

	}
	
	///////////// RE dar morede inke raveshe dorostio entekhab kardam ya na

	void get_first_last_node(Node *x, int number_loop)
	{
		Node * temp;
		temp = x;
		temp = temp -> link;
	   cout <<"The first element is : " <<	temp -> data <<endl;
	
	   for (int i = 0; i < number_loop - 1  ; i++) // -1 is because of i push my node once to front , After 0.. because i used 0 for trick node and make no problem in my list at the first node.
	   {
		   temp = temp -> link; 
	   }

	   cout << "\nThe last element is : " << temp -> data <<endl;	
	}


	void averageFunc( Node * x , int number_average)
	{
		Node * temp;
		temp = x;
		long double average = 0;;

		while (temp != NULL)
		{
		    average = average + (temp->data);
			temp = temp -> link;
		}

		cout <<"\nThe average is : " << setprecision(20)<< (average) / 1000 <<endl<<endl;		
	}

	void standardDev (Node * x , int number_average)	
	{
		double divAverage = 0;
		long int tempData;
		int sigmaTemplate = 0;
		Node * temp;
		Node * temp2;
		temp = x;
		temp2 = x;
		int average = 0;
		long double standardDiviationVariable;

		while (temp != NULL)
		{
			average = average + (temp->data);
			temp = temp -> link;
		}

		divAverage = (average / number_average);

	for ( int i = 0; i < number_average -2 ; i++ )
	{
		
		tempData = (temp2->data - divAverage);
		sigmaTemplate += pow(tempData,2);
		temp2 = temp2 -> link;

	}

	standardDiviationVariable = sqrt((sigmaTemplate/ number_average)); 

	cout << "\nStandard diviation is : " << setprecision(20) << standardDiviationVariable <<endl;

	} 


	void variance (Node * x, int number_average)	
	{
		double divAverage = 0;
		long int tempData;
		int sigmaTemplate = 0;
		Node * temp;
		Node * temp2;
		temp = x;
		temp2 = x;
		int average = 0;
		long double varianceVar;

		while (temp != NULL)
		{
			 average = average + (temp->data);
			temp = temp -> link;
		}

		divAverage = (average / number_average);

	for ( int i = 0; i < number_average - 2 ; i++ )	//Change the value of this loop for looping..
	{
		
		tempData = (temp2->data - divAverage);
		sigmaTemplate += pow(tempData,2);
		temp2 = temp2 -> link;

	}

	varianceVar = (( sigmaTemplate/number_average));

	cout << "\nVariance is : " << setprecision(20) << varianceVar <<endl;

	}


	
	void quantityOfEachNumber(Node * x , int key)
	{

		Node * temp;

		int number = 0;
		cout << "\nEnter the number for getting quantity of reapiting : \n"<<endl;
		
		temp = x;	

		cout <<"Enter the key : ";
		cin >> key;

		while (temp != NULL)
		{

			if (temp -> data == key)
			{
				number++;
			}

		temp = temp->link;

		}

		cout << "\nThe quantity of key reapiting is : " << number<<endl;
		
	}


	// Problem of showing last to first

	void showingLastToFirst(Node * x)
	{
		if (x != NULL)
		{
			cout << x -> data << endl<<endl;
			showingLastToFirst( x -> link );
		}
	}


	
	// End Public

private:

	int data;
	Node * link;
	//End Private
};


void input_Class_Parameters_And_Print_Menu();

int main()
{
	input_Class_Parameters_And_Print_Menu();

	_getch();
	return 0;
}

void input_Class_Parameters_And_Print_Menu()
{

	srand(time(NULL));   // for not repeating randoms number again.. It's header file is #include <time.h>

	string start = "\n\n\t\tWelcome to my program\a\n\t\t----------------------\n\n\n";
	int number, num , deleteKey,insertKey, insertNumberNode;
	int n;
	//int keyAllQuantity[1000];
	int keyPublic = NULL;
	Node * y;
	for (auto ch : start)
	{
        cout << ch;
        Sleep(15);
    }
	bool out = false;

		Node *temp;
		Node *x = new (Node);
		x ->data = 0;
		x ->link = NULL;
		temp = x;	

		cout << "\t\tEnter the number of nodes : ";
		cin >> n;

	for (int j = 0; j< n ;j++)
	{
			y = new (Node);
			(y-> data) = rand() % /*1000*/n + 1;
			y -> link = NULL;
			temp -> link = y;
			temp = temp -> link; 

	} 

			
		do
		{
					cout << "\t------------------------------------\n";
					cout <<"\n\n\t1) print all elements(Teravers)\n\n\t2) Min and Max\n\n\t3) Average\n\n\t4) First and last element\n\n\t5) Search an element\n\n\t6) Add an element\n\n\t7) Delete an element\n\n\t8) Standard Diviation\n\n\t9) Variance\n\n\t10) Getting searching number quantity\n\n"<<endl;	
					cin >> number;

				switch (number)
				{
				case 1:
					x->traverse(x);
					break;
				case 2:
					x->MinAndMax(x);
					break;
				case 3:
					x ->averageFunc(x,n);
					break;
				case 4:
					x -> get_first_last_node(x,n);
					break;
				case 5:
					{
					cout << "----------------\nEnter the key : " << endl;
						cin >> num;
					x -> searchNode(x, num);
					}
					break;
				case 6:
					{
					cout << "----------------\nEnter the key : " << endl;
					
					cin >> insertKey;
					x -> insertNode(x,insertKey/*,insertNumberNode*/);
					}
					break;
				case 7:
					{
					cout << "----------------\nEnter the key : " << endl;
					cin >> deleteKey;
					x -> deleteNode(x , deleteKey);
					}
					break;
				case 8:
					x-> standardDev(x,n);
					break;
				case 9:
					x-> variance(x,n);
					break;
				case 10:
					x -> quantityOfEachNumber(x,keyPublic);

				default:
					break;
				}
				cout << "\n\n----------------\nDo you want to exit ?( yes = 1 , no = 0 ) " <<endl;
				cin >> out;
				cout <<'\a';
			} 
				while (!out);

		delete temp;
		exit(0);
	}
