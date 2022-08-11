--- third_party/dawn/include/dawn/native/VulkanBackend.h.orig	2022-05-19 05:18:24 UTC
+++ third_party/dawn/include/dawn/native/VulkanBackend.h
@@ -69,7 +69,7 @@ namespace dawn::native::vulkan {
     };
 
 // Can't use DAWN_PLATFORM_LINUX since header included in both Dawn and Chrome
-#ifdef __linux__
+#if defined(__linux__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 
     // Common properties of external images represented by FDs. On successful import the file
     // descriptor's ownership is transferred to the Dawn implementation and they shouldn't be
