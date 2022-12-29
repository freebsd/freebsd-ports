--- ui/gfx/gpu_memory_buffer.h.orig	2022-09-24 10:57:32 UTC
+++ ui/gfx/gpu_memory_buffer.h
@@ -15,7 +15,7 @@
 #include "ui/gfx/geometry/rect.h"
 #include "ui/gfx/gfx_export.h"
 
-#if defined(USE_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if defined(USE_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #elif BUILDFLAG(IS_MAC)
 #include "ui/gfx/mac/io_surface.h"
@@ -75,7 +75,7 @@ struct GFX_EXPORT GpuMemoryBufferHandle {
   base::UnsafeSharedMemoryRegion region;
   uint32_t offset = 0;
   uint32_t stride = 0;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   NativePixmapHandle native_pixmap_handle;
 #elif BUILDFLAG(IS_MAC)
   ScopedIOSurface io_surface;
