--- gpu/ipc/common/gpu_memory_buffer_support.cc.orig	2022-02-28 16:54:41 UTC
+++ gpu/ipc/common/gpu_memory_buffer_support.cc
@@ -21,7 +21,7 @@
 #include "ui/ozone/public/ozone_platform.h"
 #endif
 
-#if defined(USE_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if defined(USE_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "gpu/ipc/common/gpu_memory_buffer_impl_native_pixmap.h"
 #endif
 
@@ -50,7 +50,7 @@ GpuMemoryBufferSupport::GetNativeGpuMemoryBufferType()
   return gfx::IO_SURFACE_BUFFER;
 #elif BUILDFLAG(IS_ANDROID)
   return gfx::ANDROID_HARDWARE_BUFFER;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(USE_OZONE)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(USE_OZONE) || BUILDFLAG(IS_BSD)
   return gfx::NATIVE_PIXMAP;
 #elif BUILDFLAG(IS_WIN)
   return gfx::DXGI_SHARED_HANDLE;
