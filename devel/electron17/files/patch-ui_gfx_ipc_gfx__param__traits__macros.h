--- ui/gfx/ipc/gfx_param_traits_macros.h.orig	2021-04-14 01:09:39 UTC
+++ ui/gfx/ipc/gfx_param_traits_macros.h
@@ -18,7 +18,7 @@
 #include "ui/gfx/selection_bound.h"
 #include "ui/gfx/swap_result.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #endif
 
@@ -48,7 +48,7 @@ IPC_STRUCT_TRAITS_BEGIN(gfx::GpuMemoryBufferHandle)
   IPC_STRUCT_TRAITS_MEMBER(region)
   IPC_STRUCT_TRAITS_MEMBER(offset)
   IPC_STRUCT_TRAITS_MEMBER(stride)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
   IPC_STRUCT_TRAITS_MEMBER(native_pixmap_handle)
 #elif defined(OS_APPLE)
   IPC_STRUCT_TRAITS_MEMBER(io_surface)
@@ -63,12 +63,12 @@ IPC_STRUCT_TRAITS_BEGIN(gfx::GpuMemoryBufferId)
   IPC_STRUCT_TRAITS_MEMBER(id)
 IPC_STRUCT_TRAITS_END()
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 IPC_STRUCT_TRAITS_BEGIN(gfx::NativePixmapPlane)
   IPC_STRUCT_TRAITS_MEMBER(stride)
   IPC_STRUCT_TRAITS_MEMBER(offset)
   IPC_STRUCT_TRAITS_MEMBER(size)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   IPC_STRUCT_TRAITS_MEMBER(fd)
 #elif defined(OS_FUCHSIA)
   IPC_STRUCT_TRAITS_MEMBER(vmo)
@@ -77,7 +77,7 @@ IPC_STRUCT_TRAITS_END()
 
 IPC_STRUCT_TRAITS_BEGIN(gfx::NativePixmapHandle)
   IPC_STRUCT_TRAITS_MEMBER(planes)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   IPC_STRUCT_TRAITS_MEMBER(modifier)
 #endif
 #if defined(OS_FUCHSIA)
