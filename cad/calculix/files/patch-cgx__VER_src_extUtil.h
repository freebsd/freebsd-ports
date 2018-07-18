--- cgx_2.14/src/extUtil.h.orig	2017-04-28 10:12:50 UTC
+++ cgx_2.14/src/extUtil.h
@@ -9,6 +9,7 @@
 #else
   #define DEV_NULL   " >/dev/null"
   #define DEV_NULL2 " 2>/dev/null"
+  #include <sys/param.h>
   #include <unistd.h>
 #endif
 
@@ -52,12 +53,10 @@ void printf_fflush(const char *fmt,...);
 /* from #include "f2c.h" */
 #define abs(x) ((x) >= 0 ? (x) : -(x))
 #define dabs(x) (double)abs(x)
-#define min(a,b) ((a) <= (b) ? (a) : (b))
-#define max(a,b) ((a) >= (b) ? (a) : (b))
-#define smin(a,b) (float)min(a,b)
-#define smax(a,b) (float)max(a,b)
-#define dmin(a,b) (double)min(a,b)
-#define dmax(a,b) (double)max(a,b)
+#define smin(a,b) (float)MIN(a,b)
+#define smax(a,b) (float)MAX(a,b)
+#define dmin(a,b) (double)MIN(a,b)
+#define dmax(a,b) (double)MAX(a,b)
 
 
 typedef struct {
