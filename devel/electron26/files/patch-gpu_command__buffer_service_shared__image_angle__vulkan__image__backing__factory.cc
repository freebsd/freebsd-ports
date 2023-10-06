--- gpu/command_buffer/service/shared_image/angle_vulkan_image_backing_factory.cc.orig	2023-05-25 00:41:56 UTC
+++ gpu/command_buffer/service/shared_image/angle_vulkan_image_backing_factory.cc
@@ -21,7 +21,7 @@ namespace {
 // TODO(penghuang): verify the scanout is the right usage for video playback.
 // crbug.com/1280798
 constexpr uint32_t kSupportedUsage =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     SHARED_IMAGE_USAGE_SCANOUT |
 #endif
     SHARED_IMAGE_USAGE_GLES2 | SHARED_IMAGE_USAGE_GLES2_FRAMEBUFFER_HINT |
