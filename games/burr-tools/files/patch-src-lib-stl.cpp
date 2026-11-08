--- src/lib/stl.cpp.orig	2026-10-09 20:40:12 UTC
+++ src/lib/stl.cpp
@@ -69,6 +69,8 @@ const char * basename(const char * name) {
 
   return res ? res + 1 : name;
 }
+#else
+#include <libgen.h>
 #endif
 
 
@@ -77,7 +79,7 @@ void stlExporter_c::write(const char * fname, const vo
   std::unique_ptr<FILE, int(*)(FILE*)> f(nullptr, &fclose);
   unsigned long triangleCount = 0;
 
-  const char * title = basename(fname);
+  const char * title = basename(const_cast<char*>(fname));
 
   if (binaryMode)
   {
