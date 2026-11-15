--- electron/shell/browser/osr/osr_video_consumer.cc.orig	2026-10-26 21:12:45 UTC
+++ electron/shell/browser/osr/osr_video_consumer.cc
@@ -48,7 +48,7 @@ bool IsPlatformSharedTextureHandle(const gfx::GpuMemor
   return handle.type == gfx::DXGI_SHARED_HANDLE;
 #elif BUILDFLAG(IS_APPLE)
   return handle.type == gfx::IO_SURFACE_BUFFER;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return handle.type == gfx::NATIVE_PIXMAP;
 #else
   return false;
@@ -159,7 +159,7 @@ void OffScreenVideoConsumer::OnFrameCaptured(
 #elif BUILDFLAG(IS_APPLE)
     texture.shared_texture_handle =
         reinterpret_cast<uintptr_t>(gmb_handle.io_surface().get());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     const auto& native_pixmap = gmb_handle.native_pixmap_handle();
     texture.modifier = native_pixmap.modifier;
     texture.supports_zero_copy_webgpu_import =
