--- gpu/command_buffer/service/shared_image/angle_vulkan_image_backing_factory.cc.orig	2024-08-14 20:55:03 UTC
+++ gpu/command_buffer/service/shared_image/angle_vulkan_image_backing_factory.cc
@@ -20,7 +20,7 @@ constexpr SharedImageUsageSet kSupportedUsage =
 // TODO(penghuang): verify the scanout is the right usage for video playback.
 // crbug.com/1280798
 constexpr SharedImageUsageSet kSupportedUsage =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     SHARED_IMAGE_USAGE_SCANOUT |
 #endif
     SHARED_IMAGE_USAGE_GLES2_READ | SHARED_IMAGE_USAGE_GLES2_WRITE |
