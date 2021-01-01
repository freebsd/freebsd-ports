--- chrome/browser/ui/browser_view_prefs.cc.orig	2019-12-12 12:39:16 UTC
+++ chrome/browser/ui/browser_view_prefs.cc
@@ -34,7 +34,7 @@ void RegisterBrowserViewLocalPrefs(PrefRegistrySimple*
 
 void RegisterBrowserViewProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   bool custom_frame_pref_default = false;
 #if defined(USE_X11)
   custom_frame_pref_default = ui::GetCustomFramePrefDefault();
@@ -45,7 +45,7 @@ void RegisterBrowserViewProfilePrefs(
 #endif
   registry->RegisterBooleanPref(prefs::kUseCustomChromeFrame,
                                 custom_frame_pref_default);
-#endif  // OS_LINUX && !OS_CHROMEOS
+#endif  // (OS_LINUX && !OS_CHROMEOS) || defined(OS_BSD)
 }
 
 void MigrateBrowserTabStripPrefs(PrefService* prefs) {
