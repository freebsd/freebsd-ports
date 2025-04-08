--- ui/gfx/native_pixmap_handle.cc.orig	2022-11-30 08:12:58 UTC
+++ ui/gfx/native_pixmap_handle.cc
@@ -11,7 +11,7 @@
 #include "ui/gfx/buffer_format_util.h"
 #include "ui/gfx/geometry/size.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <drm_fourcc.h>
 #include <unistd.h>
 
@@ -23,9 +23,13 @@
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
@@ -36,7 +40,7 @@ NativePixmapPlane::NativePixmapPlane() : stride(0), of
 NativePixmapPlane::NativePixmapPlane(int stride,
                                      int offset,
                                      uint64_t size
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                                      ,
                                      base::ScopedFD fd
 #elif BUILDFLAG(IS_FUCHSIA)
@@ -47,7 +51,7 @@ NativePixmapPlane::NativePixmapPlane(int stride,
     : stride(stride),
       offset(offset),
       size(size)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       ,
       fd(std::move(fd))
 #elif BUILDFLAG(IS_FUCHSIA)
@@ -75,7 +79,7 @@ NativePixmapHandle& NativePixmapHandle::operator=(Nati
 NativePixmapHandle CloneHandleForIPC(const NativePixmapHandle& handle) {
   NativePixmapHandle clone;
   for (auto& plane : handle.planes) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     DCHECK(plane.fd.is_valid());
     // Combining the HANDLE_EINTR and ScopedFD's constructor causes the compiler
     // to emit some very strange assembly that tends to cause FD ownership
@@ -113,7 +117,7 @@ NativePixmapHandle CloneHandleForIPC(const NativePixma
 #endif
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   clone.modifier = handle.modifier;
   clone.supports_zero_copy_webgpu_import =
       handle.supports_zero_copy_webgpu_import;
