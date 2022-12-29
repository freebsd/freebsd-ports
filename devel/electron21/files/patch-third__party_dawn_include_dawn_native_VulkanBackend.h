--- third_party/dawn/include/dawn/native/VulkanBackend.h.orig	2022-07-22 17:30:31 UTC
+++ third_party/dawn/include/dawn/native/VulkanBackend.h
@@ -70,7 +70,7 @@ struct ExternalImageExportInfoVk : ExternalImageExport
 };
 
 // Can't use DAWN_PLATFORM_IS(LINUX) since header included in both Dawn and Chrome
-#ifdef __linux__
+#if defined(__linux__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 
 // Common properties of external images represented by FDs. On successful import the file
 // descriptor's ownership is transferred to the Dawn implementation and they shouldn't be
