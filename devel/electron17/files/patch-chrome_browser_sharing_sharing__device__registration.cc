--- chrome/browser/sharing/sharing_device_registration.cc.orig	2022-05-11 07:16:48 UTC
+++ chrome/browser/sharing/sharing_device_registration.cc
@@ -327,7 +327,7 @@ bool SharingDeviceRegistration::IsSmsFetcherSupported(
 
 bool SharingDeviceRegistration::IsRemoteCopySupported() const {
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
   return true;
 #else
   return false;
