--- chrome/browser/extensions/api/enterprise_reporting_private/chrome_desktop_report_request_helper.cc.orig	2024-02-21 00:20:34 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/chrome_desktop_report_request_helper.cc
@@ -24,7 +24,7 @@
 #include "base/win/registry.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #endif
@@ -255,7 +255,7 @@ base::FilePath GetEndpointVerificationDir() {
   bool got_path = false;
 #if BUILDFLAG(IS_WIN)
   got_path = base::PathService::Get(base::DIR_LOCAL_APP_DATA, &path);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   path = base::nix::GetXDGDirectory(env.get(), base::nix::kXdgConfigHomeEnvVar,
                                     base::nix::kDotConfigDir);
@@ -266,7 +266,7 @@ base::FilePath GetEndpointVerificationDir() {
   if (!got_path)
     return path;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   path = path.AppendASCII("google");
 #else
   path = path.AppendASCII("Google");
