Index: backgammon/common_source/subs.c
@@ -420,7 +418,7 @@
 	if (tflag)
 		newpos();
 	buflush();
-	tty.sg_flags = mode;
+	tty.c_lflag = mode;
 	if (stty (0,&tty) < 0)
 		errexit("fixtty");
 }
