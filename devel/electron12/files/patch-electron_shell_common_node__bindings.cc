--- electron/shell/common/node_bindings.cc.orig	2021-04-20 23:32:33 UTC
+++ electron/shell/common/node_bindings.cc
@@ -35,7 +35,7 @@
 #include "shell/common/node_includes.h"
 #include "third_party/blink/renderer/bindings/core/v8/v8_initializer.h"  // nogncheck
 
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !defined(OS_BSD)
 #include "shell/common/crash_keys.h"
 #endif
 
@@ -146,7 +146,7 @@ bool IsPackagedApp() {
 void V8FatalErrorCallback(const char* location, const char* message) {
   LOG(ERROR) << "Fatal error in V8: " << location << " " << message;
 
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !defined(OS_BSD)
   electron::crash_keys::SetCrashKey("electron.v8-fatal.message", message);
   electron::crash_keys::SetCrashKey("electron.v8-fatal.location", location);
 #endif
@@ -351,7 +351,7 @@ void NodeBindings::Initialize() {
   // Open node's error reporting system for browser process.
   node::g_upstream_node_mode = false;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Get real command line in renderer process forked by zygote.
   if (browser_env_ != BrowserEnvironment::kBrowser)
     ElectronCommandLine::InitializeFromCommandLine();
