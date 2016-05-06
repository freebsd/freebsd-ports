--- src/tsp/src/tsplib.c.orig	2016-04-28 19:50:17 UTC
+++ src/tsp/src/tsplib.c
@@ -85,6 +85,7 @@ THE SOFTWARE.
 //#include <winsock2.h>
 //#endif
 #include <postgres.h>
+#include <stdlib.h>
 #include <string.h>    /* memcpy */
 #include <math.h>      /* exp    */
 
