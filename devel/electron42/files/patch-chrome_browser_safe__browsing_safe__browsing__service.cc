--- chrome/browser/safe_browsing/safe_browsing_service.cc.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/safe_browsing/safe_browsing_service.cc
@@ -79,7 +79,7 @@
 #include "services/preferences/public/mojom/tracked_preference_validation_delegate.mojom.h"
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/safe_browsing/security_settings_bundle_toast_helper.h"
 #endif
 
@@ -185,7 +185,7 @@ void TriggerSecuritySettingsBundleToastIfNeeded(
   }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (GetSecurityBundleSetting(*profile->GetPrefs()) ==
       SecuritySettingsBundleSetting::ENHANCED) {
     SecuritySettingsBundleToastHelper::GetForProfile(profile.get())
