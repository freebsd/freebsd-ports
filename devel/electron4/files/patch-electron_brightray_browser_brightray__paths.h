--- electron/brightray/browser/brightray_paths.h.orig	2019-03-16 11:54:53 UTC
+++ electron/brightray/browser/brightray_paths.h
@@ -24,7 +24,7 @@ enum {
   DIR_USER_CACHE,              // Directory where user cache can be written.
   DIR_APP_LOGS,                // Directory where app logs live
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   DIR_APP_DATA,  // Application Data directory under the user profile.
 #else
   DIR_APP_DATA = base::DIR_APP_DATA,
