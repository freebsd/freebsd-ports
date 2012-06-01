--- src/celestia/imagecapture.cpp.orig	2011-06-05 18:11:13.000000000 +0200
+++ src/celestia/imagecapture.cpp	2012-04-25 05:50:24.000000000 +0200
@@ -29,6 +29,7 @@
 #include "../celestia/Celestia.app.skel/Contents/Frameworks/Headers/png.h"
 #else
 #include "png.h"
+#include "zlib.h"
 #endif
 
 // Define png_jmpbuf() in case we are using a pre-1.0.6 version of libpng
