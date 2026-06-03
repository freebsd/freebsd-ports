--- sql/database.cc.orig	2026-03-13 16:54:03 UTC
+++ sql/database.cc
@@ -111,7 +111,7 @@ bool FilePathIsFixedSSD(const base::FilePath& path) {
 
   return !drive_info->has_seek_penalty.value_or(false)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
          && !drive_info->is_removable.value_or(false)
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
