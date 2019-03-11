--- colorbars/colorbars.c.orig	2018-11-23 03:38:50 UTC
+++ colorbars/colorbars.c
@@ -33,6 +33,10 @@
 
 #include <sys/param.h>
 
+#ifndef NELEM
+#define NELEM(n) (sizeof(n)/sizeof((n)[0]))
+#endif
+
 int
 main(void)
 {
