--- gpu/vulkan/vulkan_function_pointers.h.orig	2021-04-14 01:08:50 UTC
+++ gpu/vulkan/vulkan_function_pointers.h
@@ -240,10 +240,10 @@ struct COMPONENT_EXPORT(VULKAN) VulkanFunctionPointers
       vkGetAndroidHardwareBufferPropertiesANDROID;
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   VulkanFunction<PFN_vkGetSemaphoreFdKHR> vkGetSemaphoreFdKHR;
   VulkanFunction<PFN_vkImportSemaphoreFdKHR> vkImportSemaphoreFdKHR;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
   VulkanFunction<PFN_vkGetSemaphoreWin32HandleKHR> vkGetSemaphoreWin32HandleKHR;
@@ -251,10 +251,10 @@ struct COMPONENT_EXPORT(VULKAN) VulkanFunctionPointers
       vkImportSemaphoreWin32HandleKHR;
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   VulkanFunction<PFN_vkGetMemoryFdKHR> vkGetMemoryFdKHR;
   VulkanFunction<PFN_vkGetMemoryFdPropertiesKHR> vkGetMemoryFdPropertiesKHR;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
   VulkanFunction<PFN_vkGetMemoryWin32HandleKHR> vkGetMemoryWin32HandleKHR;
@@ -291,10 +291,10 @@ struct COMPONENT_EXPORT(VULKAN) VulkanFunctionPointers
   VulkanFunction<PFN_vkGetSwapchainImagesKHR> vkGetSwapchainImagesKHR;
   VulkanFunction<PFN_vkQueuePresentKHR> vkQueuePresentKHR;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   VulkanFunction<PFN_vkGetImageDrmFormatModifierPropertiesEXT>
       vkGetImageDrmFormatModifierPropertiesEXT;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 };
 
 }  // namespace gpu
@@ -985,7 +985,7 @@ ALWAYS_INLINE VkResult vkGetAndroidHardwareBufferPrope
 }
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 ALWAYS_INLINE VkResult
 vkGetSemaphoreFdKHR(VkDevice device,
                     const VkSemaphoreGetFdInfoKHR* pGetFdInfo,
@@ -999,7 +999,7 @@ ALWAYS_INLINE VkResult vkImportSemaphoreFdKHR(
   return gpu::GetVulkanFunctionPointers()->vkImportSemaphoreFdKHR(
       device, pImportSemaphoreFdInfo);
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 ALWAYS_INLINE VkResult vkGetSemaphoreWin32HandleKHR(
@@ -1018,7 +1018,7 @@ vkImportSemaphoreWin32HandleKHR(VkDevice device,
 }
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 ALWAYS_INLINE VkResult vkGetMemoryFdKHR(VkDevice device,
                                         const VkMemoryGetFdInfoKHR* pGetFdInfo,
                                         int* pFd) {
@@ -1033,7 +1033,7 @@ vkGetMemoryFdPropertiesKHR(VkDevice device,
   return gpu::GetVulkanFunctionPointers()->vkGetMemoryFdPropertiesKHR(
       device, handleType, fd, pMemoryFdProperties);
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 ALWAYS_INLINE VkResult vkGetMemoryWin32HandleKHR(
@@ -1113,7 +1113,7 @@ ALWAYS_INLINE VkResult vkQueuePresentKHR(VkQueue queue
                                                              pPresentInfo);
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 ALWAYS_INLINE VkResult vkGetImageDrmFormatModifierPropertiesEXT(
     VkDevice device,
     VkImage image,
@@ -1121,6 +1121,6 @@ ALWAYS_INLINE VkResult vkGetImageDrmFormatModifierProp
   return gpu::GetVulkanFunctionPointers()
       ->vkGetImageDrmFormatModifierPropertiesEXT(device, image, pProperties);
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
-#endif  // GPU_VULKAN_VULKAN_FUNCTION_POINTERS_H_
\ No newline at end of file
+#endif  // GPU_VULKAN_VULKAN_FUNCTION_POINTERS_H_
