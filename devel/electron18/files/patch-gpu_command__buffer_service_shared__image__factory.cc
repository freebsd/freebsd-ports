--- gpu/command_buffer/service/shared_image_factory.cc.orig	2022-05-19 05:17:43 UTC
+++ gpu/command_buffer/service/shared_image_factory.cc
@@ -38,12 +38,12 @@
 #include "gpu/command_buffer/service/shared_image_backing_factory_angle_vulkan.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) && defined(USE_OZONE) && BUILDFLAG(ENABLE_VULKAN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(USE_OZONE) && BUILDFLAG(ENABLE_VULKAN)
 #include "ui/ozone/public/ozone_platform.h"
 #endif
 
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN)) && \
-    BUILDFLAG(ENABLE_VULKAN)
+    BUILDFLAG(ENABLE_VULKAN) || BUILDFLAG(IS_BSD)
 #include "gpu/command_buffer/service/external_vk_image_factory.h"
 #elif BUILDFLAG(IS_ANDROID) && BUILDFLAG(ENABLE_VULKAN)
 #include "gpu/command_buffer/service/external_vk_image_factory.h"
@@ -78,7 +78,7 @@
 
 namespace gpu {
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) &&          \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
     !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_CHROMECAST) && \
     BUILDFLAG(ENABLE_VULKAN)
 
@@ -240,7 +240,7 @@ SharedImageFactory::SharedImageFactory(
     factories_.push_back(std::move(external_vk_image_factory));
   }
 #elif defined(USE_OZONE)
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
     !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_CHROMECAST)
   // Desktop Linux, not ChromeOS.
   if (gr_context_type_ == GrContextType::kVulkan &&
