--- loader/vk_loader_platform.h.orig	2020-04-02 16:20:56 UTC
+++ loader/vk_loader_platform.h
@@ -31,7 +31,7 @@
 #include "vulkan/vk_platform.h"
 #include "vulkan/vk_sdk_platform.h"
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__unix__)
 /* Linux-specific common code: */
 
 // Headers:
