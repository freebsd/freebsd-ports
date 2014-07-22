diff -Naur battlestar.orig/fly.c battlestar/fly.c
--- battlestar.orig/fly.c	2012-03-22 13:59:00.000000000 +0100
+++ battlestar/fly.c	2012-03-22 13:59:09.000000000 +0100
@@ -286,6 +286,7 @@
 	signal(SIGALRM, SIG_DFL);
 	mvcur(0,COLS-1,LINES-1,0);
 	endwin();
+	setlinebuf(stdout);
 	signal(SIGTSTP, SIG_DFL);
 	signal(SIGINT, oldsig);
 }
