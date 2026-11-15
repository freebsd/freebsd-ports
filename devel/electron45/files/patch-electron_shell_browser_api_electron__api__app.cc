--- electron/shell/browser/api/electron_api_app.cc.orig	2026-10-26 21:12:45 UTC
+++ electron/shell/browser/api/electron_api_app.cc
@@ -120,7 +120,7 @@
 #include "ui/base/resource/resource_bundle.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/scoped_xdg_activation_token_injector.h"
 #include "base/nix/xdg_util.h"
 #endif
@@ -448,7 +448,7 @@ bool NotificationCallbackWrapper(
     base::CommandLine cmd,
     const base::FilePath& cwd,
     std::vector<uint8_t> additional_data) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the global activation token sent as a command line switch by another
   // electron app instance. This also removes the switch after use to prevent
   // any side effects of leaving it in the command line after this point.
@@ -630,7 +630,7 @@ void App::OnFinishLaunching(base::DictValue launch_inf
 }
 
 void App::OnFinishLaunching(base::DictValue launch_info) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the application name for audio streams shown in external
   // applications. Only affects pulseaudio currently.
   media::AudioManager::SetGlobalAppName(Browser::Get()->GetName());
@@ -1022,7 +1022,7 @@ void App::SetDesktopName(const std::string& desktop_na
 }
 
 void App::SetDesktopName(const std::string& desktop_name) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto env = base::Environment::Create();
   env->SetVar("CHROME_DESKTOP", desktop_name);
   // The Linux application name, and so the user agent, comes from this file.
@@ -1132,7 +1132,7 @@ bool App::RequestSingleInstanceLock(gin::Arguments* ar
       base::BindRepeating(NotificationCallbackWrapper, cb));
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Read the xdg-activation token and set it in the command line for the
   // duration of the notification in order to ensure this is propagated to an
   // already running electron app instance if it exists.
@@ -2259,7 +2259,7 @@ void Initialize(v8::Local<v8::Object> exports,
         context, electron::GetEventEmitterPrototype(isolate));
   }
   dict.Set("app", app);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // For desktop-name.spec.
   dict.SetMethod(
       "defaultDesktopName",
