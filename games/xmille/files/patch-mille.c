--- mille.c.orig	Thu Mar 28 14:29:31 1996
+++ mille.c	Fri Jun 15 02:27:49 2007
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
