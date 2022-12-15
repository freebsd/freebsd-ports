--- gpu/ipc/service/gpu_memory_buffer_factory.cc.orig	2022-02-28 16:54:41 UTC
+++ gpu/ipc/service/gpu_memory_buffer_factory.cc
@@ -12,7 +12,7 @@
 #include "gpu/ipc/service/gpu_memory_buffer_factory_io_surface.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "gpu/ipc/service/gpu_memory_buffer_factory_native_pixmap.h"
 #endif
 
@@ -34,7 +34,7 @@ GpuMemoryBufferFactory::CreateNativeType(
   return std::make_unique<GpuMemoryBufferFactoryIOSurface>();
 #elif BUILDFLAG(IS_ANDROID)
   return std::make_unique<GpuMemoryBufferFactoryAndroidHardwareBuffer>();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return std::make_unique<GpuMemoryBufferFactoryNativePixmap>(
       vulkan_context_provider);
 #elif BUILDFLAG(IS_WIN)
