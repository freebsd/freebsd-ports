--- chrome/common/chrome_paths_internal.h.orig	2025-04-22 20:15:27 UTC
+++ chrome/common/chrome_paths_internal.h
@@ -53,7 +53,7 @@ bool GetUserDocumentsDirectory(base::FilePath* result)
 // Get the path to the user's documents directory.
 bool GetUserDocumentsDirectory(base::FilePath* result);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Gets the path to a safe default download directory for a user.
 bool GetUserDownloadsDirectorySafe(base::FilePath* result);
 #endif
