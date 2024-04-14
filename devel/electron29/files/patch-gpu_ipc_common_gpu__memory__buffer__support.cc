--- gpu/ipc/common/gpu_memory_buffer_support.cc.orig	2023-08-10 01:48:45 UTC
+++ gpu/ipc/common/gpu_memory_buffer_support.cc
@@ -26,7 +26,7 @@
 #include "ui/ozone/public/ozone_platform.h"
 #endif
 
-#if BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "gpu/ipc/common/gpu_memory_buffer_impl_native_pixmap.h"
 #endif
 
@@ -56,7 +56,7 @@ GpuMemoryBufferSupport::GetNativeGpuMemoryBufferType()
   return gfx::IO_SURFACE_BUFFER;
 #elif BUILDFLAG(IS_ANDROID)
   return gfx::ANDROID_HARDWARE_BUFFER;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
   return gfx::NATIVE_PIXMAP;
 #elif BUILDFLAG(IS_WIN)
   return gfx::DXGI_SHARED_HANDLE;
