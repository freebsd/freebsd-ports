--- chrome/browser/file_system_access/chrome_file_system_access_permission_context.h.orig	2026-11-01 04:41:00 UTC
+++ chrome/browser/file_system_access/chrome_file_system_access_permission_context.h
@@ -683,7 +683,7 @@ class ChromeFileSystemAccessPermissionContext
             FILE_PATH_LITERAL("Library/Mobile Documents/com~apple~CloudDocs"),
             BlockType::kDontBlockChildren),
   #endif
-  #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+  #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
         // On Linux also block access to devices via /dev.
         BlockPath::CreateAbsolute(FILE_PATH_LITERAL("/dev"),
                                   BlockType::kBlockAllChildren),
