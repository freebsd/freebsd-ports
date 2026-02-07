--- chrome/browser/file_system_access/chrome_file_system_access_permission_context.h.orig	2025-07-04 05:17:07 UTC
+++ chrome/browser/file_system_access/chrome_file_system_access_permission_context.h
@@ -454,7 +454,7 @@ class ChromeFileSystemAccessPermissionContext
         FILE_PATH_LITERAL("Library/Mobile Documents/com~apple~CloudDocs"),
         BlockType::kDontBlockChildren},
   #endif
-  #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+  #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
         // On Linux also block access to devices via /dev.
         {kNoBasePathKey, FILE_PATH_LITERAL("/dev"), BlockType::kBlockAllChildren},
         // And security sensitive data in /proc and /sys.
