--- Deck.cpp.orig	Tue Aug 19 12:02:29 2003
+++ Deck.cpp	Tue Aug 19 12:05:01 2003
@@ -38,7 +38,8 @@
 			_globalCards[j] = Card(j);
 		_globalInit = 1;
 	}
-   for(int i =0 ; i < _numOfCards; i++)
+   int i;
+   for(i =0 ; i < _numOfCards; i++)
 		 _cards[i] = &	_globalCards[i];
    for(i=_numOfCards; i < 54; i++)
 		 _cards[i] = (Card *) 0;
@@ -55,7 +56,7 @@
 	{
 		for (int i = 0; i < _numOfCards/2; i++)
         to[i*2] = from[_numOfCards/2+i];
-		for ( i = 0; i < _numOfCards/2; i++)
+		for (int i = 0; i < _numOfCards/2; i++)
         to[i*2+1] = from[i];
 		Card **tmp = from;
       from = to;
@@ -82,13 +83,13 @@
 
 	for(int i=_numOfCards-cut; i< _numOfCards; i++)
 		tmp[i] = _cards[i];
-   for( i = _numOfCards-1; i >= cut; i--)
+   for(int i = _numOfCards-1; i >= cut; i--)
 		_cards[i] = _cards[i-cut];
-	for( i = 0; i < cut; i++)
+	for(int i = 0; i < cut; i++)
 		_cards[ i ] = tmp[i + _numOfCards-cut];
 #ifdef DEBUG
 	cout << "Cutting at " << _numOfCards-cut <<endl;
-   for ( i = 0; i < _numOfCards; i++ ){
+   for (int i = 0; i < _numOfCards; i++ ){
 		if( i%10 == 0 ) cout << endl;
 		cout << _cards[i]->Suit() << (int)_cards[i]->Rank() << " ";
    }
