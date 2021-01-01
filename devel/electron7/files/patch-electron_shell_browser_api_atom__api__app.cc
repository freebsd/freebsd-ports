--- electron/shell/browser/api/atom_api_app.cc.orig	2019-12-13 19:48:14 UTC
+++ electron/shell/browser/api/atom_api_app.cc
@@ -599,7 +599,7 @@ void App::OnWillFinishLaunching() {
 }
 
 void App::OnFinishLaunching(const base::DictionaryValue& launch_info) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Set the application name for audio streams shown in external
   // applications. Only affects pulseaudio currently.
   media::AudioManager::SetGlobalAppName(Browser::Get()->GetName());
@@ -877,7 +877,7 @@ void App::SetPath(mate::Arguments* args,
 }
 
 void App::SetDesktopName(const std::string& desktop_name) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   env->SetVar("CHROME_DESKTOP", desktop_name);
 #endif
@@ -1201,7 +1201,7 @@ std::vector<mate::Dictionary> App::GetAppMetrics(v8::I
     pid_dict.Set("creationTime",
                  process_metric.second->process.CreationTime().ToJsTime());
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
     auto memory_info = process_metric.second->GetMemoryInfo();
 
     mate::Dictionary memory_dict = mate::Dictionary::CreateEmpty(isolate);
@@ -1438,7 +1438,7 @@ void App::BuildPrototype(v8::Isolate* isolate,
       .SetMethod("moveToApplicationsFolder", &App::MoveToApplicationsFolder)
       .SetMethod("isInApplicationsFolder", &App::IsInApplicationsFolder)
 #endif
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
       .SetMethod("setAboutPanelOptions",
                  base::BindRepeating(&Browser::SetAboutPanelOptions, browser))
       .SetMethod("showAboutPanel",
@@ -1457,7 +1457,7 @@ void App::BuildPrototype(v8::Isolate* isolate,
       .SetMethod("getJumpListSettings", &App::GetJumpListSettings)
       .SetMethod("setJumpList", &App::SetJumpList)
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       .SetMethod("isUnityRunning",
                  base::BindRepeating(&Browser::IsUnityRunning, browser))
 #endif
