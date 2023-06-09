--- filament/backend/src/vulkan/platform/VulkanPlatformAndroidLinuxWindows.cpp.orig	2023-06-09 00:40:30 UTC
+++ filament/backend/src/vulkan/platform/VulkanPlatformAndroidLinuxWindows.cpp
@@ -26,9 +26,9 @@
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
@@ -38,7 +38,7 @@
             uint32_t height;
         } wl;
     }// anonymous namespace
-#elif defined(__linux__) && defined(FILAMENT_SUPPORTS_X11)
+#elif (defined(__linux__) || defined(__FreeBSD__)) && defined(FILAMENT_SUPPORTS_X11)
     // TODO: we should allow for headless on Linux explicitly. Right now this is the headless path
     // (with no FILAMENT_SUPPORTS_XCB or FILAMENT_SUPPORTS_XLIB).
     #include <dlfcn.h>
@@ -82,11 +82,11 @@ VulkanPlatform::ExtensionSet VulkanPlatform::getRequir
     VulkanPlatform::ExtensionSet ret;
     #if defined(__ANDROID__)
         ret.insert("VK_KHR_android_surface");
-    #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_GGP)
+    #elif (defined(__linux__) || defined(__FreeBSD__)) && defined(FILAMENT_SUPPORTS_GGP)
         ret.insert(VK_GGP_STREAM_DESCRIPTOR_SURFACE_EXTENSION_NAME);
-    #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_WAYLAND)
+    #elif (defined(__linux__) || defined(__FreeBSD__)) && defined(FILAMENT_SUPPORTS_WAYLAND)
         ret.insert("VK_KHR_wayland_surface");
-    #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_X11)
+    #elif (defined(__linux__) || defined(__FreeBSD__)) && defined(FILAMENT_SUPPORTS_X11)
         #if defined(FILAMENT_SUPPORTS_XCB)
             ret.insert("VK_KHR_xcb_surface");
         #endif
@@ -117,7 +117,7 @@ VulkanPlatform::SurfaceBundle VulkanPlatform::createVk
         VkResult const result = vkCreateAndroidSurfaceKHR(instance, &createInfo, VKALLOC,
                 (VkSurfaceKHR*) &surface);
         ASSERT_POSTCONDITION(result == VK_SUCCESS, "vkCreateAndroidSurfaceKHR error.");
-    #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_GGP)
+    #elif (defined(__linux__) || defined(__FreeBSD__)) && defined(FILAMENT_SUPPORTS_GGP)
         VkStreamDescriptorSurfaceCreateInfoGGP const surface_create_info = {
                 .sType = VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP,
                 .streamDescriptor = kGgpPrimaryStreamDescriptor,
@@ -131,7 +131,7 @@ VulkanPlatform::SurfaceBundle VulkanPlatform::createVk
         VkResult const result = fpCreateStreamDescriptorSurfaceGGP(instance, &surface_create_info,
                 nullptr, (VkSurfaceKHR*) &surface);
         ASSERT_POSTCONDITION(result == VK_SUCCESS, "vkCreateStreamDescriptorSurfaceGGP error.");
-    #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_WAYLAND)
+    #elif (defined(__linux__) || defined(__FreeBSD__)) && defined(FILAMENT_SUPPORTS_WAYLAND)
         wl* ptrval = reinterpret_cast<wl*>(nativeWindow);
         extent.width = ptrval->width;
         extent.height = ptrval->height;
@@ -146,7 +146,7 @@ VulkanPlatform::SurfaceBundle VulkanPlatform::createVk
         VkResult const result = vkCreateWaylandSurfaceKHR(instance, &createInfo, VKALLOC,
                 (VkSurfaceKHR*) &surface);
         ASSERT_POSTCONDITION(result == VK_SUCCESS, "vkCreateWaylandSurfaceKHR error.");
-    #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_X11)
+    #elif (defined(__linux__) || defined(__FreeBSD__)) && defined(FILAMENT_SUPPORTS_X11)
         if (g_x11_vk.library == nullptr) {
             g_x11_vk.library = dlopen(LIBRARY_X11, RTLD_LOCAL | RTLD_NOW);
             ASSERT_PRECONDITION(g_x11_vk.library, "Unable to open X11 library.");
