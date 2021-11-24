--- gpu/command_buffer/service/shared_image_factory.cc.orig	2021-07-15 19:13:40 UTC
+++ gpu/command_buffer/service/shared_image_factory.cc
@@ -29,12 +29,12 @@
 #include "ui/gl/gl_implementation.h"
 #include "ui/gl/trace_util.h"
 
-#if defined(OS_LINUX) && defined(USE_OZONE) && BUILDFLAG(ENABLE_VULKAN)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_OZONE) && BUILDFLAG(ENABLE_VULKAN)
 #include "ui/base/ui_base_features.h"  // nogncheck
 #include "ui/ozone/public/ozone_platform.h"
 #endif
 
-#if (defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_WIN)) && \
+#if (defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_WIN) || defined(OS_BSD)) && \
     BUILDFLAG(ENABLE_VULKAN)
 #include "gpu/command_buffer/service/external_vk_image_factory.h"
 #elif defined(OS_ANDROID) && BUILDFLAG(ENABLE_VULKAN)
@@ -66,8 +66,8 @@
 
 namespace gpu {
 
-#if defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) &&            \
-    !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_CHROMECAST) && \
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
+    !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_CHROMECAST) &&           \
     BUILDFLAG(ENABLE_VULKAN)
 
 namespace {
@@ -143,7 +143,7 @@ SharedImageFactory::SharedImageFactory(
   // |gr_context_type|.
   if (gr_context_type_ == GrContextType::kVulkan) {
 #if BUILDFLAG(ENABLE_VULKAN)
-#if defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
     !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_CHROMECAST)
     // Desktop Linux, not ChromeOS.
     if (ShouldUseExternalVulkanImageFactory()) {
