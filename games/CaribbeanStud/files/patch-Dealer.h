--- Dealer.h.orig	Tue Aug 19 11:59:05 2003
+++ Dealer.h	Tue Aug 19 12:00:14 2003
@@ -92,7 +92,8 @@
 
 inline void Dealer::Add    (Player* newPlayer)
 {
-   for(int i=0; i < 10; i++)
+   int i;
+   for(i=0; i < 10; i++)
       if( !_players[i] ){
 			_players[i] = newPlayer;
          break;
@@ -102,8 +103,8 @@
 
 inline void Dealer::Remove (Player* aplayer)
 {
-   int pos = 20;
-	for(int i=0; _players[i]; i++)
+   int pos = 20, i;
+	for(i=0; _players[i]; i++)
 		if(aplayer == _players[i])
 		{
 			pos = i; break;
