--- electron/shell/browser/osr/osr_video_consumer.cc.orig	2025-09-02 20:56:04 UTC
+++ electron/shell/browser/osr/osr_video_consumer.cc
@@ -108,7 +108,7 @@ void OffScreenVideoConsumer::OnFrameCaptured(
 #elif BUILDFLAG(IS_APPLE)
     texture.shared_texture_handle =
         reinterpret_cast<uintptr_t>(gmb_handle.io_surface().get());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     const auto& native_pixmap = gmb_handle.native_pixmap_handle();
     texture.modifier = native_pixmap.modifier;
     for (const auto& plane : native_pixmap.planes) {
