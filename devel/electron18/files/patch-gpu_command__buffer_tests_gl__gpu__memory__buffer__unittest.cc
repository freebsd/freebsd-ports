--- gpu/command_buffer/tests/gl_gpu_memory_buffer_unittest.cc.orig	2022-05-19 05:17:43 UTC
+++ gpu/command_buffer/tests/gl_gpu_memory_buffer_unittest.cc
@@ -29,7 +29,7 @@
 #include "ui/gl/gl_image.h"
 #include "ui/gl/test/gl_image_test_support.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "gpu/ipc/common/gpu_memory_buffer_impl_native_pixmap.h"
 #include "ui/gfx/linux/client_native_pixmap_factory_dmabuf.h"
 #endif
@@ -72,7 +72,7 @@ class GpuMemoryBufferTest : public testing::TestWithPa
   GLManager gl_;
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 class GpuMemoryBufferTestEGL : public testing::Test,
                                public gpu::GpuCommandBufferTestEGL {
  public:
@@ -364,7 +364,7 @@ TEST_P(GpuMemoryBufferTest, Lifecycle) {
   glDeleteTextures(1, &texture_id);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Test glCreateImageCHROMIUM with gfx::NATIVE_PIXMAP. Basically the test
 // reproduces the situation where some dmabuf fds are available outside the
 // gpu process and the user wants to import them using glCreateImageCHROMIUM.
