--- gpu/vulkan/generate_bindings.py.orig	2022-05-19 05:17:43 UTC
+++ gpu/vulkan/generate_bindings.py
@@ -185,7 +185,7 @@ VULKAN_DEVICE_FUNCTIONS = [
   },
   {
     'ifdef':
-    'BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)',
+    'BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)',
     'extension': 'VK_KHR_EXTERNAL_SEMAPHORE_FD_EXTENSION_NAME',
     'functions': [
       'vkGetSemaphoreFdKHR',
@@ -202,7 +202,7 @@ VULKAN_DEVICE_FUNCTIONS = [
   },
   {
     'ifdef':
-    'BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)',
+    'BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)',
     'extension': 'VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME',
     'functions': [
       'vkGetMemoryFdKHR',
@@ -253,7 +253,7 @@ VULKAN_DEVICE_FUNCTIONS = [
     ]
   },
   {
-    'ifdef': 'BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)',
+    'ifdef': 'BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)',
     'extension': 'VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_EXTENSION_NAME',
     'functions': [
       'vkGetImageDrmFormatModifierPropertiesEXT',
