--- chrome/browser/web_applications/pending_app_install_task.cc.orig	2021-07-15 19:13:34 UTC
+++ chrome/browser/web_applications/pending_app_install_task.cc
@@ -311,7 +311,7 @@ void PendingAppInstallTask::OnWebAppInstalled(bool is_
   options.os_hooks[OsHookType::kProtocolHandlers] = true;
   options.os_hooks[OsHookType::kUninstallationViaOsSettings] = true;
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   options.os_hooks[OsHookType::kUrlHandlers] = true;
 #else
   options.os_hooks[OsHookType::kUrlHandlers] = false;
