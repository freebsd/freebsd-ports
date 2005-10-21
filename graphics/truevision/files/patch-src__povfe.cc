--- src/povfe.cc.orig	Tue Oct  4 04:24:37 2005
+++ src/povfe.cc	Tue Oct 18 19:11:46 2005
@@ -36,6 +36,10 @@
 #include "include/scene.h"
 #include "include/tvio.h"
 
+#if defined(__FreeBSD__)
+  #define O_SYNC O_FSYNC
+#endif
+
 // Output file format definitions
 const int file_type_num = 4;
 const char *file_type_list[file_type_num] = { "PNG", "PPM", "TGA", "TGA+RLE" };
