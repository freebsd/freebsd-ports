--- source/blender/imbuf/intern/oiio/openimageio_api.cpp.orig	2017-02-13 14:08:03 UTC
+++ source/blender/imbuf/intern/oiio/openimageio_api.cpp
@@ -35,6 +35,9 @@
 #include "utfconv.h"
 #endif
 
+#include <openimageio_api.h>
+#include <OpenImageIO/imageio.h>
+
 extern "C"
 {
 #include "MEM_guardedalloc.h"
@@ -48,8 +51,6 @@ extern "C"
 #include "IMB_colormanagement_intern.h"
 }
 
-#include <openimageio_api.h>
-#include <OpenImageIO/imageio.h>
 
 OIIO_NAMESPACE_USING
 
