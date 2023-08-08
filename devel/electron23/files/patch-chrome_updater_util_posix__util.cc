--- chrome/updater/util/posix_util.cc.orig	2023-02-01 18:43:15 UTC
+++ chrome/updater/util/posix_util.cc
@@ -10,7 +10,7 @@
 #include "chrome/updater/updater_branding.h"
 #include "chrome/updater/util/util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/updater/util/linux_util.h"
 #endif
 
@@ -42,7 +42,7 @@ base::FilePath GetUpdaterFolderName() {
 
 absl::optional<base::FilePath> GetBaseInstallDirectory(UpdaterScope scope) {
   absl::optional<base::FilePath> path;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   path = GetApplicationDataDirectory(scope);
 #elif BUILDFLAG(IS_MAC)
   path = GetLibraryFolderPath(scope);
