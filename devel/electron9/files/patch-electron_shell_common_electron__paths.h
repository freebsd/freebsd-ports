--- electron/shell/common/electron_paths.h.orig	2020-05-28 05:02:39 UTC
+++ electron/shell/common/electron_paths.h
@@ -26,7 +26,7 @@ enum {
   DIR_USER_CACHE,              // Directory where user cache can be written.
   DIR_APP_LOGS,                // Directory where app logs live
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   DIR_APP_DATA,  // Application Data directory under the user profile.
 #endif
 
@@ -34,7 +34,7 @@ enum {
 
   PATH_END,  // End of new paths. Those that follow redirect to base::DIR_*
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
   DIR_APP_DATA = base::DIR_APP_DATA,
 #endif
 
