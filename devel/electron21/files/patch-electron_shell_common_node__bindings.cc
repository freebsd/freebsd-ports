--- electron/shell/common/node_bindings.cc.orig	2022-08-17 15:33:00 UTC
+++ electron/shell/common/node_bindings.cc
@@ -38,7 +38,7 @@
 #include "shell/common/node_includes.h"
 #include "third_party/blink/renderer/bindings/core/v8/v8_initializer.h"  // nogncheck
 
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !defined(OS_BSD)
 #include "shell/common/crash_keys.h"
 #endif
 
@@ -143,7 +143,7 @@ bool g_is_initialized = false;
 void V8FatalErrorCallback(const char* location, const char* message) {
   LOG(ERROR) << "Fatal error in V8: " << location << " " << message;
 
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !defined(OS_BSD)
   electron::crash_keys::SetCrashKey("electron.v8-fatal.message", message);
   electron::crash_keys::SetCrashKey("electron.v8-fatal.location", location);
 #endif
@@ -370,7 +370,7 @@ void NodeBindings::Initialize() {
   TRACE_EVENT0("electron", "NodeBindings::Initialize");
   // Open node's error reporting system for browser process.
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Get real command line in renderer process forked by zygote.
   if (browser_env_ != BrowserEnvironment::kBrowser)
     ElectronCommandLine::InitializeFromCommandLine();
