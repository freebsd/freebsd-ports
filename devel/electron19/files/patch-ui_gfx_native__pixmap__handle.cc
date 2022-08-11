--- ui/gfx/native_pixmap_handle.cc.orig	2022-05-25 04:01:58 UTC
+++ ui/gfx/native_pixmap_handle.cc
@@ -9,7 +9,7 @@
 #include "base/logging.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <drm_fourcc.h>
 #include <unistd.h>
 
@@ -21,9 +21,13 @@
 #include "base/fuchsia/fuchsia_logging.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include <unistd.h>
+#endif
+
 namespace gfx {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 static_assert(NativePixmapHandle::kNoModifier == DRM_FORMAT_MOD_INVALID,
               "gfx::NativePixmapHandle::kNoModifier should be an alias for"
               "DRM_FORMAT_MOD_INVALID");
@@ -34,7 +38,7 @@ NativePixmapPlane::NativePixmapPlane() : stride(0), of
 NativePixmapPlane::NativePixmapPlane(int stride,
                                      int offset,
                                      uint64_t size
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                                      ,
                                      base::ScopedFD fd
 #elif BUILDFLAG(IS_FUCHSIA)
@@ -45,7 +49,7 @@ NativePixmapPlane::NativePixmapPlane(int stride,
     : stride(stride),
       offset(offset),
       size(size)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       ,
       fd(std::move(fd))
 #elif BUILDFLAG(IS_FUCHSIA)
@@ -73,7 +77,7 @@ NativePixmapHandle& NativePixmapHandle::operator=(Nati
 NativePixmapHandle CloneHandleForIPC(const NativePixmapHandle& handle) {
   NativePixmapHandle clone;
   for (auto& plane : handle.planes) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     DCHECK(plane.fd.is_valid());
     // Combining the HANDLE_EINTR and ScopedFD's constructor causes the compiler
     // to emit some very strange assembly that tends to cause FD ownership
@@ -103,7 +107,7 @@ NativePixmapHandle CloneHandleForIPC(const NativePixma
 #endif
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   clone.modifier = handle.modifier;
   clone.supports_zero_copy_webgpu_import =
       handle.supports_zero_copy_webgpu_import;
