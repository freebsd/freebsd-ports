--- gpu/command_buffer/client/test_shared_image_interface.cc.orig	2025-08-26 20:49:50 UTC
+++ gpu/command_buffer/client/test_shared_image_interface.cc
@@ -30,7 +30,7 @@
 #include "ui/gfx/gpu_fence.h"
 #include "ui/gfx/gpu_memory_buffer_handle.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <fcntl.h>
 #endif
 
@@ -154,7 +154,7 @@ TestSharedImageInterface::~TestSharedImageInterface() 
 TestSharedImageInterface::~TestSharedImageInterface() = default;
 
 // static
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 gfx::GpuMemoryBufferHandle TestSharedImageInterface::CreatePixmapHandle(
     const gfx::Size& size,
     gfx::BufferFormat format) {
