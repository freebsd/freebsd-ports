--- ./Hands.cpp.orig	2013-10-29 15:12:13.000000000 -0200
+++ ./Hands.cpp	2013-10-29 15:12:13.000000000 -0200
@@ -46,7 +46,7 @@
 		_next = 0;
 }
 
-Hand Hands::HandValue() const
+enum Hands::Hand Hands::HandValue() const
 {
 	return _hand;
 }
@@ -93,7 +93,7 @@
 
 Card** Hands::Cards() const
 {
-	return _cards;
+	return (Card**)_cards;
 }
 
 void Hands::SortCards() const
@@ -106,7 +106,7 @@
 		ranks[i] = _cards[i]->Rank();
 	
 	for(int j=0; j < 4; j++) // sorting based on rank
-		for( i=0; i < 4-j; i++)
+		for(int i=0; i < 4-j; i++)
 		{
 			if( ranks[i] < ranks[i+1] )
 			{
@@ -121,10 +121,10 @@
 
 	char r = ranks[0];
 	char board[4];
-	for( i =0; i<4; i++) board[i] = '\0';
+	for(int i =0; i<4; i++) board[i] = '\0';
 
    int s=1;
-   for ( i=1; i< 6; i++)
+   for (int i=1; i< 6; i++)
    {
 		if( r == ranks[i] ) s++;
 		else{
@@ -162,7 +162,8 @@
    }
 	else{
 		if(ranks[0] == (char) '\14') ranks[5] = '\1';
-		for( i =0; i < 4; i++)
+		int i;
+		for(i =0; i < 4; i++)
 			if(_cards[i]->Suit() != _cards[i+1]->Suit())
 			{
 				i = 8;
@@ -199,9 +200,9 @@
 // rearrange cards order
 
 	Card* tmpcards[5];
-   for(i = 0; i < 5; i++) tmpcards[i] = _cards[i];
-	for(i = 0; i < 5; i++)
-		for(j=0; j<5; j++)
+   for(int i = 0; i < 5; i++) tmpcards[i] = _cards[i];
+	for(int i = 0; i < 5; i++)
+		for(int j=0; j<5; j++)
 			if(tmpcards[j] && ranks[i]==tmpcards[j]->Rank())
 			{
 				((Hands*)this) ->_cards[i] = tmpcards[j];
@@ -210,7 +211,7 @@
 			}
 
 #ifdef DEBUG
-		for(i = 0; i < 5; i++)
+		for(int i = 0; i < 5; i++)
 		  cout << _cards[i]->Suit() << (int) _cards[i]->Rank() << " ";
       cout << endl;
 #endif
@@ -219,9 +220,9 @@
 
 void    Hands::ReArrange(char* ranks , int nel,char* board, Hand score)
 {
-	int j=0 , k = 0;
+	int i, j=0 , k = 0;
 	char tmprank[10];
-   for( int i = 0; i < nel; i++)  // copy all the cards to the tmprank
+   for( i = 0; i < nel; i++)  // copy all the cards to the tmprank
 		tmprank[i] = *(ranks+i);
 	tmprank[nel] = '\0';
 
