--- chrome/browser/sharing/sharing_device_registration.cc.orig	2024-08-14 20:54:38 UTC
+++ chrome/browser/sharing/sharing_device_registration.cc
@@ -331,7 +331,7 @@ bool SharingDeviceRegistration::IsRemoteCopySupported(
 
 bool SharingDeviceRegistration::IsRemoteCopySupported() const {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
