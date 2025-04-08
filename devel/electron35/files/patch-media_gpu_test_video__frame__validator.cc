--- media/gpu/test/video_frame_validator.cc.orig	2024-10-16 21:31:33 UTC
+++ media/gpu/test/video_frame_validator.cc
@@ -33,7 +33,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/mman.h>
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 
