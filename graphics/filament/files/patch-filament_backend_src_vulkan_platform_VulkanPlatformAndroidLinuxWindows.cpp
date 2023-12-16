--- filament/backend/src/vulkan/platform/VulkanPlatformAndroidLinuxWindows.cpp.orig	2023-11-15 05:34:54 UTC
+++ filament/backend/src/vulkan/platform/VulkanPlatformAndroidLinuxWindows.cpp
@@ -30,7 +30,7 @@
 // Platform specific includes and defines
 #if defined(__ANDROID__)
     #include <android/native_window.h>
-#elif defined(__linux__) && defined(FILAMENT_SUPPORTS_WAYLAND)
+#elif defined(LINUX_OR_FREEBSD) && defined(FILAMENT_SUPPORTS_WAYLAND)
     #include <dlfcn.h>
     namespace {
         typedef struct _wl {
@@ -84,7 +84,7 @@ VulkanPlatform::ExtensionSet VulkanPlatform::getRequir
     VulkanPlatform::ExtensionSet ret;
     #if defined(__ANDROID__)
         ret.insert("VK_KHR_android_surface");
-    #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_WAYLAND)
+    #elif defined(LINUX_OR_FREEBSD) && defined(FILAMENT_SUPPORTS_WAYLAND)
         ret.insert("VK_KHR_wayland_surface");
     #elif LINUX_OR_FREEBSD && defined(FILAMENT_SUPPORTS_X11)
         #if defined(FILAMENT_SUPPORTS_XCB)
@@ -117,7 +117,7 @@ VulkanPlatform::SurfaceBundle VulkanPlatform::createVk
         VkResult const result = vkCreateAndroidSurfaceKHR(instance, &createInfo, VKALLOC,
                 (VkSurfaceKHR*) &surface);
         ASSERT_POSTCONDITION(result == VK_SUCCESS, "vkCreateAndroidSurfaceKHR error.");
-    #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_WAYLAND)
+    #elif defined(LINUX_OR_FREEBSD) && defined(FILAMENT_SUPPORTS_WAYLAND)
         wl* ptrval = reinterpret_cast<wl*>(nativeWindow);
         extent.width = ptrval->width;
         extent.height = ptrval->height;
