--- content/shell/browser/shell_browser_context.cc.orig	2021-07-15 19:13:39 UTC
+++ content/shell/browser/shell_browser_context.cc
@@ -32,7 +32,7 @@
 
 #if defined(OS_WIN)
 #include "base/base_paths_win.h"
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/nix/xdg_util.h"
 #elif defined(OS_MAC)
 #include "base/base_paths_mac.h"
@@ -105,7 +105,7 @@ void ShellBrowserContext::InitWhileIOAllowed() {
 #if defined(OS_WIN)
   CHECK(base::PathService::Get(base::DIR_LOCAL_APP_DATA, &path_));
   path_ = path_.Append(std::wstring(L"content_shell"));
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   base::FilePath config_dir(
       base::nix::GetXDGDirectory(env.get(),
