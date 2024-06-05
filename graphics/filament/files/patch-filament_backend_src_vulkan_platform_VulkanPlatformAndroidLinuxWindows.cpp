--- filament/backend/src/vulkan/platform/VulkanPlatformAndroidLinuxWindows.cpp.orig	2024-06-03 18:10:41 UTC
+++ filament/backend/src/vulkan/platform/VulkanPlatformAndroidLinuxWindows.cpp
@@ -36,7 +36,7 @@
 // Platform specific includes and defines
 #if defined(__ANDROID__)
     #include <android/native_window.h>
-#elif defined(__linux__) && defined(FILAMENT_SUPPORTS_WAYLAND)
+#elif defined(LINUX_OR_FREEBSD) && defined(FILAMENT_SUPPORTS_WAYLAND)
     #include <dlfcn.h>
     namespace {
         typedef struct _wl {
@@ -90,7 +90,7 @@ VulkanPlatform::ExtensionSet VulkanPlatform::getSwapch
     VulkanPlatform::ExtensionSet const ret = {
 #if defined(__ANDROID__)
         VK_KHR_ANDROID_SURFACE_EXTENSION_NAME,
-#elif defined(__linux__) && defined(FILAMENT_SUPPORTS_WAYLAND)
+#elif defined(LINUX_OR_FREEBSD) && defined(FILAMENT_SUPPORTS_WAYLAND)
         VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME,
 #elif defined(LINUX_OR_FREEBSD) && defined(FILAMENT_SUPPORTS_X11)
     #if defined(FILAMENT_SUPPORTS_XCB)
@@ -124,7 +124,7 @@ VulkanPlatform::SurfaceBundle VulkanPlatform::createVk
         VkResult const result = vkCreateAndroidSurfaceKHR(instance, &createInfo, VKALLOC,
                 (VkSurfaceKHR*) &surface);
         FILAMENT_CHECK_POSTCONDITION(result == VK_SUCCESS) << "vkCreateAndroidSurfaceKHR error.";
-    #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_WAYLAND)
+    #elif defined(LINUX_OR_FREEBSD) && defined(FILAMENT_SUPPORTS_WAYLAND)
         wl* ptrval = reinterpret_cast<wl*>(nativeWindow);
         extent.width = ptrval->width;
         extent.height = ptrval->height;
