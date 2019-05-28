--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2019-03-15 06:37:04 UTC
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc
@@ -305,7 +305,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #if !defined(OS_ANDROID)
   MediaGalleriesPreferencesFactory::GetInstance();
 #endif
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
   metrics::DesktopProfileSessionDurationsServiceFactory::GetInstance();
 #endif
