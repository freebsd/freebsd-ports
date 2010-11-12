--- ./src/lib/stl.cpp.orig	2010-10-09 07:48:31.000000000 -0400
+++ ./src/lib/stl.cpp	2010-11-11 20:19:35.000000000 -0500
@@ -40,6 +40,9 @@
  * The concrete classes do the grid dependend stuff and add lots of triangles to the file
  */
 
+#if defined(__FreeBSD__)
+#include <libgen.h>
+#else
 #if defined(WIN32) || defined(__APPLE__)
 const char * basename(const char * name) {
   const char * res1 = strchr(name, '/');
@@ -55,6 +58,7 @@
   return res;
 }
 #endif
+#endif
 
 
 void stlExporter_c::write(const char * fname, const voxel_c & v, const faceList_c & holes)
