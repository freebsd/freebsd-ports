--- electron/shell/browser/atom_paths.h.orig	2019-12-13 19:48:14 UTC
+++ electron/shell/browser/atom_paths.h
@@ -26,13 +26,13 @@ enum {
   DIR_USER_CACHE,              // Directory where user cache can be written.
   DIR_APP_LOGS,                // Directory where app logs live
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   DIR_APP_DATA,  // Application Data directory under the user profile.
 #endif
 
   PATH_END,  // End of new paths. Those that follow redirect to base::DIR_*
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
   DIR_APP_DATA = base::DIR_APP_DATA,
 #endif
 
