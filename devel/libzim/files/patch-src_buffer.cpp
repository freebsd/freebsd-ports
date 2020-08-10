--- src/buffer.cpp.orig	2020-07-15 14:24:54 UTC
+++ src/buffer.cpp
@@ -48,6 +48,8 @@ MMapBuffer::MMapBuffer(int fd, offset_t offset, zsize_
   _offset = offset-pa_offset;
 #if defined(__APPLE__) || defined(__OpenBSD__)
   #define MAP_FLAGS MAP_PRIVATE
+#elif defined(__FreeBSD__)
+  #define MAP_FLAGS MAP_PRIVATE|MAP_PREFAULT_READ
 #else
   #define MAP_FLAGS MAP_PRIVATE|MAP_POPULATE
 #endif
