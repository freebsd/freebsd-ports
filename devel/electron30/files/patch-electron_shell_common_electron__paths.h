--- electron/shell/common/electron_paths.h.orig	2022-08-03 15:31:32 UTC
+++ electron/shell/common/electron_paths.h
@@ -30,7 +30,7 @@ enum {
   DIR_RECENT,  // Directory where recent files live
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DIR_APP_DATA,  // Application Data directory under the user profile.
 #endif
 
