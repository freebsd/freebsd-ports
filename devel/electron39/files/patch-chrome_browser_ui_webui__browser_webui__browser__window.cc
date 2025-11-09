--- chrome/browser/ui/webui_browser/webui_browser_window.cc.orig	2025-10-21 20:19:54 UTC
+++ chrome/browser/ui/webui_browser/webui_browser_window.cc
@@ -54,7 +54,7 @@ bool IsUsingLinuxSystemTheme(Profile* profile) {
 
 // Copied from chrome/browser/ui/views/frame/browser_widget.cc.
 bool IsUsingLinuxSystemTheme(Profile* profile) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
