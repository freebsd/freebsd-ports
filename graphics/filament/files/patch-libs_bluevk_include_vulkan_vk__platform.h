--- libs/bluevk/include/vulkan/vk_platform.h.orig	2022-08-19 02:33:42 UTC
+++ libs/bluevk/include/vulkan/vk_platform.h
@@ -25,7 +25,7 @@
 #define VK_USE_PLATFORM_ANDROID_KHR 1
 #elif defined(IOS)
 #define VK_USE_PLATFORM_IOS_MVK 1
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #if defined(FILAMENT_SUPPORTS_XCB)
 #define VK_USE_PLATFORM_XCB_KHR 1
 #endif
