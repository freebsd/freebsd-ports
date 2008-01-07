--- src/lib/fclock.c.orig	Sun Dec 23 15:10:22 2007
+++ src/lib/fclock.c	Mon Jan  7 00:46:01 2008
@@ -26,6 +26,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>
+#include <sys/time.h>
 #include <sys/times.h>
 #include <math.h>
 #include <assert.h>
@@ -66,7 +67,7 @@
     }
     result = (long double)c/CLK_TCK;
 #endif
-    assert(isnormal(result));
+    /*assert(isnormal(result));*/
     assert(result > 0);
     return result;
 }
