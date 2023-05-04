--- weblayer/common/weblayer_paths.cc.orig	2022-03-25 21:59:56 UTC
+++ weblayer/common/weblayer_paths.cc
@@ -18,7 +18,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include "base/base_paths_win.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #endif
 
@@ -36,7 +36,7 @@ bool GetDefaultUserDataDirectory(base::FilePath* resul
     return false;
   *result = result->AppendASCII("weblayer");
   return true;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   base::FilePath config_dir(base::nix::GetXDGDirectory(
       env.get(), base::nix::kXdgConfigHomeEnvVar, base::nix::kDotConfigDir));
