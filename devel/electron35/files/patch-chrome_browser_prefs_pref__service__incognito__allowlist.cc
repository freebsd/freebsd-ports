--- chrome/browser/prefs/pref_service_incognito_allowlist.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/prefs/pref_service_incognito_allowlist.cc
@@ -204,7 +204,7 @@ const char* const kPersistentPrefNames[] = {
     prefs::kShowFullscreenToolbar,
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Toggleing custom frames affects all open windows in the profile, hence
     // should be written to the regular profile when changed in incognito mode.
     prefs::kUseCustomChromeFrame,
