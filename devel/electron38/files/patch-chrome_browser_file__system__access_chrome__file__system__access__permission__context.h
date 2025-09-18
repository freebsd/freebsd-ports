--- chrome/browser/file_system_access/chrome_file_system_access_permission_context.h.orig	2025-09-10 14:33:47 UTC
+++ chrome/browser/file_system_access/chrome_file_system_access_permission_context.h
@@ -519,7 +519,7 @@ class ChromeFileSystemAccessPermissionContext
             FILE_PATH_LITERAL("Library/Mobile Documents/com~apple~CloudDocs"),
             BlockType::kDontBlockChildren},
   #endif
-  #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+  #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
             // On Linux also block access to devices via /dev.
             {kNoBasePathKey, FILE_PATH_LITERAL("/dev"),
             BlockType::kBlockAllChildren},
