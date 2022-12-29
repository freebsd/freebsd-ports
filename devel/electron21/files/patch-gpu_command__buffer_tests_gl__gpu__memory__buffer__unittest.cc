--- gpu/command_buffer/tests/gl_gpu_memory_buffer_unittest.cc.orig	2022-08-31 12:19:35 UTC
+++ gpu/command_buffer/tests/gl_gpu_memory_buffer_unittest.cc
@@ -28,7 +28,7 @@
 #include "ui/gl/gl_image.h"
 #include "ui/gl/test/gl_image_test_support.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "gpu/ipc/common/gpu_memory_buffer_impl_native_pixmap.h"
 #include "ui/gfx/linux/client_native_pixmap_factory_dmabuf.h"
 #endif
@@ -71,7 +71,7 @@ class GpuMemoryBufferTest : public testing::TestWithPa
   GLManager gl_;
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 class GpuMemoryBufferTestEGL : public testing::Test,
                                public gpu::GpuCommandBufferTestEGL {
  public:
