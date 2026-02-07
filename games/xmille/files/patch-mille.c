--- ./mille.c.orig	1996-03-28 06:29:31.000000000 +0100
+++ ./mille.c	2013-05-26 18:05:50.000000000 +0200
@@ -1,16 +1,17 @@
 # include	"mille.h"
 # include	<signal.h>
+# include	<stdlib.h>
 # ifdef attron
 #	include	<term.h>
-# endif	attron
+# endif	
 
 /*
  * @(#)mille.c	1.3 (Berkeley) 5/10/83
  */
 
-int	rub();
+void rub( int );
 
-/*char	_sobuf[BUFSIZ];*/
+char	_sobuf[BUFSIZ];
 
 main(ac, av)
 reg int		ac;
@@ -49,8 +50,6 @@
 		/* NOTREACHED */
 	}
 	setbuf(stdout, _sobuf);
-	Play = PLAYER;
-	init_ui ();
 # ifndef PROF
 #ifdef sun
 	srandom(getpid());
@@ -60,6 +59,8 @@
 # else
 	srand(0);
 # endif
+	Play = random()&01 ? COMP : PLAYER;
+	init_ui();
 	signal(SIGINT, rub);
 	for (;;) {
 		if (!restore || (Player[PLAYER].total >= 5000
@@ -73,7 +74,7 @@
 		}
 		do {
 			if (!restore)
-				Handstart = Play = other(Handstart);
+				Handstart = other(Handstart);
 			if (!restore || On_exit) {
 				shuffle();
 				init();
@@ -123,9 +124,9 @@
  *	Routine to trap rubouts, and make sure they really want to
  * quit.
  */
-rub() {
+void rub( int signum ) {
 
-	signal(SIGINT, 1);
+	signal(SIGINT, SIG_IGN);
 	if (getyn("Really? "))
 		die();
 	signal(SIGINT, rub);
@@ -136,7 +137,7 @@
  */
 die() {
 
-	signal(SIGINT, 1);
+	signal(SIGINT, SIG_IGN);
 	if (outf)
 		fflush(outf);
 	finish_ui ();
