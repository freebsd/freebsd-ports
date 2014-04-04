--- bonus.c.orig	Thu Nov 20 03:12:56 1997
+++ bonus.c	Thu Nov 20 03:15:32 1997
@@ -311,7 +311,7 @@
 	XFlush(display);
 
 	SetBonusWait(BONUS_SCORE, frame + 5);
-	SetGameSpeed(SLOW_SPEED);
+	SetGameSpeed(MEDIUM_SPEED);
 
 	DEBUG("set bonus mode to BONUS_SCORE.")
 }
@@ -326,7 +326,7 @@
 {
 	DEBUG("in function DoScore() in bonus.c")
 
-	SetGameSpeed(SLOW_SPEED);
+	SetGameSpeed(MEDIUM_SPEED);
 
 	/* Nice message rewarding you for your efforts */
 	strcpy(string, "Congratulations on finishing this level.");
@@ -336,7 +336,7 @@
 
 	ypos += (35 + GAP);
 	SetBonusWait(BONUS_BONUS, frame + LINE_DELAY);
-	SetGameSpeed(SLOW_SPEED);
+	SetGameSpeed(MEDIUM_SPEED);
 	DEBUG("set bonus mode to BONUS_BONUS.")
 }
 
@@ -387,7 +387,7 @@
 			DrawShadowCentredText(display, window, textFont, 
 				string, ypos, blue, TOTAL_WIDTH);
 
-			SetGameSpeed(SLOW_SPEED);
+			SetGameSpeed(MEDIUM_SPEED);
 
 			/* Now skip to the next sequence */
 			SetBonusWait(BONUS_LEVEL, frame + LINE_DELAY);
@@ -411,7 +411,7 @@
 			bonusScore += ComputeScore(SUPER_BONUS_SCORE);
 			DisplayScore(display, scoreWindow, bonusScore);
 	
-			SetGameSpeed(SLOW_SPEED);
+			SetGameSpeed(MEDIUM_SPEED);
 
 			/* Now skip to the next sequence */
 			SetBonusWait(BONUS_LEVEL, frame + LINE_DELAY);
@@ -454,7 +454,7 @@
 		ypos += (int) (textFont->ascent + GAP * 1.5);
 		firstTime = True;
 
-		SetGameSpeed(SLOW_SPEED);
+		SetGameSpeed(MEDIUM_SPEED);
 	}
 }
 
@@ -468,7 +468,7 @@
 {
 	int secs, theLevel;
 
-	SetGameSpeed(SLOW_SPEED);
+	SetGameSpeed(MEDIUM_SPEED);
 
 	/* Get the number of seconds left on the clock */
 	secs = GetLevelTimeBonus();
@@ -533,7 +533,7 @@
 			/* Play the sound for the super bonus */
 			if (noSound == False) playSoundFile("Doh3", 80);
 			
-			SetGameSpeed(SLOW_SPEED);
+			SetGameSpeed(MEDIUM_SPEED);
 
 			/* Get ready for the next sequence */
 			SetBonusWait(BONUS_TIME, frame + LINE_DELAY);
@@ -569,7 +569,7 @@
 		SetBonusWait(BONUS_TIME, frame + LINE_DELAY);
 		ypos += (textFont->ascent + GAP/2);
 		firstTime = True;
-		SetGameSpeed(SLOW_SPEED);
+		SetGameSpeed(MEDIUM_SPEED);
 	}
 }
 
@@ -583,7 +583,7 @@
 {
 	int secs = 0;
 
-	SetGameSpeed(SLOW_SPEED);
+	SetGameSpeed(MEDIUM_SPEED);
 
 	/* Get the number of seconds left on the clock */
 	secs = GetLevelTimeBonus();
@@ -627,7 +627,7 @@
 	int myrank = 0;
 	char str[5];
 
-	SetGameSpeed(SLOW_SPEED);
+	SetGameSpeed(MEDIUM_SPEED);
 
 	/* Obtain current ranking for this score */
 	myrank = GetHighScoreRanking(score);
@@ -680,7 +680,7 @@
 {
 	DEBUG("DoEndText in bonus screen.")
 
-	SetGameSpeed(SLOW_SPEED);
+	SetGameSpeed(MEDIUM_SPEED);
 
 	/* Finishing sentence - so you know what level to do */
 	sprintf(string, "Prepare for level %ld", level+1);
--- main.c.orig	Thu Nov 20 03:15:34 1997
+++ main.c	Thu Nov 20 03:15:54 1997
@@ -156,7 +156,7 @@
 
 	/* Set an entire game speedup or slowdown speed */
 	temp = (speed / (long) userDelay);
-	userDelay = delay;
+	userDelay = delay/2 + 3;
 	speed = (long) (temp * userDelay);
 	speedLevel = 10 - delay;
 }
--- misc.c.orig	Fri Nov 22 09:28:46 1996
+++ misc.c	Thu Nov 20 03:18:15 1997
@@ -89,8 +89,8 @@
 #ifdef SYSV
 #ifdef __clipper__
     struct timeval tv;
-    tv.tv_sec=((usec)/1000);
-    tv.tv_usec=(((usec)%1000)*1000);
+    tv.tv_sec=((usec)/1000000);
+    tv.tv_usec=((usec)%1000000);
     select(1,NULL,NULL,NULL,&tv);
 #else
     poll((struct poll *) 0, (size_t) 0, usec / 1000);   /* ms resolution */
@@ -105,6 +105,68 @@
 #endif
 
 #if NeedFunctionPrototypes
+static	int	kudelay(unsigned long count)
+#else
+static	int	kudelay(count)
+unsigned long count;
+#endif
+{
+    unsigned int	bluff = 1;
+
+    while( count-- != 0 )	/* this can hardly be "optimised out" */
+	bluff = (bluff ^ ((bluff & 1) * 0x6110)) >> 1;
+
+    return( bluff );
+}
+
+#if NeedFunctionPrototypes
+static	void kusleep(unsigned long usec)
+#else
+static	void kusleep(usec)
+        unsigned long usec;
+#endif
+{
+    static float	kuliber_time = 0.0;
+    static float	kuliber_count = 0.0;
+    static unsigned long	kutimerswap = (1000000 / 15);
+    struct timeval	st, et;
+    long		gap;
+    unsigned long	count;
+
+    if( kuliber_time == 0.0 )
+    {
+	count = 0x1000;		/* calibrate delay loop */
+	gettimeofday(&st, NULL);
+
+	while( True )
+	{
+	    kudelay( count );
+	    count = (count << 1);
+	    gettimeofday(&et, NULL);
+	    gap = (((et.tv_sec - st.tv_sec) * 1000000) +
+			(et.tv_usec - st.tv_usec) );
+
+	    if( gap > 400*1000 )
+		break;
+	}
+
+	kuliber_time = (float)(gap/4);
+	kuliber_count = (float)(((count-1)&~0xFFF)>>2);
+    }
+
+    if( usec > kutimerswap )
+    {
+	kutimerswap = (1000000 / 30);
+	usleep( usec );		/* using usleep() for low resolution only */
+    }
+    else
+    {
+	kutimerswap = (1000000 / 15);
+	kudelay( (unsigned long)(kuliber_count*((float)usec/kuliber_time)) );
+    }
+}
+
+#if NeedFunctionPrototypes
 void sleepSync(Display *display, unsigned long ms)
 #else
 void sleepSync(display, ms)
@@ -112,27 +174,85 @@
     unsigned long ms;
 #endif
 {
-    struct timeval st, et;
-    long SyncTime;
-    static unsigned long accu;
+    static long		Expected_time = 0;
+    static long		Ref_sec = 0;
+    static long		Ref_usec = 0;
+    static long		Sleeping_time = 0;
+    static int		PLL_filter = 0;
+    struct timeval	st;
+    long		elapsed;
+    long		dodelay;
+    float		x;
 
-    gettimeofday(&st, NULL);
     XSync(display, False);
-    gettimeofday(&et, NULL);
 
-    SyncTime = (((et.tv_sec - st.tv_sec) * 1000) +
-               ((et.tv_usec - st.tv_usec) / 1000) );
+    gettimeofday(&st, NULL);
+
+    if( Ref_sec == 0 )
+    {
+	Ref_sec = st.tv_sec;	/* take the initial reference point */
+	Ref_usec = st.tv_usec;
+	Sleeping_time = ms * 1000;
+    }
+
+    elapsed = (st.tv_sec - Ref_sec) * 1000000 + (st.tv_usec - Ref_usec);
+    dodelay = Sleeping_time;
+
+    if( PLL_filter > 0 && elapsed != 0 )	/* Phase lock loop */
+    {
+	dodelay = Expected_time + Sleeping_time - elapsed;
+
+	if( dodelay < 0 )
+	{
+	    dodelay = 0; PLL_filter--;
+	}
+	else
+	    if( dodelay > 2*Sleeping_time )
+	    {
+		dodelay = 2*Sleeping_time; PLL_filter--;
+	    }
+	    else
+		PLL_filter = 3;
+
+	if( elapsed > 40*Sleeping_time && Expected_time > 40*Sleeping_time )
+	{
+	    elapsed -= 20*Sleeping_time; /* Ref. point shouldn't be far away*/
+	    Expected_time -= 20*Sleeping_time;
+	    Ref_usec += 20*Sleeping_time;
+	    Ref_sec += Ref_usec/1000000; Ref_usec %= 1000000;
+	}
+    }
 
-/*    if ((ms) > ((1000 / 60) + SyncTime))
-        usleep(ms - SyncTime);
-*/
-    if ((ms + accu) > ((1000 / 30) + SyncTime)) 
+    if( PLL_filter <= 0 && elapsed > 40000 )	/* Frequency lock loop */
     {
-        usleep(ms +accu - SyncTime);
-        accu = 0;
+	/* feedback filter */
+	x = 0.5 + 0.5 * (float)Expected_time / (float)elapsed;
+
+	if( x < 0.966 )	/* Acceleration must be strongly limited */
+	    x = 0.966;
+
+	if( x > 2.0 )
+	    x = 2.0;
+
+	Sleeping_time = (long)((float)Sleeping_time * x);
+
+	if( Sleeping_time < 500 )
+	    Sleeping_time = 500;
+
+	if( x > 0.99 && x < 1.01 && Sleeping_time > ms*500 )
+	    PLL_filter = -1 - 4*PLL_filter; /* locked - it's time to try PLL */
+	else
+	    PLL_filter = 0;
+
+	Ref_sec = st.tv_sec;
+	Ref_usec = st.tv_usec;
+	Expected_time = 0;
+	dodelay = Sleeping_time;
     }
-    else if (ms > SyncTime)
-       accu += (ms - SyncTime);
+
+    kusleep( dodelay );
+
+    Expected_time += ms * 1000;
 }
 
 #if NeedFunctionPrototypes
--- presents.c.orig	Thu Nov 20 03:18:42 1997
+++ presents.c	Thu Nov 20 03:21:38 1997
@@ -287,7 +287,7 @@
 	}
 #endif
 
-	SetPresentWait(PRESENT_TEXT1, frame + 800);
+	SetPresentWait(PRESENT_TEXT1, frame + 200);
 }
 
 #if NeedFunctionPrototypes
@@ -309,7 +309,7 @@
 	RenderShape(display, window, justin, justinM,
 		x, y, 285, 44, True);
 
-	SetPresentWait(PRESENT_TEXT2, frame + 300);
+	SetPresentWait(PRESENT_TEXT2, frame + 100);
 }
 
 #if NeedFunctionPrototypes
@@ -331,7 +331,7 @@
 	RenderShape(display, window, kibell, kibellM,
 		x, y, 260, 40, True);
 
-	SetPresentWait(PRESENT_TEXT3, frame + 500);
+	SetPresentWait(PRESENT_TEXT3, frame + 200);
 }
 
 #if NeedFunctionPrototypes
@@ -355,7 +355,7 @@
 	RenderShape(display, window, presents, presentsM,
 		x, y, 410, 44, True);
 
-	SetPresentWait(PRESENT_TEXT_CLEAR, frame + 750);
+	SetPresentWait(PRESENT_TEXT_CLEAR, frame + 250);
 }
 
 #if NeedFunctionPrototypes
@@ -375,7 +375,7 @@
 
 	FadeAwayArea(display, window, x, y, 410, 44);
 
-	SetPresentWait(PRESENT_LETTERS, frame + 10);
+	SetPresentWait(PRESENT_LETTERS, frame + 5);
 }
 
 /* The distances for the gap inbetwen blocks */
@@ -404,7 +404,7 @@
 		DrawLetter(display, window, i, x, y);
 		x += 10 + dists[i];
 
-		SetPresentWait(PRESENT_LETTERS, frame + 300);
+		SetPresentWait(PRESENT_LETTERS, frame + 100);
 	}
 	else
 	{
@@ -416,7 +416,7 @@
 		x += dists[3];
 		DrawLetter(display, window, 3, x, y);
 
-		SetPresentWait(PRESENT_SHINE, frame + 200);
+		SetPresentWait(PRESENT_SHINE, frame + 100);
 	}
 
 	i++;
@@ -463,7 +463,7 @@
         if (in == 11)
         {
             XCopyArea(display, store, window, gc, 0, 0, 20, 20, x, y);
-			SetPresentWait(PRESENT_SPECIAL_TEXT1, frame + 500);
+			SetPresentWait(PRESENT_SPECIAL_TEXT1, frame + 100);
         }
     }
 }
@@ -499,7 +499,7 @@
 		len = strlen(wisdom);
 		x = ((PLAY_WIDTH + MAIN_WIDTH) / 2) - 
 			(XTextWidth(dataFont, wisdom, len) / 2);
-		nextFrame = frame + 10;
+		nextFrame = frame + 5;
 		first = False;
 	}
 
@@ -508,11 +508,11 @@
 		if (noSound == False) playSoundFile("key", 60);
 		DrawText(display, window, x, y, dataFont, red, wisdom, i);
 
-		nextFrame = frame + 30;
+		nextFrame = frame + 15;
 
 		i++;
 		if (i > len)
-			SetPresentWait(PRESENT_SPECIAL_TEXT2, frame + 700);
+			SetPresentWait(PRESENT_SPECIAL_TEXT2, frame + 150);
 	}
 }
 
@@ -542,7 +542,7 @@
 		len = strlen(wisdom2);
 		x = ((PLAY_WIDTH + MAIN_WIDTH) / 2) - 
 			(XTextWidth(dataFont, wisdom2, len) / 2);
-		nextFrame = frame + 10;
+		nextFrame = frame + 5;
 		first = False;
 	}
 
@@ -551,11 +551,11 @@
 		if (noSound == False) playSoundFile("key", 60);
 		DrawText(display, window, x, y, dataFont, red, wisdom2, i);
 
-		nextFrame = frame + 30;
+		nextFrame = frame + 15;
 
 		i++;
 		if (i > len)
-			SetPresentWait(PRESENT_SPECIAL_TEXT3, frame + 700);
+			SetPresentWait(PRESENT_SPECIAL_TEXT3, frame + 150);
 	}
 }
 
@@ -584,7 +584,7 @@
 		len = strlen(wisdom3);
 		x = ((PLAY_WIDTH + MAIN_WIDTH) / 2) - 
 			(XTextWidth(dataFont, wisdom3, len) / 2);
-		nextFrame = frame + 10;
+		nextFrame = frame + 5;
 		first = False;
 	}
 
@@ -593,11 +593,11 @@
 		if (noSound == False) playSoundFile("key", 60);
 		DrawText(display, window, x, y, dataFont, red, wisdom3, i);
 
-		nextFrame = frame + 30;
+		nextFrame = frame + 15;
 
 		i++;
 		if (i > len)
-			SetPresentWait(PRESENT_CLEAR, frame + 800);
+			SetPresentWait(PRESENT_CLEAR, frame + 200);
 	}
 }
 
@@ -642,7 +642,7 @@
 		yb -= 10;
 
 		if (yt > ((PLAY_HEIGHT + MAIN_HEIGHT) / 2))
-			SetPresentWait(PRESENT_FINISH, frame + 20);
+			SetPresentWait(PRESENT_FINISH, frame + 10);
 
 		nextFrame = frame + 20;
 	}
