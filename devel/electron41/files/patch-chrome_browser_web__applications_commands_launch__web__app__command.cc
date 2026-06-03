--- chrome/browser/web_applications/commands/launch_web_app_command.cc.orig	2026-03-13 16:54:03 UTC
+++ chrome/browser/web_applications/commands/launch_web_app_command.cc
@@ -104,7 +104,7 @@ void LaunchWebAppCommand::StartWithLock(std::unique_pt
     // OsIntegrationTestOverride can use the xdg install command to detect
     // install.
     SynchronizeOsOptions options;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     options.add_shortcut_to_desktop = true;
 #endif
     lock_->os_integration_manager().Synchronize(
