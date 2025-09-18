--- chrome/browser/prefs/browser_prefs.cc.orig	2025-08-26 20:49:50 UTC
+++ chrome/browser/prefs/browser_prefs.cc
@@ -326,7 +326,7 @@
 #include "chrome/browser/devtools/devtools_window.h"
 #endif  // BUILDFLAG(ENABLE_DEVTOOLS_FRONTEND)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/whats_new/whats_new_ui.h"
 #endif
 
@@ -493,11 +493,11 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/device_signals/core/browser/pref_names.h"  // nogncheck due to crbug.com/1125897
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_switcher/browser_switcher_prefs.h"
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
 #endif
@@ -525,7 +525,7 @@
 #include "chrome/browser/sessions/session_service_log.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/color/system_theme.h"
 #endif
 
@@ -1705,7 +1705,7 @@ void RegisterLocalState(PrefRegistrySimple* registry) 
   on_device_translation::RegisterLocalStatePrefs(registry);
 #endif  // BUILDFLAG(ENABLE_ON_DEVICE_TRANSLATION)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   WhatsNewUI::RegisterLocalStatePrefs(registry);
 #endif
 
@@ -1860,7 +1860,7 @@ void RegisterLocalState(PrefRegistrySimple* registry) 
 #endif  // BUILDFLAG(ENABLE_PDF)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kChromeForTestingAllowed, true);
 #endif
 
@@ -2231,12 +2231,12 @@ void RegisterProfilePrefs(user_prefs::PrefRegistrySync
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   device_signals::RegisterProfilePrefs(registry);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   browser_switcher::BrowserSwitcherPrefs::RegisterProfilePrefs(registry);
   enterprise_signin::RegisterProfilePrefs(registry);
 #endif
