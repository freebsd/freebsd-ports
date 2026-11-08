--- electron/shell/common/node_bindings.cc.orig	2026-09-08 07:41:45 UTC
+++ electron/shell/common/node_bindings.cc
@@ -57,7 +57,7 @@
 #include "third_party/electron_node/src/node_snapshot_builder.h"
 #include "v8/include/v8-statistics.h"
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
 #include "shell/common/crash_keys.h"
 #include "shell/common/v8_oom_diagnostics.h"
 #endif
@@ -175,7 +175,7 @@ void V8FatalErrorCallback(const char* location, const 
 void V8FatalErrorCallback(const char* location, const char* message) {
   LOG(ERROR) << "Fatal error in V8: " << location << " " << message;
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   electron::crash_keys::SetCrashKey("electron.v8-fatal.message", message);
   electron::crash_keys::SetCrashKey("electron.v8-fatal.location", location);
 #endif
@@ -197,7 +197,7 @@ void V8OOMErrorCallback(const char* location, const v8
     LOG(ERROR) << "OOM detail: " << details.detail;
   }
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   // TryGetCurrent() instead of GetCurrent() to avoid FATAL if no isolate.
   v8::Isolate* isolate = v8::Isolate::TryGetCurrent();
   electron::v8_oom::RecordErrorDetails(isolate, location, details);
@@ -651,7 +651,7 @@ void NodeBindings::Initialize(v8::Isolate* const isola
   TRACE_EVENT0("electron", "NodeBindings::Initialize");
   // Open node's error reporting system for browser process.
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Get real command line in renderer process forked by zygote.
   if (browser_env_ != BrowserEnvironment::kBrowser)
     ElectronCommandLine::InitializeFromCommandLine();
