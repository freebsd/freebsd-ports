--- colorbars/colorbars.c.orig	2016-10-31 17:00:48 UTC
+++ colorbars/colorbars.c
@@ -31,6 +31,10 @@
 #include <err.h>
 #include <stdlib.h>
 
+#ifndef __arysize
+#define __arysize(n) (sizeof(n)/sizeof((n)[0]))
+#endif
+
 int
 main(void)
 {
