--- electron/shell/app/electron_main_delegate.cc.orig	2025-08-18 21:37:48 UTC
+++ electron/shell/app/electron_main_delegate.cc
@@ -63,13 +63,13 @@
 #include "chrome/child/v8_crashpad_support_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #include "v8/include/v8-wasm-trap-handler-posix.h"
 #include "v8/include/v8.h"
 #endif
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
 #include "components/crash/core/app/crash_switches.h"  // nogncheck
 #include "components/crash/core/app/crashpad.h"        // nogncheck
 #include "components/crash/core/common/crash_key.h"
@@ -160,7 +160,7 @@ bool ElectronPathProvider(int key, base::FilePath* res
       create_dir = true;
       break;
     }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case DIR_APP_DATA: {
       auto env = base::Environment::Create();
       cur = base::nix::GetXDGDirectory(
@@ -302,7 +302,7 @@ std::optional<int> ElectronMainDelegate::BasicStartupC
     base::win::PinUser32();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Check for --no-sandbox parameter when running as root.
   if (getuid() == 0 && IsSandboxEnabled(command_line))
     LOG(FATAL) << "Running as root without --"
@@ -352,7 +352,7 @@ void ElectronMainDelegate::PreSandboxStartup() {
       /* is_preinit = */ IsBrowserProcess() || IsZygoteProcess());
 #endif
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   crash_reporter::InitializeCrashKeys();
 #endif
 
@@ -387,7 +387,7 @@ void ElectronMainDelegate::PreSandboxStartup() {
   }
 #endif
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   crash_keys::SetCrashKeysFromCommandLine(*command_line);
   crash_keys::SetPlatformCrashKey();
 #endif
@@ -422,7 +422,7 @@ std::optional<int> ElectronMainDelegate::PreBrowserMai
 #if BUILDFLAG(IS_MAC)
   RegisterAtomCrApp();
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the global activation token sent as an environment variable.
   auto env = base::Environment::Create();
   base::nix::ExtractXdgActivationTokenFromEnv(*env);
