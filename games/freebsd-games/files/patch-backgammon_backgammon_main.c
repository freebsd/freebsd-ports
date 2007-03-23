Index: backgammon/backgammon/main.c
@@ -113,13 +111,13 @@
 	signal (SIGINT,getout);				/* trap interrupts */
 	if (gtty (0,&tty) == -1)			/* get old tty mode */
 		errexit ("backgammon(gtty)");
-	old = tty.sg_flags;
+	old = tty.c_lflag;
 #ifdef V7
-	raw = ((noech = old & ~ECHO) | CBREAK);		/* set up modes */
+	raw = ((noech = old & ~ECHO) & ~ICANON);		/* set up modes */
 #else
 	raw = ((noech = old & ~ECHO) | RAW);		/* set up modes */
 #endif
-	ospeed = tty.sg_ospeed;				/* for termlib */
+	ospeed = cfgetospeed(&tty);				/* for termlib */
 
 							/* get terminal
 							 * capabilities, and
@@ -135,8 +133,8 @@
 	getarg (argc, argv);
 	args[acnt] = NULL;
 	if (tflag)  {					/* clear screen */
-		noech &= ~(CRMOD|XTABS);
-		raw &= ~(CRMOD|XTABS);
+		noech &= ~(ICRNL|OXTABS);
+		raw &= ~(ICRNL|OXTABS);
 		clear();
 	}
 	fixtty (raw);					/* go into raw mode */
