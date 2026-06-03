--- chrome/browser/web_applications/commands/launch_web_app_command.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/web_applications/commands/launch_web_app_command.cc
@@ -101,7 +101,7 @@ void LaunchWebAppCommand::StartWithLock(std::unique_pt
     // OsIntegrationTestOverride can use the xdg install command to detect
     // install.
     SynchronizeOsOptions options;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     options.add_shortcut_to_desktop = true;
 #endif
     lock_->os_integration_manager().Synchronize(
