
$FreeBSD$

--- prez/parse.y.orig
+++ prez/parse.y
@@ -40,6 +40,10 @@
 int message (const char *, ...);
 void savegame (const char *);
 void play_ai (void);
+void bigmessage (const char * mesg);
+int yylex (void);
+void loadgame (const char * file);
+void yyerror (const char * errmesg);
 
 game_t  SGBgame;  /* The game we're playing!! :) */
 int SGBplaysinround;  /* How many plays have taken place in this round */
@@ -351,17 +355,17 @@
 		         "\tQUIT\n");
 		}
 	| command PLAY set '\n' {
+		int okay_to_play_ai;
 		int goer = ass_turn (SGBgame);
 		hand_t h = ass_Hand (
 		    ass_GamePlayer (SGBgame, ass_turn (SGBgame)));
 
+		okay_to_play_ai = 1;
 		if (ptypes[goer-1] == tAI) {
 			message ("You can't make moves for an AI.  "
 			         "Try just \"PLAY\"\n");
-			goto falsebreak;
-		}
-
-		if (ass_turn (SGBgame)) {
+			okay_to_play_ai = 0;
+		} else if (ass_turn (SGBgame)) {
 			if (!ass_setlt (ass_GameDown (SGBgame), &$3)) {
 				message ("You can't lay that set!!\n");
 				message ("Maybe you should do \"PLAY pass\" "
@@ -397,9 +401,9 @@
 		} else
 			message ("You must \"DEAL\" first.\n");
 
-		play_ai ();
-
-falsebreak:
+		if (okay_to_play_ai) {
+			play_ai ();
+		}
 	}
 	| command PLAY '\n' {
 #ifdef DEBUG
@@ -555,6 +559,8 @@
 	| ACE_T { $$ = ACE; }
 	| TWO_T { $$ = TWO; }
 	| JOKER_T { $$ = JOKER; }
+;
+
 %%
 
 void
@@ -625,7 +631,7 @@
 yylex (void) {
 	static char s[81];  /* What kind of initialization guarantees
 	                     * am I given here????? */
-	static return_nl_f = 0;  /* Return a \n token? */
+	static int return_nl_f = 0;  /* Return a \n token? */
 	char * t = NULL;
 	int i;
 
@@ -696,7 +702,7 @@
  */
 int
 message (const char * mesg, ...) {
-	static on = 1;
+	static int on = 1;
 	va_list va;
 	int x;
 
@@ -874,7 +880,7 @@
 
 
 int
-main (char *c, char **v) {
+main (int c, char **v) {
 	int i;
 
 	printf ("TVP, prez CLI, Copyright (C) 1997, Timothy M. Vanderhoek\n"
