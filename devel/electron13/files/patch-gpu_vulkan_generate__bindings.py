--- gpu/vulkan/generate_bindings.py.orig	2021-07-15 19:13:40 UTC
+++ gpu/vulkan/generate_bindings.py
@@ -183,7 +183,7 @@ VULKAN_DEVICE_FUNCTIONS = [
     ]
   },
   {
-    'ifdef': 'defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)',
+    'ifdef': 'defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)',
     'extension': 'VK_KHR_EXTERNAL_SEMAPHORE_FD_EXTENSION_NAME',
     'functions': [
       'vkGetSemaphoreFdKHR',
@@ -199,7 +199,7 @@ VULKAN_DEVICE_FUNCTIONS = [
     ]
   },
   {
-    'ifdef': 'defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)',
+    'ifdef': 'defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)',
     'extension': 'VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME',
     'functions': [
       'vkGetMemoryFdKHR',
@@ -250,7 +250,7 @@ VULKAN_DEVICE_FUNCTIONS = [
     ]
   },
   {
-    'ifdef': 'defined(OS_LINUX) || defined(OS_CHROMEOS)',
+    'ifdef': 'defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)',
     'extension': 'VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_EXTENSION_NAME',
     'functions': [
       'vkGetImageDrmFormatModifierPropertiesEXT',
