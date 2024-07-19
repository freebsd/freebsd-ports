--- chrome/browser/extensions/api/settings_private/prefs_util.cc.orig	2024-06-18 21:43:22 UTC
+++ chrome/browser/extensions/api/settings_private/prefs_util.cc
@@ -197,7 +197,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetAllowlist
   (*s_allowlist)[::prefs::kSidePanelHorizontalAlignment] =
       settings_api::PrefType::kBoolean;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   (*s_allowlist)[::prefs::kUseCustomChromeFrame] =
       settings_api::PrefType::kBoolean;
 #endif
@@ -208,7 +208,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetAllowlist
   // Appearance settings.
   (*s_allowlist)[::prefs::kCurrentThemeID] = settings_api::PrefType::kString;
   (*s_allowlist)[::prefs::kPolicyThemeColor] = settings_api::PrefType::kNumber;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   (*s_allowlist)[::prefs::kSystemTheme] = settings_api::PrefType::kNumber;
 #endif
   (*s_allowlist)[::prefs::kHomePage] = settings_api::PrefType::kUrl;
