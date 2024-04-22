--- content/shell/browser/shell_paths.cc.orig	2022-02-28 16:54:41 UTC
+++ content/shell/browser/shell_paths.cc
@@ -13,7 +13,7 @@
 
 #if BUILDFLAG(IS_FUCHSIA)
 #include "base/fuchsia/file_utils.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #endif
 
@@ -25,7 +25,7 @@ bool GetDefaultUserDataDirectory(base::FilePath* resul
 #if BUILDFLAG(IS_WIN)
   CHECK(base::PathService::Get(base::DIR_LOCAL_APP_DATA, result));
   *result = result->Append(std::wstring(L"content_shell"));
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   base::FilePath config_dir(base::nix::GetXDGDirectory(
       env.get(), base::nix::kXdgConfigHomeEnvVar, base::nix::kDotConfigDir));
