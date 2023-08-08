--- filament/backend/src/vulkan/platform/VulkanPlatformAndroidLinuxWindows.cpp.orig	2023-06-20 18:57:42 UTC
+++ filament/backend/src/vulkan/platform/VulkanPlatformAndroidLinuxWindows.cpp
@@ -30,9 +30,9 @@
 // Platform specific includes and defines
 #if defined(__ANDROID__)
     #include <android/native_window.h>
-#elif defined(__linux__) && defined(FILAMENT_SUPPORTS_GGP)
+#elif (defined(__linux__) || defined(__FreeBSD__)) && defined(FILAMENT_SUPPORTS_GGP)
     #include <ggp_c/ggp.h>
-#elif defined(__linux__) && defined(FILAMENT_SUPPORTS_WAYLAND)
+#elif (defined(__linux__) || defined(__FreeBSD__)) && defined(FILAMENT_SUPPORTS_WAYLAND)
     #include <dlfcn.h>
     namespace {
         typedef struct _wl {
@@ -86,9 +86,9 @@ VulkanPlatform::ExtensionSet VulkanPlatform::getRequir
     VulkanPlatform::ExtensionSet ret;
     #if defined(__ANDROID__)
         ret.insert("VK_KHR_android_surface");
-    #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_GGP)
+    #elif (defined(__linux__) || defined(__FreeBSD__)) && defined(FILAMENT_SUPPORTS_GGP)
         ret.insert(VK_GGP_STREAM_DESCRIPTOR_SURFACE_EXTENSION_NAME);
-    #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_WAYLAND)
+    #elif (defined(__linux__) || defined(__FreeBSD__)) && defined(FILAMENT_SUPPORTS_WAYLAND)
         ret.insert("VK_KHR_wayland_surface");
     #elif LINUX_OR_FREEBSD && defined(FILAMENT_SUPPORTS_X11)
         #if defined(FILAMENT_SUPPORTS_XCB)
@@ -121,7 +121,7 @@ VulkanPlatform::SurfaceBundle VulkanPlatform::createVk
         VkResult const result = vkCreateAndroidSurfaceKHR(instance, &createInfo, VKALLOC,
                 (VkSurfaceKHR*) &surface);
         ASSERT_POSTCONDITION(result == VK_SUCCESS, "vkCreateAndroidSurfaceKHR error.");
-    #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_GGP)
+    #elif (defined(__linux__) || defined(__FreeBSD__)) && defined(FILAMENT_SUPPORTS_GGP)
         VkStreamDescriptorSurfaceCreateInfoGGP const surface_create_info = {
                 .sType = VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP,
                 .streamDescriptor = kGgpPrimaryStreamDescriptor,
@@ -135,7 +135,7 @@ VulkanPlatform::SurfaceBundle VulkanPlatform::createVk
         VkResult const result = fpCreateStreamDescriptorSurfaceGGP(instance, &surface_create_info,
                 nullptr, (VkSurfaceKHR*) &surface);
         ASSERT_POSTCONDITION(result == VK_SUCCESS, "vkCreateStreamDescriptorSurfaceGGP error.");
-    #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_WAYLAND)
+    #elif (defined(__linux__) || defined(__FreeBSD__)) && defined(FILAMENT_SUPPORTS_WAYLAND)
         wl* ptrval = reinterpret_cast<wl*>(nativeWindow);
         extent.width = ptrval->width;
         extent.height = ptrval->height;
