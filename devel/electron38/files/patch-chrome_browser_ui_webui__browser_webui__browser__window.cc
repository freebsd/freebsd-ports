--- chrome/browser/ui/webui_browser/webui_browser_window.cc.orig	2025-08-26 20:49:50 UTC
+++ chrome/browser/ui/webui_browser/webui_browser_window.cc
@@ -22,7 +22,7 @@ bool IsUsingLinuxSystemTheme(Profile* profile) {
 
 // Copied from chrome/browser/ui/views/frame/browser_frame.cc.
 bool IsUsingLinuxSystemTheme(Profile* profile) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
