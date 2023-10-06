--- chrome/browser/prefs/browser_prefs.cc.orig	2023-08-10 01:48:35 UTC
+++ chrome/browser/prefs/browser_prefs.cc
@@ -465,13 +465,13 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "components/device_signals/core/browser/pref_names.h"  // nogncheck due to crbug.com/1125897
 #endif
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
 #include "chrome/browser/browser_switcher/browser_switcher_prefs.h"
 #endif
@@ -504,7 +504,7 @@
 #include "chrome/browser/sessions/session_service_log.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/color/system_theme.h"
 #endif
 
@@ -709,7 +709,7 @@ const char kPluginsPluginsList[] = "plugins.plugins_li
 const char kPluginsShowDetails[] = "plugins.show_details";
 
 // Deprecated 02/2023.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kWebAppsUrlHandlerInfo[] = "web_apps.url_handler_info";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -952,7 +952,7 @@ void RegisterLocalStatePrefsForMigration(PrefRegistryS
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
   // Deprecated 02/2023.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterDictionaryPref(kWebAppsUrlHandlerInfo);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -1103,7 +1103,7 @@ void RegisterProfilePrefsForMigration(
   registry->RegisterIntegerPref(kProfileAvatarTutorialShown, 0);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Deprecated 08/2022.
   registry->RegisterBooleanPref(prefs::kUsesSystemThemeDeprecated, false);
 #endif
@@ -1862,12 +1862,12 @@ void RegisterProfilePrefs(user_prefs::PrefRegistrySync
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   device_signals::RegisterProfilePrefs(registry);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   browser_switcher::BrowserSwitcherPrefs::RegisterProfilePrefs(registry);
 #endif
 
@@ -2020,7 +2020,7 @@ void MigrateObsoleteLocalStatePrefs(PrefService* local
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
   // Added 02/2023
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   local_state->ClearPref(kWebAppsUrlHandlerInfo);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -2185,7 +2185,7 @@ void MigrateObsoleteProfilePrefs(Profile* profile) {
   profile_prefs->ClearPref(kProfileAvatarTutorialShown);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Added 08/2022.
   if (profile_prefs->HasPrefPath(prefs::kUsesSystemThemeDeprecated)) {
     auto migrated_theme =
