--- media/gpu/buffer_validation.cc.orig	2023-05-25 00:41:58 UTC
+++ media/gpu/buffer_validation.cc
@@ -15,7 +15,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <sys/types.h>
 #include <unistd.h>
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -23,7 +23,7 @@
 namespace media {
 
 bool GetFileSize(const int fd, size_t* size) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (fd < 0) {
     VLOG(1) << "Invalid file descriptor";
     return false;
@@ -76,7 +76,7 @@ bool VerifyGpuMemoryBufferHandle(
     VLOG(1) << "Unsupported: " << pixel_format;
     return false;
   }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   const size_t num_planes = media::VideoFrame::NumPlanes(pixel_format);
   if (num_planes != gmb_handle.native_pixmap_handle.planes.size() ||
       num_planes == 0) {
