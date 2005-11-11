--- src/scramble.c.orig	Thu Nov 10 05:20:17 2005
+++ src/scramble.c	Thu Nov 10 05:22:01 2005
@@ -290,14 +290,13 @@
  ****************************************************/
 void putLetter(char * ch, int s)
 {
-	if(!running)
-		return;
-
 	char ch2[2];
+	SDL_Rect dest;
 	ch2[0] = toupper(ch[0]);
 	ch2[1] = 0;
-
-	SDL_Rect dest;
+
+	if(!running)
+		return;
 
 	s--;
 	
@@ -694,6 +693,8 @@
 
 	for(i = 0; i < numberCurrentWords; i++) {
 		if(strcmp(wordAttempt, currentWordSet[i]) == 0 && currentWordSetShow[i] == 0) {
+			double per;
+
 			currentWordSetShow[i] = 1;
 			playSound(hitSound);	
 
@@ -706,7 +707,7 @@
 			stateChanged = 1;
 			redrawAll = 1;
 			wordsFound++;
-			double per = ((double)wordsFound / (double)numberCurrentWords);
+			per = ((double)wordsFound / (double)numberCurrentWords);
 			if(per > percentage) {
 				nextLevel = 1;
 				if(nextLevel % 5 && percentage < .8)
@@ -1127,9 +1128,10 @@
  ****************************************************/
 void letter(char c)
 {
+	int i;
 	if(!running)
 		return;
-	int i;
+
 	for(i = 0; i < 6; i++) {
 		if(c == letters[i].letter[0] && !letters[i].played) {
 			playSound(clickSound);
