--- chrome/browser/chrome_browser_main_posix.cc.orig	2019-03-15 06:37:01 UTC
+++ chrome/browser/chrome_browser_main_posix.cc
@@ -139,7 +139,7 @@ void ChromeBrowserMainPartsPosix::PostMainMessageLoopS
 void ChromeBrowserMainPartsPosix::ShowMissingLocaleMessageBox() {
 #if defined(OS_CHROMEOS)
   NOTREACHED();  // Should not ever happen on ChromeOS.
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   // Not called on Mac because we load the locale files differently.
   NOTREACHED();
 #elif defined(USE_AURA)
