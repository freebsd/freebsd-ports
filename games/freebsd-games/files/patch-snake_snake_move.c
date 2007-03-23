Index: snake/snake/move.c
@@ -677,10 +674,10 @@
 
 	gtty(0, &orig);
 	new=orig;
-	new.sg_flags &= ~(ECHO|CRMOD|ALLDELAY|XTABS);
-	new.sg_flags |= CBREAK;
+	new.c_lflag &= ~(ECHO|ICRNL|OXTABS);
+	new.c_lflag &= ~ICANON;
 	signal(SIGINT,stop);
-	ospeed = orig.sg_ospeed;
+	ospeed = cfgetospeed(&orig);
 #ifdef TIOCGLTC
 	ioctl(0, TIOCGLTC, &olttyc);
 	nlttyc = olttyc;
@@ -689,7 +686,7 @@
 #endif
 	raw();
 
-	if ((orig.sg_flags & XTABS) == XTABS) TA=0;
+	if ((orig.c_lflag & OXTABS) == OXTABS) TA=0;
 	putpad(KS);
 	putpad(TI);
 	point(&cursor,0,LINES-1);
