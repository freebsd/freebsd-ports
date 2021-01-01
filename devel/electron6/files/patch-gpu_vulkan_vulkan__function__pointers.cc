--- gpu/vulkan/vulkan_function_pointers.cc.orig	2019-09-10 11:14:06 UTC
+++ gpu/vulkan/vulkan_function_pointers.cc
@@ -352,7 +352,7 @@ bool VulkanFunctionPointers::BindDeviceFunctionPointer
 
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
   vkGetSemaphoreFdKHRFn = reinterpret_cast<PFN_vkGetSemaphoreFdKHR>(
       vkGetDeviceProcAddrFn(vk_device, "vkGetSemaphoreFdKHR"));
@@ -366,7 +366,7 @@ bool VulkanFunctionPointers::BindDeviceFunctionPointer
 
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
   vkGetMemoryFdKHRFn = reinterpret_cast<PFN_vkGetMemoryFdKHR>(
       vkGetDeviceProcAddrFn(vk_device, "vkGetMemoryFdKHR"));
