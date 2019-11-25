--- electron/atom/browser/atom_paths.h.orig	2019-09-11 17:30:11 UTC
+++ electron/atom/browser/atom_paths.h
@@ -26,7 +26,7 @@ enum {
   DIR_USER_CACHE,              // Directory where user cache can be written.
   DIR_APP_LOGS,                // Directory where app logs live
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   DIR_APP_DATA,  // Application Data directory under the user profile.
 #else
   DIR_APP_DATA = base::DIR_APP_DATA,
