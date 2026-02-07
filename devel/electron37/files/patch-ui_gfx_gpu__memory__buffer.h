--- ui/gfx/gpu_memory_buffer.h.orig	2025-06-30 07:04:30 UTC
+++ ui/gfx/gpu_memory_buffer.h
@@ -17,7 +17,7 @@
 #include "ui/gfx/generic_shared_memory_id.h"
 #include "ui/gfx/geometry/rect.h"
 
-#if BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #elif BUILDFLAG(IS_APPLE)
 #include "ui/gfx/mac/io_surface.h"
@@ -58,7 +58,7 @@ enum GpuMemoryBufferType {
 #if BUILDFLAG(IS_APPLE)
   IO_SURFACE_BUFFER,
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   NATIVE_PIXMAP,
 #endif
 #if BUILDFLAG(IS_WIN)
@@ -154,7 +154,7 @@ struct COMPONENT_EXPORT(GFX) GpuMemoryBufferHandle {
 #if BUILDFLAG(IS_WIN)
   explicit GpuMemoryBufferHandle(DXGIHandle handle);
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   explicit GpuMemoryBufferHandle(gfx::NativePixmapHandle native_pixmap_handle);
 #endif
 #if BUILDFLAG(IS_ANDROID)
@@ -196,7 +196,7 @@ struct COMPONENT_EXPORT(GFX) GpuMemoryBufferHandle {
     return std::move(region_);
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   const NativePixmapHandle& native_pixmap_handle() const& {
     CHECK_EQ(type, NATIVE_PIXMAP);
     return native_pixmap_handle_;
@@ -240,7 +240,7 @@ struct COMPONENT_EXPORT(GFX) GpuMemoryBufferHandle {
   // goal is to make `this` an encapsulated class.
   base::UnsafeSharedMemoryRegion region_;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   NativePixmapHandle native_pixmap_handle_;
 #endif
 
