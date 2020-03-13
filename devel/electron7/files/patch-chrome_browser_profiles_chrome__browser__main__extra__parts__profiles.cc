--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2019-12-12 12:39:12 UTC
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc
@@ -181,7 +181,7 @@
 #include "chrome/browser/safe_browsing/advanced_protection_status_manager_factory.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/sync/sync_clipboard_service_factory.h"
 #endif
 
@@ -336,7 +336,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   MediaGalleriesPreferencesFactory::GetInstance();
 #endif
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   metrics::DesktopProfileSessionDurationsServiceFactory::GetInstance();
 #endif
   ModelTypeStoreServiceFactory::GetInstance();
@@ -398,7 +398,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   SpellcheckServiceFactory::GetInstance();
 #endif
   suggestions::SuggestionsServiceFactory::GetInstance();
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   SyncClipboardServiceFactory::GetInstance();
 #endif
   TabRestoreServiceFactory::GetInstance();
