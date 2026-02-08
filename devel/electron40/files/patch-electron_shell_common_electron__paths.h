--- electron/shell/common/electron_paths.h.orig	2026-02-04 19:30:54 UTC
+++ electron/shell/common/electron_paths.h
@@ -31,7 +31,7 @@ enum {
   DIR_RECENT,  // Directory where recent files live
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DIR_APP_DATA,  // Application Data directory under the user profile.
 #endif
 
