--- chrome/browser/extensions/api/enterprise_reporting_private/chrome_desktop_report_request_helper.cc.orig	2021-04-14 01:08:39 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/chrome_desktop_report_request_helper.cc
@@ -22,7 +22,7 @@
 #include "base/win/registry.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #endif
@@ -238,7 +238,7 @@ base::FilePath GetEndpointVerificationDir() {
     return *GetEndpointVerificationDirOverride();
 #if defined(OS_WIN)
   if (!base::PathService::Get(base::DIR_LOCAL_APP_DATA, &path))
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   path = base::nix::GetXDGDirectory(env.get(), base::nix::kXdgConfigHomeEnvVar,
                                     base::nix::kDotConfigDir);
@@ -249,7 +249,7 @@ base::FilePath GetEndpointVerificationDir() {
   if (true)
 #endif
     return path;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   path = path.AppendASCII("google");
 #else
   path = path.AppendASCII("Google");
