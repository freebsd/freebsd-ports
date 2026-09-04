--- electron/shell/browser/electron_browser_main_parts.h.orig	2026-09-04 00:15:46 UTC
+++ electron/shell/browser/electron_browser_main_parts.h
@@ -144,7 +144,7 @@ class ElectronBrowserMainParts : public content::Brows
   std::unique_ptr<display::Screen> screen_;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void JoinSystemFontConfigInit();
 
   base::PlatformThreadHandle system_fontconfig_thread_;
