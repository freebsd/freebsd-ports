--- electron/shell/browser/osr/osr_video_consumer.cc.orig	2026-04-15 14:10:25 UTC
+++ electron/shell/browser/osr/osr_video_consumer.cc
@@ -130,7 +130,7 @@ void OffScreenVideoConsumer::OnFrameCaptured(
 #elif BUILDFLAG(IS_APPLE)
     texture.shared_texture_handle =
         reinterpret_cast<uintptr_t>(gmb_handle.io_surface().get());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     const auto& native_pixmap = gmb_handle.native_pixmap_handle();
     texture.modifier = native_pixmap.modifier;
     texture.supports_zero_copy_webgpu_import =
