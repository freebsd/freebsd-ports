--- bonus.c.orig	1996-11-22 01:28:46 UTC
+++ bonus.c
@@ -120,7 +120,7 @@ enum BonusStates 	BonusState;
 static Pixmap 	titlePixmap, titlePixmapM;
 static int 		ypos;
 static int 		waitingFrame;
-enum BonusStates		waitMode;
+extern enum BonusStates		waitMode;
 static char 	string[80];
 static u_long 	bonusScore;
 static int 		firstTime = True;
@@ -311,7 +311,7 @@ void DrawTitleText(display, window)
 	XFlush(display);
 
 	SetBonusWait(BONUS_SCORE, frame + 5);
-	SetGameSpeed(SLOW_SPEED);
+	SetGameSpeed(MEDIUM_SPEED);
 
 	DEBUG("set bonus mode to BONUS_SCORE.")
 }
@@ -326,7 +326,7 @@ static void DoScore(display, window)
 {
 	DEBUG("in function DoScore() in bonus.c")
 
-	SetGameSpeed(SLOW_SPEED);
+	SetGameSpeed(MEDIUM_SPEED);
 
 	/* Nice message rewarding you for your efforts */
 	strcpy(string, "Congratulations on finishing this level.");
@@ -336,7 +336,7 @@ static void DoScore(display, window)
 
 	ypos += (35 + GAP);
 	SetBonusWait(BONUS_BONUS, frame + LINE_DELAY);
-	SetGameSpeed(SLOW_SPEED);
+	SetGameSpeed(MEDIUM_SPEED);
 	DEBUG("set bonus mode to BONUS_BONUS.")
 }
 
@@ -387,7 +387,7 @@ static void DoBonuses(display, window)
 			DrawShadowCentredText(display, window, textFont, 
 				string, ypos, blue, TOTAL_WIDTH);
 
-			SetGameSpeed(SLOW_SPEED);
+			SetGameSpeed(MEDIUM_SPEED);
 
 			/* Now skip to the next sequence */
 			SetBonusWait(BONUS_LEVEL, frame + LINE_DELAY);
@@ -411,7 +411,7 @@ static void DoBonuses(display, window)
 			bonusScore += ComputeScore(SUPER_BONUS_SCORE);
 			DisplayScore(display, scoreWindow, bonusScore);
 	
-			SetGameSpeed(SLOW_SPEED);
+			SetGameSpeed(MEDIUM_SPEED);
 
 			/* Now skip to the next sequence */
 			SetBonusWait(BONUS_LEVEL, frame + LINE_DELAY);
@@ -454,7 +454,7 @@ static void DoBonuses(display, window)
 		ypos += (int) (textFont->ascent + GAP * 1.5);
 		firstTime = True;
 
-		SetGameSpeed(SLOW_SPEED);
+		SetGameSpeed(MEDIUM_SPEED);
 	}
 }
 
@@ -468,7 +468,7 @@ static void DoLevel(display, window)
 {
 	int secs, theLevel;
 
-	SetGameSpeed(SLOW_SPEED);
+	SetGameSpeed(MEDIUM_SPEED);
 
 	/* Get the number of seconds left on the clock */
 	secs = GetLevelTimeBonus();
@@ -533,7 +533,7 @@ static void DoBullets(display, window)
 			/* Play the sound for the super bonus */
 			if (noSound == False) playSoundFile("Doh3", 80);
 			
-			SetGameSpeed(SLOW_SPEED);
+			SetGameSpeed(MEDIUM_SPEED);
 
 			/* Get ready for the next sequence */
 			SetBonusWait(BONUS_TIME, frame + LINE_DELAY);
@@ -569,7 +569,7 @@ static void DoBullets(display, window)
 		SetBonusWait(BONUS_TIME, frame + LINE_DELAY);
 		ypos += (textFont->ascent + GAP/2);
 		firstTime = True;
-		SetGameSpeed(SLOW_SPEED);
+		SetGameSpeed(MEDIUM_SPEED);
 	}
 }
 
@@ -583,7 +583,7 @@ static void DoTimeBonus(display, window)
 {
 	int secs = 0;
 
-	SetGameSpeed(SLOW_SPEED);
+	SetGameSpeed(MEDIUM_SPEED);
 
 	/* Get the number of seconds left on the clock */
 	secs = GetLevelTimeBonus();
@@ -627,7 +627,7 @@ static void DoHighScore(display, window)
 	int myrank = 0;
 	char str[5];
 
-	SetGameSpeed(SLOW_SPEED);
+	SetGameSpeed(MEDIUM_SPEED);
 
 	/* Obtain current ranking for this score */
 	myrank = GetHighScoreRanking(score);
@@ -680,7 +680,7 @@ static void DoEndText(display, window)
 {
 	DEBUG("DoEndText in bonus screen.")
 
-	SetGameSpeed(SLOW_SPEED);
+	SetGameSpeed(MEDIUM_SPEED);
 
 	/* Finishing sentence - so you know what level to do */
 	sprintf(string, "Prepare for level %ld", level+1);
