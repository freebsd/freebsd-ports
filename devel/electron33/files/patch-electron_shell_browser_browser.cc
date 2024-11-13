--- electron/shell/browser/browser.cc.orig	2024-10-22 02:29:46 UTC
+++ electron/shell/browser/browser.cc
@@ -72,7 +72,7 @@ Browser* Browser::Get() {
   return ElectronBrowserMainParts::Get()->browser();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void Browser::Focus(gin::Arguments* args) {
   // Focus on the first visible window.
   for (auto* const window : WindowList::GetWindows()) {
