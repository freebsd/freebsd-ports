--- src/torrent.c.orig	2013-06-17 21:58:19.795111620 +0400
+++ src/torrent.c	2013-06-17 21:58:27.445112740 +0400
@@ -328,6 +328,8 @@
 	int x, y;
 
 	if(++level > LEVELSIZE) {
+		int y;
+
 		level--; //to keep from showing -1 on board
 		playSound(levelOverSound);
 		stateChanged = 1;
@@ -340,10 +342,11 @@
 
 
 		// Count number of empty layers and remaining blocks
-		for(int y = 0; y < yBSize; y++) {
+		for(y = 0; y < yBSize; y++) {
+			int x;
 			int start = remaining;
 
-			for(int x = 0; x < xBSize; x++) {
+			for(x = 0; x < xBSize; x++) {
 				if(board[y][x])
 					remaining++;
 			}
@@ -693,10 +696,10 @@
 {
 	static char odd = 0;
 	if((scoreAdd || scoreTexts) && !drawing) {
+		struct scoreText * t = scoreTexts;
 		odd = !odd;
 		drawing = 1;
 		/* draw the text scores */
-		struct scoreText * t = scoreTexts;
 		while(t && odd) {
 			SE_Redraw();
 			drawing = 0;
@@ -857,9 +860,9 @@
  ****************************************************/
 int clickBomb(enum Color color, enum Color bombColor)
 {
+	int c = 0, x, y;
 	playSound(bombClickSound);
 	isBomb = 1;
-	int c = 0, x, y;
 	for(y = 0; y < yBSize; y++) {
 		for(x = 0; x < xBSize; x++) {
 			if(board[y][x] && (board[y][x]->color == color ||
@@ -1045,7 +1048,7 @@
 
 /*****************************************************
  ****************************************************/
-inline void SE_CheckEvents()
+void SE_CheckEvents()
 {
 	SDL_Event event;
 	int x, y;
