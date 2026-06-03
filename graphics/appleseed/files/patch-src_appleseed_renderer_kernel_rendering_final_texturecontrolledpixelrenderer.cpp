--- src/appleseed/renderer/kernel/rendering/final/texturecontrolledpixelrenderer.cpp.orig	2019-08-31 15:49:01 UTC
+++ src/appleseed/renderer/kernel/rendering/final/texturecontrolledpixelrenderer.cpp
@@ -61,6 +61,7 @@
 // OpenImageIO headers.
 #include "foundation/platform/_beginoiioheaders.h"
 #include "OpenImageIO/imagebufalgo.h"
+#include "OpenImageIO/imagecache.h"
 #include "OpenImageIO/typedesc.h"
 #include "foundation/platform/_endoiioheaders.h"
 
@@ -321,7 +322,7 @@ bool TextureControlledPixelRendererFactory::load_textu
 {
     // Create a new dedicated ImageCache instead of using the global ImageCache.
     // This is to prevent errors during ImageBuf access if the file behind tex_path was overwritten on disk.
-    ImageCache* image_cache = ImageCache::create();
+    auto image_cache = ImageCache::create();
     std::unique_ptr<ImageBuf> texture(new ImageBuf(texture_path, 0, 0, image_cache));
 
     // Force the read to immediately do the entire disk I/O for the file.
