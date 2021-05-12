--- gpu/vulkan/vulkan_function_pointers.cc.orig	2021-04-14 01:08:50 UTC
+++ gpu/vulkan/vulkan_function_pointers.cc
@@ -890,7 +890,7 @@ bool VulkanFunctionPointers::BindDeviceFunctionPointer
   }
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   if (gfx::HasExtension(enabled_extensions,
                         VK_KHR_EXTERNAL_SEMAPHORE_FD_EXTENSION_NAME)) {
     vkGetSemaphoreFdKHR = reinterpret_cast<PFN_vkGetSemaphoreFdKHR>(
@@ -909,7 +909,7 @@ bool VulkanFunctionPointers::BindDeviceFunctionPointer
       return false;
     }
   }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
   if (gfx::HasExtension(enabled_extensions,
@@ -934,7 +934,7 @@ bool VulkanFunctionPointers::BindDeviceFunctionPointer
   }
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   if (gfx::HasExtension(enabled_extensions,
                         VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME)) {
     vkGetMemoryFdKHR = reinterpret_cast<PFN_vkGetMemoryFdKHR>(
@@ -954,7 +954,7 @@ bool VulkanFunctionPointers::BindDeviceFunctionPointer
       return false;
     }
   }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
   if (gfx::HasExtension(enabled_extensions,
@@ -1103,7 +1103,7 @@ bool VulkanFunctionPointers::BindDeviceFunctionPointer
     }
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (gfx::HasExtension(enabled_extensions,
                         VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_EXTENSION_NAME)) {
     vkGetImageDrmFormatModifierPropertiesEXT =
@@ -1116,7 +1116,7 @@ bool VulkanFunctionPointers::BindDeviceFunctionPointer
       return false;
     }
   }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   return true;
 }
