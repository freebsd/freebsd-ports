--- mandelbulber2/src/radiance_hdr.cpp.orig	2020-09-28 17:07:46 UTC
+++ mandelbulber2/src/radiance_hdr.cpp
@@ -40,7 +40,7 @@
 // custom includes
 #define STB_IMAGE_IMPLEMENTATION
 #define STBI_ONLY_HDR
-#include "third-party/stb/stb_image.h"
+#include <stb/stb_image.h>
 
 cRadianceHDR::cRadianceHDR()
 {
