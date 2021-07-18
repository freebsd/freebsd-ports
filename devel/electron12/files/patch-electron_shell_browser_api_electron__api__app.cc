--- electron/shell/browser/api/electron_api_app.cc.orig	2021-04-20 23:32:33 UTC
+++ electron/shell/browser/api/electron_api_app.cc
@@ -655,7 +655,7 @@ void App::OnWillFinishLaunching() {
 }
 
 void App::OnFinishLaunching(const base::DictionaryValue& launch_info) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Set the application name for audio streams shown in external
   // applications. Only affects pulseaudio currently.
   media::AudioManager::SetGlobalAppName(Browser::Get()->GetName());
@@ -1005,7 +1005,7 @@ void App::SetPath(gin_helper::ErrorThrower thrower,
 }
 
 void App::SetDesktopName(const std::string& desktop_name) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   env->SetVar("CHROME_DESKTOP", desktop_name);
 #endif
@@ -1358,7 +1358,7 @@ std::vector<gin_helper::Dictionary> App::GetAppMetrics
       pid_dict.Set("name", process_metric.second->name);
     }
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
     auto memory_info = process_metric.second->GetMemoryInfo();
 
     gin_helper::Dictionary memory_dict = gin::Dictionary::CreateEmpty(isolate);
@@ -1571,7 +1571,7 @@ gin::ObjectTemplateBuilder App::GetObjectTemplateBuild
       .SetMethod(
           "removeAsDefaultProtocolClient",
           base::BindRepeating(&Browser::RemoveAsDefaultProtocolClient, browser))
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
       .SetMethod(
           "getApplicationInfoForProtocol",
           base::BindRepeating(&Browser::GetApplicationInfoForProtocol, browser))
@@ -1628,7 +1628,7 @@ gin::ObjectTemplateBuilder App::GetObjectTemplateBuild
       .SetMethod("getJumpListSettings", &App::GetJumpListSettings)
       .SetMethod("setJumpList", &App::SetJumpList)
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       .SetMethod("isUnityRunning",
                  base::BindRepeating(&Browser::IsUnityRunning, browser))
 #endif
