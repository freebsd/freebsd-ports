--- chrome/browser/sharing/sharing_device_registration.cc.orig	2022-05-19 03:45:18 UTC
+++ chrome/browser/sharing/sharing_device_registration.cc
@@ -327,7 +327,7 @@ bool SharingDeviceRegistration::IsSmsFetcherSupported(
 
 bool SharingDeviceRegistration::IsRemoteCopySupported() const {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
