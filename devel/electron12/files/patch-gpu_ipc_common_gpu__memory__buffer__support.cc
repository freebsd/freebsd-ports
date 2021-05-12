--- gpu/ipc/common/gpu_memory_buffer_support.cc.orig	2021-04-14 01:08:50 UTC
+++ gpu/ipc/common/gpu_memory_buffer_support.cc
@@ -16,7 +16,7 @@
 #include "gpu/ipc/common/gpu_memory_buffer_impl_io_surface.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/gfx/client_native_pixmap_factory.h"
 #include "ui/gfx/linux/client_native_pixmap_factory_dmabuf.h"
 #endif
@@ -26,7 +26,7 @@
 #include "ui/ozone/public/ozone_platform.h"
 #endif
 
-#if defined(USE_OZONE) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(USE_OZONE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "gpu/ipc/common/gpu_memory_buffer_impl_native_pixmap.h"
 #endif
 
@@ -52,7 +52,7 @@ GpuMemoryBufferSupport::GpuMemoryBufferSupport() {
     return;
   }
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   client_native_pixmap_factory_.reset(
       gfx::CreateClientNativePixmapFactoryDmabuf());
 #endif
@@ -66,7 +66,7 @@ GpuMemoryBufferSupport::GetNativeGpuMemoryBufferType()
   return gfx::IO_SURFACE_BUFFER;
 #elif defined(OS_ANDROID)
   return gfx::ANDROID_HARDWARE_BUFFER;
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(USE_OZONE)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || defined(USE_OZONE)
   return gfx::NATIVE_PIXMAP;
 #elif defined(OS_WIN)
   return gfx::DXGI_SHARED_HANDLE;
@@ -201,7 +201,7 @@ GpuMemoryBufferSupport::CreateGpuMemoryBufferImplFromH
       return GpuMemoryBufferImplIOSurface::CreateFromHandle(
           std::move(handle), size, format, usage, std::move(callback));
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(USE_OZONE)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || defined(USE_OZONE)
     case gfx::NATIVE_PIXMAP:
       return GpuMemoryBufferImplNativePixmap::CreateFromHandle(
           client_native_pixmap_factory(), std::move(handle), size, format,
