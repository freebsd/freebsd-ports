--- bsl.c.orig	Mon Nov  8 22:40:57 2010
+++ bsl.c	Thu Dec  2 13:05:14 2010
@@ -31,7 +31,7 @@
 #include "output.h"
 #include "fet_error.h"
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #define B460800 460800
 #endif
 
