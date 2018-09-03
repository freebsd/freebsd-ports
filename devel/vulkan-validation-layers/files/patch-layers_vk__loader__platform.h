--- layers/vk_loader_platform.h.orig	2018-08-07 18:19:43 UTC
+++ layers/vk_loader_platform.h
@@ -31,7 +31,7 @@
 #include "vulkan/vk_platform.h"
 #include "vulkan/vk_sdk_platform.h"
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__unix__)
 /* Linux-specific common code: */
 
 // Headers:
