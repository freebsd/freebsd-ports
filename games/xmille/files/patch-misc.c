--- misc.c.orig	Wed Jul  8 11:33:04 1987
+++ misc.c	Fri Jun 15 02:20:34 2007
@@ -2,7 +2,7 @@
 # ifdef	attron
 #	include	<term.h>
 #	define	_tty	cur_term->Nttyb
-# endif	attron
+# endif	
 
 /*
  * @(#)misc.c	1.3 (Berkeley) 7/2/83
