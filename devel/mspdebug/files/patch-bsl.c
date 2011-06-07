--- bsl.c.orig	2011-04-05 06:22:54.000000000 +1000
+++ bsl.c	2011-06-04 06:02:31.326405250 +1000
@@ -31,7 +31,7 @@
 #include "output.h"
 #include "fet_error.h"
 
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #define B460800 460800
 #endif
 
