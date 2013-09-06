--- w_intersect.c.orig	2011-06-18 21:05:55.000000000 -0700
+++ w_intersect.c	2011-06-18 21:06:18.000000000 -0700
@@ -26,7 +26,9 @@
 #include "w_msgpanel.h"
 #include "f_util.h"
 #include "u_quartic.h"
+#ifndef __FreeBSD__
 #include <alloca.h>
+#endif
 #include <math.h>
 #undef I
   
