--- w_snap.c.orig	Wed Sep 29 14:52:16 2004
+++ w_snap.c
@@ -29,7 +29,9 @@
 #include "w_util.h"
 #include "u_quartic.h"
 #include <math.h>
+#ifndef __FreeBSD__
 #include <alloca.h>
+#endif
 
 int snap_gx;
 int snap_gy;
@@ -878,7 +880,7 @@
   dt = (dx * (double)(a->point[0].y - y))
     -  (dy * (double)(a->point[0].x - x));
   
-  return (signbit(d1) == signbit(dt)) ? True : False;
+  return (signbit_(d1) == signbit_(dt)) ? True : False;
 }
 
 /*                                      */
