--- chrome/browser/ui/webui_browser/webui_browser_window.cc.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/ui/webui_browser/webui_browser_window.cc
@@ -59,7 +59,7 @@ bool IsUsingLinuxSystemTheme(Profile* profile) {
 
 // Copied from chrome/browser/ui/views/frame/browser_widget.cc.
 bool IsUsingLinuxSystemTheme(Profile* profile) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
