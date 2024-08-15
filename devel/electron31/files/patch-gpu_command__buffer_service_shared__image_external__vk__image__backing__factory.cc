--- gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc.orig	2024-04-15 20:33:59 UTC
+++ gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc
@@ -147,7 +147,7 @@ constexpr uint32_t kSupportedUsage =
 }  // namespace
 
 constexpr uint32_t kSupportedUsage =
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
     SHARED_IMAGE_USAGE_WEBGPU_READ | SHARED_IMAGE_USAGE_WEBGPU_WRITE |
     SHARED_IMAGE_USAGE_WEBGPU_SWAP_CHAIN_TEXTURE |
     SHARED_IMAGE_USAGE_WEBGPU_STORAGE_TEXTURE |
