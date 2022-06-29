--- chrome/updater/installer.cc.orig	2022-05-25 04:00:52 UTC
+++ chrome/updater/installer.cc
@@ -242,7 +242,7 @@ absl::optional<base::FilePath> Installer::GetCurrentIn
   return path->AppendASCII(pv_.GetString());
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 AppInstallerResult RunApplicationInstaller(
     const AppInfo& /*app_info*/,
