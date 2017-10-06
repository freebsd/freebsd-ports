--- utests/image_planar_yuv.cpp.orig	2017-06-23 08:05:54 UTC
+++ utests/image_planar_yuv.cpp
@@ -1,6 +1,6 @@
 #include <string.h>
 #include "utest_helper.hpp"
-#include <malloc.h>
+#include <cstdlib>
 #include <cstring>
 
 static void image_planar_yuv(void)
@@ -28,10 +28,9 @@ static void image_planar_yuv(void)
   uint8_t* src_data;
   uint8_t* yplane_data;
   uint8_t* uvplane_data;
-  src_data = (uint8_t*)memalign(base_address_alignment, buffer_sz);
-  yplane_data = (uint8_t*)memalign(base_address_alignment, yplane_sz);
-  uvplane_data = (uint8_t*)memalign(base_address_alignment, uvplane_sz);
-  if (!src_data || !yplane_data || !uvplane_data) {
+  if (posix_memalign((void **)&src_data, base_address_alignment, buffer_sz) ||
+      posix_memalign((void **)&yplane_data, base_address_alignment, yplane_sz) ||
+      posix_memalign((void **)&uvplane_data, base_address_alignment, uvplane_sz)) {
     fprintf(stderr, "run out of memory\n");
     return;
   }
