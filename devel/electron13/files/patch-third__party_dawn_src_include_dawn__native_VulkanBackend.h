--- third_party/dawn/src/include/dawn_native/VulkanBackend.h.orig	2021-07-15 19:15:43 UTC
+++ third_party/dawn/src/include/dawn_native/VulkanBackend.h
@@ -63,7 +63,7 @@ namespace dawn_native { namespace vulkan {
     };
 
 // Can't use DAWN_PLATFORM_LINUX since header included in both Dawn and Chrome
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 
         // Common properties of external images represented by FDs. On successful import the file
         // descriptor's ownership is transferred to the Dawn implementation and they shouldn't be
