--- chrome/browser/file_system_access/chrome_file_system_access_permission_context.cc.orig	2023-10-19 19:58:04 UTC
+++ chrome/browser/file_system_access/chrome_file_system_access_permission_context.cc
@@ -314,7 +314,7 @@ const struct {
      FILE_PATH_LITERAL("Library/Mobile Documents/com~apple~CloudDocs"),
      kDontBlockChildren},
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // On Linux also block access to devices via /dev.
     {kNoBasePathKey, FILE_PATH_LITERAL("/dev"), kBlockAllChildren},
     // And security sensitive data in /proc and /sys.
