--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2022-05-25 04:00:48 UTC
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc
@@ -400,7 +400,7 @@ void ChromeBrowserMainExtraPartsProfiles::
 #endif
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   metrics::DesktopProfileSessionDurationsServiceFactory::GetInstance();
 #endif
