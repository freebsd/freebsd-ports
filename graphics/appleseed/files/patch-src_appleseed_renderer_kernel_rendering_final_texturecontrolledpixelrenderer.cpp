--- src/appleseed/renderer/kernel/rendering/final/texturecontrolledpixelrenderer.cpp.orig	2019-08-31 15:49:01 UTC
+++ src/appleseed/renderer/kernel/rendering/final/texturecontrolledpixelrenderer.cpp
@@ -61,6 +61,7 @@
 // OpenImageIO headers.
 #include "foundation/platform/_beginoiioheaders.h"
 #include "OpenImageIO/imagebufalgo.h"
+#include "OpenImageIO/imagecache.h"
 #include "OpenImageIO/typedesc.h"
 #include "foundation/platform/_endoiioheaders.h"
 
