--- electron/atom/browser/api/atom_api_app.cc.orig	2019-04-04 16:09:31 UTC
+++ electron/atom/browser/api/atom_api_app.cc
@@ -609,7 +609,7 @@ void App::OnWillFinishLaunching() {
 }
 
 void App::OnFinishLaunching(const base::DictionaryValue& launch_info) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Set the application name for audio streams shown in external
   // applications. Only affects pulseaudio currently.
   media::AudioManager::SetGlobalAppName(Browser::Get()->GetName());
@@ -864,7 +864,7 @@ void App::SetPath(mate::Arguments* args,
 }
 
 void App::SetDesktopName(const std::string& desktop_name) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   env->SetVar("CHROME_DESKTOP", desktop_name);
 #endif
@@ -1313,7 +1313,7 @@ void App::BuildPrototype(v8::Isolate* isolate,
       .SetMethod("moveToApplicationsFolder", &App::MoveToApplicationsFolder)
       .SetMethod("isInApplicationsFolder", &App::IsInApplicationsFolder)
 #endif
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
       .SetMethod("setAboutPanelOptions",
                  base::Bind(&Browser::SetAboutPanelOptions, browser))
       .SetMethod("showAboutPanel",
@@ -1324,7 +1324,7 @@ void App::BuildPrototype(v8::Isolate* isolate,
       .SetMethod("getJumpListSettings", &App::GetJumpListSettings)
       .SetMethod("setJumpList", &App::SetJumpList)
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       .SetMethod("isUnityRunning",
                  base::Bind(&Browser::IsUnityRunning, browser))
 #endif
