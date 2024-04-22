--- chrome/browser/web_applications/commands/install_app_locally_command.cc.orig	2023-08-10 01:48:37 UTC
+++ chrome/browser/web_applications/commands/install_app_locally_command.cc
@@ -80,7 +80,7 @@ void InstallAppLocallyCommand::StartWithLock(
   options.os_hooks[OsHookType::kUninstallationViaOsSettings] =
       web_app->CanUserUninstallWebApp();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
   options.os_hooks[web_app::OsHookType::kUrlHandlers] = true;
 #else
