--- electron/shell/common/electron_paths.h.orig	2022-05-11 15:32:29 UTC
+++ electron/shell/common/electron_paths.h
@@ -29,7 +29,7 @@ enum {
   DIR_RECENT,  // Directory where recent files live
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   DIR_APP_DATA,  // Application Data directory under the user profile.
 #endif
 
