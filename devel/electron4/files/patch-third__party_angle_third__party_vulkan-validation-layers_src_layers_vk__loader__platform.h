--- third_party/angle/third_party/vulkan-validation-layers/src/layers/vk_loader_platform.h.orig	2019-03-15 06:30:51 UTC
+++ third_party/angle/third_party/vulkan-validation-layers/src/layers/vk_loader_platform.h
@@ -31,7 +31,7 @@
 #include "vulkan/vk_platform.h"
 #include "vulkan/vk_sdk_platform.h"
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 /* Linux-specific common code: */
 
 // Headers:
