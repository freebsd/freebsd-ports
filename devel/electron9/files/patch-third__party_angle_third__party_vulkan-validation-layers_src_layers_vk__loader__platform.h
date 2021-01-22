--- third_party/angle/third_party/vulkan-validation-layers/src/layers/vk_loader_platform.h.orig	2020-05-26 07:52:30 UTC
+++ third_party/angle/third_party/vulkan-validation-layers/src/layers/vk_loader_platform.h
@@ -33,7 +33,7 @@
 #undef NOMINMAX
 #include "vulkan/vk_sdk_platform.h"
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 /* Linux-specific common code: */
 
 // Headers:
