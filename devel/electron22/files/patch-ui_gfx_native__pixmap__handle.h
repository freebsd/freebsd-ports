--- ui/gfx/native_pixmap_handle.h.orig	2022-11-30 08:12:58 UTC
+++ ui/gfx/native_pixmap_handle.h
@@ -16,7 +16,7 @@
 #include "ui/gfx/buffer_types.h"
 #include "ui/gfx/gfx_export.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/scoped_file.h"
 #endif
 
@@ -35,7 +35,7 @@ struct GFX_EXPORT NativePixmapPlane {
   NativePixmapPlane(int stride,
                     int offset,
                     uint64_t size
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                     ,
                     base::ScopedFD fd
 #elif BUILDFLAG(IS_FUCHSIA)
@@ -56,7 +56,7 @@ struct GFX_EXPORT NativePixmapPlane {
   // This is necessary to map the buffers.
   uint64_t size;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // File descriptor for the underlying memory object (usually dmabuf).
   base::ScopedFD fd;
 #elif BUILDFLAG(IS_FUCHSIA)
@@ -85,7 +85,7 @@ struct GFX_EXPORT NativePixmapHandle {
 
   std::vector<NativePixmapPlane> planes;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The modifier is retrieved from GBM library and passed to EGL driver.
   // Generally it's platform specific, and we don't need to modify it in
   // Chromium code. Also one per plane per entry.
