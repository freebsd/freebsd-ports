--- third_party/angle/src/libANGLE/renderer/vulkan/DisplayVk_api.h.orig	2021-04-14 01:15:19 UTC
+++ third_party/angle/src/libANGLE/renderer/vulkan/DisplayVk_api.h
@@ -19,7 +19,7 @@ bool IsVulkanWin32DisplayAvailable();
 DisplayImpl *CreateVulkanWin32Display(const egl::DisplayState &state);
 #endif  // defined(ANGLE_PLATFORM_WINDOWS)
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
 bool IsVulkanXcbDisplayAvailable();
 DisplayImpl *CreateVulkanXcbDisplay(const egl::DisplayState &state);
 
@@ -28,7 +28,7 @@ DisplayImpl *CreateVulkanSimpleDisplay(const egl::Disp
 
 bool IsVulkanHeadlessDisplayAvailable();
 DisplayImpl *CreateVulkanHeadlessDisplay(const egl::DisplayState &state);
-#endif  // defined(ANGLE_PLATFORM_LINUX)
+#endif  // defined(ANGLE_PLATFORM_POSIX)
 
 #if defined(ANGLE_PLATFORM_ANDROID)
 bool IsVulkanAndroidDisplayAvailable();
