--- chrome/browser/extensions/api/settings_private/prefs_util.cc.orig	2023-02-01 18:43:11 UTC
+++ chrome/browser/extensions/api/settings_private/prefs_util.cc
@@ -185,7 +185,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetAllowlist
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   (*s_allowlist)[::prefs::kUseCustomChromeFrame] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
 #endif
@@ -197,7 +197,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetAllowlist
       settings_api::PrefType::PREF_TYPE_STRING;
   (*s_allowlist)[::prefs::kPolicyThemeColor] =
       settings_api::PrefType::PREF_TYPE_NUMBER;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   (*s_allowlist)[::prefs::kUsesSystemThemeDeprecated] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
   (*s_allowlist)[::prefs::kSystemTheme] =
