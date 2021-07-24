--- utils/vk_loader_platform.h.orig	2021-07-21 20:54:27 UTC
+++ utils/vk_loader_platform.h
@@ -33,7 +33,7 @@
 #undef NOMINMAX
 #include "vulkan/vk_sdk_platform.h"
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__unix__) || defined(__APPLE__)
 /* Linux-specific common code: */
 
 // Headers:
