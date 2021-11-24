--- chrome/browser/sessions/session_restore.cc.orig	2021-07-15 19:13:34 UTC
+++ chrome/browser/sessions/session_restore.cc
@@ -958,7 +958,7 @@ void SessionRestore::RestoreSessionAfterCrash(Browser*
 // On linux, apps can be restored without the proper app frame,
 // disabling restorations on linux for now. http://crbug.com/1199109
 #if BUILDFLAG(ENABLE_APP_SESSION_SERVICE)
-#if !defined(OS_MAC) && !defined(OS_LINUX)
+#if !defined(OS_MAC) && !defined(OS_LINUX) && !defined(OS_BSD)
   // Apps should always be restored on crash restore.
   behavior |= SessionRestore::RESTORE_APPS;
 #endif
