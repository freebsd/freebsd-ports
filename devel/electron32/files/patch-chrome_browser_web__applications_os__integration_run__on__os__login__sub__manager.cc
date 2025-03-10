--- chrome/browser/web_applications/os_integration/run_on_os_login_sub_manager.cc.orig	2023-10-19 19:58:08 UTC
+++ chrome/browser/web_applications/os_integration/run_on_os_login_sub_manager.cc
@@ -54,7 +54,7 @@ proto::RunOnOsLoginMode ConvertWebAppRunOnOsLoginModeT
 // different from other platforms, see web_app_run_on_os_login_manager.h for
 // more info.
 bool DoesRunOnOsLoginRequireExecution() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(features::kDesktopPWAsRunOnOsLogin);
 #else
   return false;
