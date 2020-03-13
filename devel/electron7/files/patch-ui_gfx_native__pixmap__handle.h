--- ui/gfx/native_pixmap_handle.h.orig	2019-12-12 12:41:33 UTC
+++ ui/gfx/native_pixmap_handle.h
@@ -15,7 +15,7 @@
 #include "build/build_config.h"
 #include "ui/gfx/gfx_export.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/files/scoped_file.h"
 #endif
 
@@ -32,7 +32,7 @@ struct GFX_EXPORT NativePixmapPlane {
   NativePixmapPlane(int stride,
                     int offset,
                     uint64_t size
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
                     ,
                     base::ScopedFD fd
 #elif defined(OS_FUCHSIA)
@@ -53,7 +53,7 @@ struct GFX_EXPORT NativePixmapPlane {
   // This is necessary to map the buffers.
   uint64_t size;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // File descriptor for the underlying memory object (usually dmabuf).
   base::ScopedFD fd;
 #elif defined(OS_FUCHSIA)
@@ -82,7 +82,7 @@ struct GFX_EXPORT NativePixmapHandle {
 
   std::vector<NativePixmapPlane> planes;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // The modifier is retrieved from GBM library and passed to EGL driver.
   // Generally it's platform specific, and we don't need to modify it in
   // Chromium code. Also one per plane per entry.
