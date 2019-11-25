--- third_party/angle/third_party/vulkan-loader/src/loader/vk_loader_platform.h.orig	2019-09-10 10:47:33 UTC
+++ third_party/angle/third_party/vulkan-loader/src/loader/vk_loader_platform.h
@@ -31,7 +31,7 @@
 #include "vulkan/vk_platform.h"
 #include "vulkan/vk_sdk_platform.h"
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 /* Linux-specific common code: */
 
 // Headers:
