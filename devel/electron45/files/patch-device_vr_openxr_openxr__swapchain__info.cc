--- device/vr/openxr/openxr_swapchain_info.cc.orig	2026-10-19 21:50:55 UTC
+++ device/vr/openxr/openxr_swapchain_info.cc
@@ -17,7 +17,7 @@ OpenXrSwapchainInfo::OpenXrSwapchainInfo(uint32_t text
 #elif BUILDFLAG(IS_ANDROID)
 OpenXrSwapchainInfo::OpenXrSwapchainInfo(uint32_t texture)
     : openxr_texture(texture) {}
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 OpenXrSwapchainInfo::OpenXrSwapchainInfo(VkImage vk_image)
     : vk_image(vk_image) {}
 #endif
