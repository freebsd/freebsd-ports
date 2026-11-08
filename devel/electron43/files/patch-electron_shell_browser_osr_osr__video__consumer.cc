--- electron/shell/browser/osr/osr_video_consumer.cc.orig	2026-09-18 15:42:59 UTC
+++ electron/shell/browser/osr/osr_video_consumer.cc
@@ -49,7 +49,7 @@ bool IsPlatformSharedTextureHandle(const gfx::GpuMemor
   return handle.type == gfx::DXGI_SHARED_HANDLE;
 #elif BUILDFLAG(IS_APPLE)
   return handle.type == gfx::IO_SURFACE_BUFFER;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return handle.type == gfx::NATIVE_PIXMAP;
 #else
   return false;
@@ -160,7 +160,7 @@ void OffScreenVideoConsumer::OnFrameCaptured(
 #elif BUILDFLAG(IS_APPLE)
     texture.shared_texture_handle =
         reinterpret_cast<uintptr_t>(gmb_handle.io_surface().get());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     const auto& native_pixmap = gmb_handle.native_pixmap_handle();
     texture.modifier = native_pixmap.modifier;
     texture.supports_zero_copy_webgpu_import =
