--- weblayer/shell/app/shell_main.cc.orig	2019-12-12 12:41:35 UTC
+++ weblayer/shell/app/shell_main.cc
@@ -18,7 +18,7 @@
 
 #if defined(OS_WIN)
 #include "base/base_paths_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "base/nix/xdg_util.h"
 #endif
 
@@ -65,7 +65,7 @@ class MainDelegateImpl : public weblayer::MainDelegate
 #if defined(OS_WIN)
     CHECK(base::PathService::Get(base::DIR_LOCAL_APP_DATA, &path));
     path = path.AppendASCII("web_shell");
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     std::unique_ptr<base::Environment> env(base::Environment::Create());
     base::FilePath config_dir(base::nix::GetXDGDirectory(
         env.get(), base::nix::kXdgConfigHomeEnvVar, base::nix::kDotConfigDir));
