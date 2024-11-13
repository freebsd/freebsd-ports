--- chrome/browser/enterprise/identifiers/profile_id_delegate_impl.cc.orig	2024-06-18 21:43:22 UTC
+++ chrome/browser/enterprise/identifiers/profile_id_delegate_impl.cc
@@ -13,7 +13,7 @@
 #include "components/enterprise/browser/identifiers/identifiers_prefs.h"
 #include "components/prefs/pref_service.h"
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "components/enterprise/browser/controller/browser_dm_token_storage.h"
 #if BUILDFLAG(IS_WIN)
 #include "base/strings/utf_string_conversions.h"
@@ -94,7 +94,7 @@ std::string ProfileIdDelegateImpl::GetDeviceId() {
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // Gets the device ID from the BrowserDMTokenStorage.
 std::string ProfileIdDelegateImpl::GetId() {
   std::string device_id =
