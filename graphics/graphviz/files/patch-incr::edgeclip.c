--- incr/edgeclip.c.orig	Fri Nov 10 04:23:25 2000
+++ incr/edgeclip.c	Wed Nov  7 17:48:55 2001
@@ -1,5 +1,5 @@
-#include <engine.h>
 #include <math.h>
+#include <engine.h>
 #define EPSILON	(.005)
 
 static int seg_size(ilcurve_t *curve)
