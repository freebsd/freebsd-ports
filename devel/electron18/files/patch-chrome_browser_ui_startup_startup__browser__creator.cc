--- chrome/browser/ui/startup/startup_browser_creator.cc.orig	2022-05-19 05:17:38 UTC
+++ chrome/browser/ui/startup/startup_browser_creator.cc
@@ -126,12 +126,12 @@
 #endif  // BUILDFLAG(ENABLE_PRINT_PREVIEW)
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
 #include "chrome/browser/ui/startup/web_app_url_handling_startup_utils.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/startup/web_app_info_recorder_utils.h"
 #endif
 
@@ -518,7 +518,7 @@ bool MaybeLaunchAppShortcutWindow(const base::CommandL
   return false;
 }
 
-#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
 bool MaybeLaunchUrlHandlerWebAppFromCmd(
     const base::CommandLine& command_line,
     const base::FilePath& cur_dir,
@@ -989,7 +989,7 @@ bool StartupBrowserCreator::ProcessCmdLineImpl(
     silent_launch = true;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Writes open and installed web apps to the specified file without
   // launching a new browser window or tab.
   if (base::FeatureList::IsEnabled(features::kListWebAppsSwitch) &&
@@ -1181,7 +1181,7 @@ bool StartupBrowserCreator::ProcessCmdLineImpl(
     CHECK_EQ(profile_info.mode, StartupProfileMode::kBrowserWindow)
         << "Failed launch with app: couldn't pick a profile";
     std::string app_id = command_line.GetSwitchValueASCII(switches::kAppId);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // If Chrome Apps are deprecated and |app_id| is a Chrome App, display the
     // deprecation UI instead of launching the app.
     if (apps::OpenDeprecatedApplicationPrompt(privacy_safe_profile, app_id))
@@ -1220,7 +1220,7 @@ bool StartupBrowserCreator::ProcessCmdLineImpl(
       web_app::startup::MaybeHandleWebAppLaunch(
           command_line, cur_dir, privacy_safe_profile, is_first_run);
 
-#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
   handled_as_app = handled_as_app ||
                    // Give web apps a chance to handle a URL.
                    MaybeLaunchUrlHandlerWebAppFromCmd(
