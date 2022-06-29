--- ui/gfx/gpu_memory_buffer.h.orig	2022-05-19 03:47:20 UTC
+++ ui/gfx/gpu_memory_buffer.h
@@ -16,7 +16,7 @@
 #include "ui/gfx/gfx_export.h"
 #include "ui/gfx/hdr_metadata.h"
 
-#if defined(USE_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if defined(USE_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #elif BUILDFLAG(IS_MAC)
 #include "ui/gfx/mac/io_surface.h"
@@ -78,7 +78,7 @@ struct GFX_EXPORT GpuMemoryBufferHandle {
   base::UnsafeSharedMemoryRegion region;
   uint32_t offset = 0;
   int32_t stride = 0;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   NativePixmapHandle native_pixmap_handle;
 #elif BUILDFLAG(IS_MAC)
   ScopedIOSurface io_surface;
