--- electron/atom/browser/api/atom_api_app.cc.orig	2019-05-02 21:34:52 UTC
+++ electron/atom/browser/api/atom_api_app.cc
@@ -619,7 +619,7 @@ void App::OnWillFinishLaunching() {
 }
 
 void App::OnFinishLaunching(const base::DictionaryValue& launch_info) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Set the application name for audio streams shown in external
   // applications. Only affects pulseaudio currently.
   media::AudioManager::SetGlobalAppName(Browser::Get()->GetName());
@@ -871,7 +871,7 @@ void App::SetPath(mate::Arguments* args,
 }
 
 void App::SetDesktopName(const std::string& desktop_name) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   env->SetVar("CHROME_DESKTOP", desktop_name);
 #endif
@@ -1318,7 +1318,7 @@ void App::BuildPrototype(v8::Isolate* isolate,
       .SetMethod("getJumpListSettings", &App::GetJumpListSettings)
       .SetMethod("setJumpList", &App::SetJumpList)
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       .SetMethod("isUnityRunning",
                  base::Bind(&Browser::IsUnityRunning, browser))
 #endif
