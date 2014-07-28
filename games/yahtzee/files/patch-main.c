--- main.c.orig	Sat Jan 25 17:41:13 1992
+++ main.c	Thu Nov  6 18:12:58 2003
@@ -12,7 +12,7 @@
  * (c)1992 by orest zborowski
  */
 
-static char *header = "Yahtzee  Version 1.00  (c)1992 by zorst";
+static char *header = "Yahtzee Version 1.00p1   (c)1992 by zorst, FreeBSD port by Joel Sutton";
 
 extern errno;
 
@@ -138,7 +138,7 @@
 
 	initscr();
 	if (LINES < 23)
-		abort("Not enough lines on the terminal");
+		_abort("Not enough lines on the terminal");
 	numlines = LINES;
 	clear();
 	mvaddstr(0, 9, header);
@@ -156,7 +156,7 @@
 	endwin();
 }
 
-abort(char *msg)
+_abort(char *msg)
 {
 	yend();
 	putchar('\n');
@@ -278,7 +278,7 @@
 	int j;
 
 	if (num < 1 || num > 5)
-		abort("Bad dice loc passed");
+		_abort("Bad dice loc passed");
 
 	for (j = 0; j < 1; ++j)
 	{
@@ -820,6 +820,7 @@
 	int i;
 	int topscore;
 	int winner;
+	char dummy[5];
 
 	for (;;)
 	{
@@ -844,7 +845,9 @@
 			winner = i;
 		}
 
-	say("The winner is %s", players[winner].name);
+	say("The winner is %s. Press <enter> to continue...", players[winner].name);
+	fgets(dummy,5,stdin);
+	fflush(stdin);
 }
 
 #define L_LOCK 0
@@ -1117,7 +1120,8 @@
 
 	printf ("How many times to you wish to roll? ");
 
-	gets(nrollstr);
+	fflush(stdin);
+	fgets(nrollstr, 10, stdin);
 	nroll = atoi(nrollstr);
 
 	printf("Generating...\n");
@@ -1270,6 +1274,7 @@
 				printf("How many computers to play (max of %d) ? ",
 				  MAX_NUMBER_OF_PLAYERS - num_players);
 				fflush(stdout);
+				fpurge(stdin);
 
 				fgets(num, sizeof(num), stdin);
 
