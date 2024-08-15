--- gpu/command_buffer/service/shared_image/shared_image_manager.cc.orig	2024-06-18 21:43:33 UTC
+++ gpu/command_buffer/service/shared_image/shared_image_manager.cc
@@ -570,7 +570,7 @@ bool SharedImageManager::SupportsScanoutImages() {
   return true;
 #elif BUILDFLAG(IS_ANDROID)
   return base::AndroidHardwareBufferCompat::IsSupportAvailable();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return ui::OzonePlatform::GetInstance()
       ->GetPlatformRuntimeProperties()
       .supports_native_pixmaps;
