$FreeBSD$

--- driver.c.orig	Sat Oct 25 23:20:56 2003
+++ driver.c	Sat Oct 25 23:21:54 2003
@@ -9,6 +9,7 @@
 # include	<errno.h>
 # include	<sys/ioctl.h>
 # include	<sys/time.h>
+# include	<err.h>
 
 # ifndef pdp11
 # define	RN	(((Seed = Seed * 11109 + 13849) >> 16) & 0xffff)
@@ -653,7 +654,7 @@
 					if (np->p_flying < 0)
 						break;
 				if (np >= &Boot[NBOOTS])
-					abort(1, "Too many boots");
+					errx(1, "Too many boots");
 				np->p_undershot = FALSE;
 				np->p_x = pp->p_x;
 				np->p_y = pp->p_y;
