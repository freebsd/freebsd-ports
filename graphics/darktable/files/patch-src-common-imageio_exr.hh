--- src/common/imageio_exr.hh.orig
+++ src/common/imageio_exr.hh
@@ -21,7 +21,11 @@
 #include "common/image.h"
 #include "common/mipmap_cache.h"
 
+#if __cplusplus >= 201103L || defined(__clang__)
+#include <memory>
+#else
 #include <tr1/memory>
+#endif
 
 #include <OpenEXR/ImfFrameBuffer.h>
 #include <OpenEXR/ImfTestFile.h>
@@ -56,7 +60,11 @@ public:
   }
 
   uint32_t size;
+#if __cplusplus >= 201103L || defined(__clang__)
+  std::shared_ptr<uint8_t> data;
+#else
   std::tr1::shared_ptr<uint8_t> data;
+#endif
 };
