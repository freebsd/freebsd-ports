--- gpu/command_buffer/tests/gl_gpu_memory_buffer_unittest.cc.orig	2025-06-30 07:04:30 UTC
+++ gpu/command_buffer/tests/gl_gpu_memory_buffer_unittest.cc
@@ -29,7 +29,7 @@
 #include "ui/gfx/half_float.h"
 #include "ui/gl/test/gl_test_support.h"
 
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
