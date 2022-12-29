--- gpu/command_buffer/service/shared_image/shared_image_factory.cc.orig	2022-08-31 12:19:35 UTC
+++ gpu/command_buffer/service/shared_image/shared_image_factory.cc
@@ -52,7 +52,7 @@
 #include "ui/ozone/public/surface_factory_ozone.h"
 #endif
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENABLE_VULKAN)
 #include "gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.h"
 #include "gpu/command_buffer/service/shared_image/ozone_image_backing_factory.h"
@@ -88,7 +88,7 @@ namespace gpu {
 
 namespace {
 
-#if defined(USE_OZONE) && BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)
+#if defined(USE_OZONE) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CASTOS)
 
 bool ShouldUseExternalVulkanImageFactory() {
 #if BUILDFLAG(ENABLE_VULKAN)
@@ -398,7 +398,7 @@ SharedImageFactory::SharedImageFactory(
     factories_.push_back(std::move(external_vk_image_factory));
   }
 #elif defined(USE_OZONE)
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CASTOS)
   // Desktop Linux, not ChromeOS.
   if (ShouldUseOzoneImageBackingFactory()) {
     auto ozone_factory =
