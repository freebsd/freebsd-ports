--- gpu/vulkan/generate_bindings.py.orig	2021-09-14 01:51:58 UTC
+++ gpu/vulkan/generate_bindings.py
@@ -184,7 +184,7 @@ VULKAN_DEVICE_FUNCTIONS = [
     ]
   },
   {
-    'ifdef': 'defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)',
+    'ifdef': 'defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)',
     'extension': 'VK_KHR_EXTERNAL_SEMAPHORE_FD_EXTENSION_NAME',
     'functions': [
       'vkGetSemaphoreFdKHR',
@@ -200,7 +200,7 @@ VULKAN_DEVICE_FUNCTIONS = [
     ]
   },
   {
-    'ifdef': 'defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)',
+    'ifdef': 'defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)',
     'extension': 'VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME',
     'functions': [
       'vkGetMemoryFdKHR',
@@ -251,7 +251,7 @@ VULKAN_DEVICE_FUNCTIONS = [
     ]
   },
   {
-    'ifdef': 'defined(OS_LINUX) || defined(OS_CHROMEOS)',
+    'ifdef': 'defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)',
     'extension': 'VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_EXTENSION_NAME',
     'functions': [
       'vkGetImageDrmFormatModifierPropertiesEXT',
