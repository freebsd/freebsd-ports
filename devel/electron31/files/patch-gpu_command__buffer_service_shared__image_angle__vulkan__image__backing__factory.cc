--- gpu/command_buffer/service/shared_image/angle_vulkan_image_backing_factory.cc.orig	2024-02-21 00:20:47 UTC
+++ gpu/command_buffer/service/shared_image/angle_vulkan_image_backing_factory.cc
@@ -21,7 +21,7 @@ constexpr uint32_t kSupportedUsage =
 // TODO(penghuang): verify the scanout is the right usage for video playback.
 // crbug.com/1280798
 constexpr uint32_t kSupportedUsage =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     SHARED_IMAGE_USAGE_SCANOUT |
 #endif
     SHARED_IMAGE_USAGE_GLES2_READ | SHARED_IMAGE_USAGE_GLES2_WRITE |
