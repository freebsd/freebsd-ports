--- gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc.orig	2026-09-30 12:59:54 UTC
+++ gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc
@@ -154,7 +154,7 @@ SharedImageUsageSet SupportedUsage() {
 
 SharedImageUsageSet SupportedUsage() {
   SharedImageUsageSet supported_usage =
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
       SHARED_IMAGE_USAGE_WEBGPU_READ | SHARED_IMAGE_USAGE_WEBGPU_WRITE |
       SHARED_IMAGE_USAGE_WEBGPU_SWAP_CHAIN_TEXTURE |
       SHARED_IMAGE_USAGE_WEBGPU_STORAGE_TEXTURE |
