--- ./src/help/data2c.cpp.orig	2010-10-09 07:48:30.000000000 -0400
+++ ./src/help/data2c.cpp	2010-11-11 20:19:35.000000000 -0500
@@ -48,6 +48,9 @@
     fprintf(out, "\\x%02x", c);
 }
 
+#if defined(__FreeBSD__)
+#include <libgen.h>
+#else
 #if defined(WIN32) || defined(__APPLE__)
 const char * basename(const char * n) {
 
@@ -62,6 +65,7 @@
   return n;
 }
 #endif
+#endif
 
 
 /* first param: output file name
