--- gpu/command_buffer/service/shared_image/shared_image_manager.cc.orig	2026-04-28 21:06:17 UTC
+++ gpu/command_buffer/service/shared_image/shared_image_manager.cc
@@ -641,7 +641,7 @@ bool SharedImageManager::SupportsScanoutImages() {
   return true;
 #elif BUILDFLAG(IS_ANDROID)
   return true;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return supports_overlays_on_ozone_;
 #elif BUILDFLAG(IS_WIN)
   return gl::DirectCompositionTextureSupported();
