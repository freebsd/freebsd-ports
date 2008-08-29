--- src/help/data2c.cpp.orig	2008-08-30 00:15:50.000000000 +0800
+++ src/help/data2c.cpp	2008-08-30 00:16:22.000000000 +0800
@@ -44,6 +44,9 @@
     fprintf(out, "\\x%02x", c);
 }
 
+#if defined(__FreeBSD__)
+#include <libgen.h>
+#else
 #if defined(WIN32) || defined(__APPLE__)
 const char * basename(const char * n) {
 
@@ -58,6 +61,7 @@
   return n;
 }
 #endif
+#endif
 
 
 /* first param: output file name
