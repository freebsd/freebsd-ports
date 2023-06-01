- workaround for https://github.com/google/filament/issues/6861

--- filament/backend/src/vulkan/platform/PlatformVulkanAndroidLinuxWindows.cpp.orig	2023-06-01 16:53:44 UTC
+++ filament/backend/src/vulkan/platform/PlatformVulkanAndroidLinuxWindows.cpp
@@ -38,7 +38,7 @@
             uint32_t height;
         } wl;
     }// anonymous namespace
-#elif defined(__linux__) && defined(FILAMENT_SUPPORTS_X11)
+#elif (defined(__linux__) || defined(__FreeBSD__)) && defined(FILAMENT_SUPPORTS_X11)
     #include <dlfcn.h>
     #if defined(FILAMENT_SUPPORTS_XCB)
         #include <xcb/xcb.h>
@@ -83,11 +83,11 @@ Driver* PlatformVulkan::createDriver(void* const share
     static const char* requiredInstanceExtensions[] = {
     #if defined(__ANDROID__)
         "VK_KHR_android_surface",
-    #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_GGP)
+    #elif (defined(__linux__) || defined(__FreeBSD__)) && defined(FILAMENT_SUPPORTS_GGP)
         VK_GGP_STREAM_DESCRIPTOR_SURFACE_EXTENSION_NAME,
     #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_WAYLAND)
         "VK_KHR_wayland_surface",
-    #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_X11)
+    #elif (defined(__linux__) || defined(__FreeBSD__)) && defined(FILAMENT_SUPPORTS_X11)
         #if defined(FILAMENT_SUPPORTS_XCB)
             "VK_KHR_xcb_surface",
         #endif
@@ -121,7 +121,7 @@ PlatformVulkan::SurfaceBundle PlatformVulkan::createVk
         VkResult const result = vkCreateAndroidSurfaceKHR(instance, &createInfo, VKALLOC,
                 (VkSurfaceKHR*) &bundle.surface);
         ASSERT_POSTCONDITION(result == VK_SUCCESS, "vkCreateAndroidSurfaceKHR error.");
-    #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_GGP)
+    #elif (defined(__linux__) || defined(__FreeBSD__)) && defined(FILAMENT_SUPPORTS_GGP)
         VkStreamDescriptorSurfaceCreateInfoGGP const surface_create_info = {
                 .sType = VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP,
                 .streamDescriptor = kGgpPrimaryStreamDescriptor,
@@ -135,7 +135,7 @@ PlatformVulkan::SurfaceBundle PlatformVulkan::createVk
         VkResult const result = fpCreateStreamDescriptorSurfaceGGP(instance, &surface_create_info,
                 nullptr, (VkSurfaceKHR*) &bundle.surface);
         ASSERT_POSTCONDITION(result == VK_SUCCESS, "vkCreateStreamDescriptorSurfaceGGP error.");
-    #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_WAYLAND)
+    #elif (defined(__linux__) || defined(__FreeBSD__)) && defined(FILAMENT_SUPPORTS_WAYLAND)
         wl* ptrval = reinterpret_cast<wl*>(nativeWindow);
         bundle.width = ptrval->width;
         bundle.height = ptrval->height;
@@ -150,7 +150,7 @@ PlatformVulkan::SurfaceBundle PlatformVulkan::createVk
         VkResult const result = vkCreateWaylandSurfaceKHR(instance, &createInfo, VKALLOC,
                 (VkSurfaceKHR*) &bundle.surface);
         ASSERT_POSTCONDITION(result == VK_SUCCESS, "vkCreateWaylandSurfaceKHR error.");
-    #elif defined(__linux__) && defined(FILAMENT_SUPPORTS_X11)
+    #elif (defined(__linux__) || defined(__FreeBSD__)) && defined(FILAMENT_SUPPORTS_X11)
         if (g_x11_vk.library == nullptr) {
             g_x11_vk.library = dlopen(LIBRARY_X11, RTLD_LOCAL | RTLD_NOW);
             ASSERT_PRECONDITION(g_x11_vk.library, "Unable to open X11 library.");
