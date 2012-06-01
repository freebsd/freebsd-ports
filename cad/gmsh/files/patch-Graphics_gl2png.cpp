--- Graphics/gl2png.cpp.orig	2010-10-15 15:35:00.000000000 +0200
+++ Graphics/gl2png.cpp	2012-05-09 13:23:42.000000000 +0200
@@ -16,6 +16,7 @@
 #else
 
 #include <png.h>
+#include <zlib.h>
 
 #ifndef png_jmpbuf
 #  define png_jmpbuf(png_ptr) ((png_ptr)->jmpbuf)
