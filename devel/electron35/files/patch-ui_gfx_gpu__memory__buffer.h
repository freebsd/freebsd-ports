--- ui/gfx/gpu_memory_buffer.h.orig	2025-03-24 20:50:14 UTC
+++ ui/gfx/gpu_memory_buffer.h
@@ -17,7 +17,7 @@
 #include "ui/gfx/generic_shared_memory_id.h"
 #include "ui/gfx/geometry/rect.h"
 
-#if BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #elif BUILDFLAG(IS_APPLE)
 #include "ui/gfx/mac/io_surface.h"
@@ -205,7 +205,7 @@ struct COMPONENT_EXPORT(GFX) GpuMemoryBufferHandle {
 
   uint32_t offset = 0;
   uint32_t stride = 0;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   NativePixmapHandle native_pixmap_handle;
 #elif BUILDFLAG(IS_APPLE)
   ScopedIOSurface io_surface;
