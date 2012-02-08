Index: backgammon/teachgammon/teach.c
@@ -94,18 +92,18 @@
 	signal (SIGINT,getout);
 	if (gtty (0,&tty) == -1)			/* get old tty mode */
 		errexit ("teachgammon(gtty)");
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
 	tflag = getcaps (getenv ("TERM"));
 	getarg (argc, argv);
 	if (tflag)  {
-		noech &= ~(CRMOD|XTABS);
-		raw &= ~(CRMOD|XTABS);
+		noech &= ~(ICRNL|OXTABS);
+		raw &= ~(ICRNL|OXTABS);
 		clear();
 	}
 	text (hello);
