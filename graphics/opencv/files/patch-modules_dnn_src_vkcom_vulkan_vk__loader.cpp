--- modules/dnn/src/vkcom/vulkan/vk_loader.cpp.orig	2021-01-30 08:42:05 UTC
+++ modules/dnn/src/vkcom/vulkan/vk_loader.cpp
@@ -21,7 +21,7 @@ typedef HMODULE VulkanHandle;
         (PFN_vkGetInstanceProcAddr)GetProcAddress(handle, "vkGetInstanceProcAddr");
 #endif // _WIN32
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <dlfcn.h>
 #include <stdio.h>
 typedef void* VulkanHandle;
