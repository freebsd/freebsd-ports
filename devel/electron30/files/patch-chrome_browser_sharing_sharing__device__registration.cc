--- chrome/browser/sharing/sharing_device_registration.cc.orig	2024-02-21 00:20:36 UTC
+++ chrome/browser/sharing/sharing_device_registration.cc
@@ -328,7 +328,7 @@ bool SharingDeviceRegistration::IsRemoteCopySupported(
 
 bool SharingDeviceRegistration::IsRemoteCopySupported() const {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
