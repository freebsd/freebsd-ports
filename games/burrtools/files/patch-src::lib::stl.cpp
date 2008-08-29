--- src/lib/stl.cpp.orig	2008-08-30 00:13:04.000000000 +0800
+++ src/lib/stl.cpp	2008-08-30 00:14:23.000000000 +0800
@@ -21,6 +21,9 @@
 #include <math.h>
 #include <string.h>
 
+#if defined(__FreeBSD__)
+#include <libgen.h>
+#else
 #if defined(WIN32) || defined(__APPLE__)
 const char * basename(const char * name) {
   const char * res1 = strchr(name, '/');
@@ -36,6 +39,7 @@
   return res;
 }
 #endif
+#endif
 
 void stlExporter_c::open(const char * name) {
 
