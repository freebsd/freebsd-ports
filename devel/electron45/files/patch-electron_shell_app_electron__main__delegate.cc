--- electron/shell/app/electron_main_delegate.cc.orig	2026-10-26 21:12:45 UTC
+++ electron/shell/app/electron_main_delegate.cc
@@ -65,7 +65,7 @@
 #include "chrome/child/v8_crashpad_support_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #include "ui/linux/display_server_utils.h"
 #include "v8/include/v8-wasm-trap-handler-posix.h"
@@ -76,7 +76,7 @@
 #include "ui/ozone/public/ozone_platform.h"
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
 #include "components/crash/core/app/crash_switches.h"  // nogncheck
 #include "components/crash/core/app/crashpad.h"        // nogncheck
 #include "components/crash/core/common/crash_key.h"
@@ -218,7 +218,7 @@ std::optional<int> ElectronMainDelegate::BasicStartupC
     base::win::PinUser32();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Check for --no-sandbox parameter when running as root.
   if (getuid() == 0 && IsSandboxEnabled(command_line))
     LOG(FATAL) << "Running as root without --"
@@ -268,7 +268,7 @@ void ElectronMainDelegate::PreSandboxStartup() {
       /* is_preinit = */ IsBrowserProcess() || IsZygoteProcess());
 #endif
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   crash_reporter::InitializeCrashKeys();
 #endif
 
@@ -310,7 +310,7 @@ void ElectronMainDelegate::PreSandboxStartup() {
   }
 #endif
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   crash_keys::SetCrashKeysFromCommandLine(*command_line);
   crash_keys::SetPlatformCrashKey();
 #endif
@@ -329,7 +329,7 @@ void ElectronMainDelegate::PreSandboxStartup() {
 #if BUILDFLAG(IS_OZONE)
     // Initialize Ozone platform and add required feature flags as per
     // platform's properties.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     ui::SetOzonePlatformForLinuxIfNeeded(*command_line);
 #endif
     ui::OzonePlatform::PreSandboxStartup();
@@ -362,7 +362,7 @@ std::optional<int> ElectronMainDelegate::PreBrowserMai
 #if BUILDFLAG(IS_MAC)
   RegisterAtomCrApp();
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the global activation token sent as an environment variable.
   auto env = base::Environment::Create();
   base::nix::ExtractXdgActivationTokenFromEnv(*env);
