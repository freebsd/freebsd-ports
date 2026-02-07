--- src/util.c	2014-03-27 20:00:17.000000000 -0300
+++ src/util.c	2014-03-27 20:00:58.000000000 -0300
@@ -18,6 +18,7 @@
  * Version $Id: util.c,v 1.1.1.1 2003/01/30 21:30:19 ernstl Exp $
  */
 
+#include <stdio.h>
 #include "util.h"
 #include <string.h>
 #include <math.h>
@@ -30,14 +31,38 @@
 gint
 floorm (gint a, gint b)
  /* return largest multiple of b that is <= a */
+ /*
+  & & m = floorm(a,b)
+    & a = b*m + r
+    &  0 <= r < b
+  */
 {
+#ifdef RLXTEST
+  printf("floorm: a/b %d, fl %g\n", a/b, floor ((gdouble) a / b));
+#endif
   return (b * floor ((gdouble) a / b));
 }
 
 gint
 ceilm (gint a, gint b)
  /* return least multiple of b that is >= a */
+ /*
+    & m = ceilm(a,b)
+    & a = b*m - r;
+    & m = a/b
+    % r = a%b
+    & -a = -b*m + r
+
+    & ceilm = (r == 0 ? b*m : (b+1)*m)
+  */
 {
+#ifdef RLXTEST
+  printf("ceil: a %d, b %d, -(-a/b) %d,a/b+(a%b != 0 ? 1:0) %d,  fl %g\n",
+         a,b,
+         -((-a)/b),
+          a/b+(a%b != 0 ? 1:0),
+         ceil ((gdouble) a / b) );
+#endif
   return (b * ceil ((gdouble) a / b));
 }
 
