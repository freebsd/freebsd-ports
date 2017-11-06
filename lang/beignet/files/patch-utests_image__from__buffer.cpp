--- utests/image_from_buffer.cpp.orig	2017-03-13 21:06:07 UTC
+++ utests/image_from_buffer.cpp
@@ -1,6 +1,6 @@
 #include <string.h>
 #include "utest_helper.hpp"
-#include <malloc.h>
+#include <cstdlib>
 #include <cstring>
 
 static void image_from_buffer(void)
@@ -33,8 +33,7 @@ static void image_from_buffer(void)
   // Setup kernel and images
   size_t buffer_sz = sizeof(uint32_t) * w * h;
   uint32_t* src_data;
-  src_data = (uint32_t*)memalign(base_address_alignment, buffer_sz);
-  if(!src_data) {
+  if(posix_memalign((void**)&src_data, base_address_alignment, buffer_sz)) {
     fprintf(stderr, "run out of memory\n");
     return;
   }
