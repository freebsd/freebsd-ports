--- trek/main.c.orig	Mon Jun 24 04:29:52 2002
+++ trek/main.c	Sun Apr 16 21:26:44 2006
@@ -51,6 +51,8 @@
 # include	<setjmp.h>
 # include       <stdlib.h>
 
+#define gtty(_a,_b) ioctl(_a,TIOCGETP,_b)
+
 # define	PRIO		00	/* default priority */
 
 int	Mother	= 51 + (51 << 8);
