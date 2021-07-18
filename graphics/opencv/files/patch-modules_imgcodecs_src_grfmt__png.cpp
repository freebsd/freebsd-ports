--- modules/imgcodecs/src/grfmt_png.cpp.orig	2021-07-18 11:13:32 UTC
+++ modules/imgcodecs/src/grfmt_png.cpp
@@ -59,7 +59,7 @@
 #endif
 
 #ifdef HAVE_LIBPNG_PNG_H
-#include <libpng/png.h>
+#include <libpng16/png.h>
 #else
 #include <png.h>
 #endif
