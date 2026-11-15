--- chrome/browser/safe_browsing/security_settings_bundle_pref_change_handler.h.orig	2026-06-23 23:37:18 UTC
+++ chrome/browser/safe_browsing/security_settings_bundle_pref_change_handler.h
@@ -8,7 +8,7 @@
 #include "base/memory/raw_ptr.h"
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/toasts/toast_controller.h"
 #endif
 
@@ -25,13 +25,13 @@ class SecuritySettingsBundlePrefChangeHandler {
   virtual void MaybeShowEnhancedBundleSettingChangeNotification();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   void SetToastControllerForTesting(ToastController* controller);
 #endif
 
  private:
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   ToastController* GetToastController();
 #endif
 
@@ -39,7 +39,7 @@ class SecuritySettingsBundlePrefChangeHandler {
   raw_ptr<Profile> profile_ = nullptr;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   raw_ptr<ToastController> toast_controller_for_testing_ = nullptr;
 #endif
 };
