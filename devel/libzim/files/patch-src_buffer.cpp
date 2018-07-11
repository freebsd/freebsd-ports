--- src/buffer.cpp.orig	2018-07-11 01:24:59.809896000 +0000
+++ src/buffer.cpp	2018-07-11 01:25:29.007975000 +0000
@@ -48,7 +48,7 @@ MMapBuffer::MMapBuffer(int fd, offset_t offset, zsize_
 #if defined(__APPLE__)
   #define MAP_FLAGS MAP_PRIVATE
 #else
-  #define MAP_FLAGS MAP_PRIVATE|MAP_POPULATE
+  #define MAP_FLAGS MAP_PRIVATE|MAP_PREFAULT_READ
 #endif
   _data = (char*)mmap(NULL, size.v + _offset.v, PROT_READ, MAP_FLAGS, fd, pa_offset.v);
   if (_data == MAP_FAILED )
