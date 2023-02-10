--- chrome/browser/content_settings/chrome_content_settings_utils.cc.orig	2022-11-30 08:12:58 UTC
+++ chrome/browser/content_settings/chrome_content_settings_utils.cc
@@ -44,7 +44,7 @@ void UpdateLocationBarUiForWebContents(content::WebCon
     location_bar->UpdateContentSettingsIcons();
 
 // TODO(https://crbug.com/1346734): Enable this on all platforms.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The document PiP window does not have a location bar, but has some content
   // setting views that need to be updated too.
   if (browser->is_type_picture_in_picture()) {
