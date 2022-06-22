--- ui/base/cursor/cursor_factory.cc.orig	2022-05-19 05:18:01 UTC
+++ ui/base/cursor/cursor_factory.cc
@@ -82,7 +82,7 @@ void CursorFactory::ObserveThemeChanges() {
 
 void CursorFactory::SetDeviceScaleFactor(float scale) {}
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 // Returns a cursor name compatible with either X11 or the FreeDesktop.org
 // cursor spec ([1] and [2]), followed by fallbacks that can work as
