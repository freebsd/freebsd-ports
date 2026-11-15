--- chrome/browser/safe_browsing/security_settings_bundle_pref_change_handler.cc.orig	2026-06-23 23:37:18 UTC
+++ chrome/browser/safe_browsing/security_settings_bundle_pref_change_handler.cc
@@ -11,7 +11,7 @@
 #include "components/safe_browsing/core/common/safe_browsing_prefs.h"
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/safe_browsing/security_settings_bundle_toast_helper.h"
 #include "chrome/browser/ui/browser_window/public/browser_window_features.h"
 #include "chrome/browser/ui/browser_window/public/browser_window_interface.h"
@@ -33,7 +33,7 @@ void SecuritySettingsBundlePrefChangeHandler::
 void SecuritySettingsBundlePrefChangeHandler::
     MaybeShowEnhancedBundleSettingChangeNotification() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (!profile_ ||
       !base::FeatureList::IsEnabled(safe_browsing::kBundledSecuritySettings)) {
     return;
@@ -59,7 +59,7 @@ void SecuritySettingsBundlePrefChangeHandler::
 }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 void SecuritySettingsBundlePrefChangeHandler::SetToastControllerForTesting(
     ToastController* controller) {
   toast_controller_for_testing_ = controller;
