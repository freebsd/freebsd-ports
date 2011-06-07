--- uif.c.orig	2011-04-05 06:22:54.000000000 +1000
+++ uif.c	2011-06-04 06:02:31.284404600 +1000
@@ -36,7 +36,7 @@
 #include "util.h"
 #include "output.h"
 
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #define B460800 460800
 #define B500000 500000
 #endif
