--- chrome/updater/installer.cc.orig	2022-05-19 05:17:39 UTC
+++ chrome/updater/installer.cc
@@ -225,7 +225,7 @@ absl::optional<base::FilePath> Installer::GetCurrentIn
   return path->AppendASCII(pv_.GetString());
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 Installer::Result Installer::RunApplicationInstaller(
     const base::FilePath& /*app_installer*/,
     const std::string& /*arguments*/,
