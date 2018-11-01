--- colorbars/colorbars.c.orig	2018-06-15 14:40:00 UTC
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
