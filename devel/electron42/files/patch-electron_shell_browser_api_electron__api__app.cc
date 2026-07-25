--- electron/shell/browser/api/electron_api_app.cc.orig	2026-07-21 15:08:10 UTC
+++ electron/shell/browser/api/electron_api_app.cc
@@ -109,7 +109,7 @@
 #include "ui/base/resource/resource_bundle.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/scoped_xdg_activation_token_injector.h"
 #include "base/nix/xdg_util.h"
 #endif
@@ -437,7 +437,7 @@ bool NotificationCallbackWrapper(
     base::CommandLine cmd,
     const base::FilePath& cwd,
     const std::vector<uint8_t> additional_data) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the global activation token sent as a command line switch by another
   // electron app instance. This also removes the switch after use to prevent
   // any side effects of leaving it in the command line after this point.
@@ -622,7 +622,7 @@ void App::OnFinishLaunching(base::DictValue launch_inf
 }
 
 void App::OnFinishLaunching(base::DictValue launch_info) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the application name for audio streams shown in external
   // applications. Only affects pulseaudio currently.
   media::AudioManager::SetGlobalAppName(Browser::Get()->GetName());
@@ -971,7 +971,7 @@ void App::SetDesktopName(const std::string& desktop_na
 }
 
 void App::SetDesktopName(const std::string& desktop_name) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto env = base::Environment::Create();
   env->SetVar("CHROME_DESKTOP", desktop_name);
 #endif
@@ -1073,7 +1073,7 @@ bool App::RequestSingleInstanceLock(gin::Arguments* ar
       base::BindRepeating(NotificationCallbackWrapper, cb));
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Read the xdg-activation token and set it in the command line for the
   // duration of the notification in order to ensure this is propagated to an
   // already running electron app instance if it exists.
@@ -1468,7 +1468,7 @@ std::vector<gin_helper::Dictionary> App::GetAppMetrics
       pid_dict.Set("name", process_metric.second->name);
     }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     auto memory_info = process_metric.second->GetMemoryInfo();
 
     auto memory_dict = gin_helper::Dictionary::CreateEmpty(isolate);
@@ -1974,7 +1974,7 @@ gin::ObjectTemplateBuilder App::GetObjectTemplateBuild
       .SetMethod("getJumpListSettings", &App::GetJumpListSettings)
       .SetMethod("setJumpList", &App::SetJumpList)
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       .SetMethod("isUnityRunning",
                  base::BindRepeating(&Browser::IsUnityRunning, browser))
 #endif
