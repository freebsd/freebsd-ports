--- chrome/browser/ui/webui/side_panel/customize_chrome/customize_chrome_page_handler.h.orig	2025-08-26 20:49:50 UTC
+++ chrome/browser/ui/webui/side_panel/customize_chrome/customize_chrome_page_handler.h
@@ -206,7 +206,7 @@ class CustomizeChromePageHandler
   // value needs to be requeried by the page.
   GURL last_source_url_{GURL(chrome::kChromeUINewTabPageURL)};
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   PrefChangeRegistrar browser_pref_change_registrar_;
 #endif
   PrefChangeRegistrar pref_change_registrar_;
