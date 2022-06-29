--- gpu/command_buffer/service/shared_image_factory.cc.orig	2022-05-25 04:01:02 UTC
+++ gpu/command_buffer/service/shared_image_factory.cc
@@ -46,7 +46,7 @@
 #include "ui/ozone/public/ozone_platform.h"
 #endif
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENABLE_VULKAN)
 #include "gpu/command_buffer/service/external_vk_image_factory.h"
 #elif BUILDFLAG(IS_ANDROID) && BUILDFLAG(ENABLE_VULKAN)
@@ -81,7 +81,7 @@
 
 namespace gpu {
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) &&          \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS_ASH) &&          \
     !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_CHROMECAST) && \
     BUILDFLAG(ENABLE_VULKAN)
 
@@ -325,7 +325,7 @@ SharedImageFactory::SharedImageFactory(
     factories_.push_back(std::move(external_vk_image_factory));
   }
 #elif defined(USE_OZONE)
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
     !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_CHROMECAST)
   // Desktop Linux, not ChromeOS.
   if (gr_context_type_ == GrContextType::kVulkan &&
