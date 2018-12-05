--- src/buffer.cpp.orig	2018-09-04 16:23:32 UTC
+++ src/buffer.cpp
@@ -49,7 +49,7 @@ MMapBuffer::MMapBuffer(int fd, offset_t offset, zsize_
 #if defined(__APPLE__)
   #define MAP_FLAGS MAP_PRIVATE
 #else
-  #define MAP_FLAGS MAP_PRIVATE|MAP_POPULATE
+  #define MAP_FLAGS MAP_PRIVATE|MAP_PREFAULT_READ
 #endif
 #if !MMAP_SUPPORT_64
   if(pa_offset.v >= INT32_MAX) {
