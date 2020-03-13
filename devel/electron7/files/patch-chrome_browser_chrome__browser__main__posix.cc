--- chrome/browser/chrome_browser_main_posix.cc.orig	2019-12-12 12:39:08 UTC
+++ chrome/browser/chrome_browser_main_posix.cc
@@ -70,7 +70,7 @@ void ExitHandler::ExitWhenPossibleOnUIThread(int signa
     // ExitHandler takes care of deleting itself.
     new ExitHandler();
   } else {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
     switch (signal) {
       case SIGINT:
       case SIGHUP:
@@ -166,7 +166,7 @@ void ChromeBrowserMainPartsPosix::PostMainMessageLoopS
 void ChromeBrowserMainPartsPosix::ShowMissingLocaleMessageBox() {
 #if defined(OS_CHROMEOS)
   NOTREACHED();  // Should not ever happen on ChromeOS.
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   // Not called on Mac because we load the locale files differently.
   NOTREACHED();
 #elif defined(USE_AURA)
