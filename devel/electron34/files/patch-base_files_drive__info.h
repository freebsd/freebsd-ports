--- base/files/drive_info.h.orig	2025-01-27 17:37:37 UTC
+++ base/files/drive_info.h
@@ -40,7 +40,7 @@ class BASE_EXPORT DriveInfo {
   std::optional<bool> has_seek_penalty;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Whether the drive is a removable drive.
   //
   // Note on macOS: that SSDs that are connected over USB that you can eject
