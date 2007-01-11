--- src/getopt.c.orig	Thu Jan 11 21:34:50 2007
+++ src/getopt.c	Thu Jan 11 21:36:24 2007
@@ -31,7 +31,7 @@
 # include <config.h>
 #endif
 
-#if defined(WIN32) || defined(_WIN32)
+#if defined(WIN32) || defined(_WIN32) || defined(__FreeBSD__)
 #define HAVE_STRING_H 1
 #endif
 
