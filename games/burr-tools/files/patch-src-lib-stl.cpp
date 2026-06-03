--- src/lib/stl.cpp.orig	2013-05-08 19:02:06 UTC
+++ src/lib/stl.cpp
@@ -54,6 +54,8 @@ const char * basename(const char * name)
 
   return res;
 }
+#else
+#include <libgen.h>
 #endif
 
 
@@ -62,7 +64,7 @@ void stlExporter_c::write(const char * f
   FILE * f;
   unsigned long triangleCount = 0;
 
-  const char * title = basename(fname);
+  const char * title = basename(const_cast<char*>(fname));
 
   if (binaryMode)
   {
