diff -u circum.c.orig circum.c
--- circum.c.orig	Sat Mar 14 23:21:56 1992
+++ circum.c	Sun Jan 21 20:33:31 2007
@@ -8,6 +8,8 @@
 #include "circum.h"
 #include "screen.h"	/* just for SUN and MOON */
 
+static about_now (Now *n1, Now *n2, double dt);
+
 /* find body p's circumstances now.
  * to save some time the caller may specify a desired accuracy, in arc seconds.
  * if, based on its mean motion, it would not have moved this much since the
