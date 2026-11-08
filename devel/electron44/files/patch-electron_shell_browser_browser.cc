--- electron/shell/browser/browser.cc.orig	2026-08-31 00:54:38 UTC
+++ electron/shell/browser/browser.cc
@@ -105,7 +105,7 @@ bool Browser::IsValidProtocolScheme(const std::string&
   return true;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void Browser::Focus(gin::Arguments* args) {
   // Focus on the first visible window.
   for (auto* const window : WindowList::GetWindows()) {
