--- electron/shell/common/node_bindings.cc.orig	2026-05-08 13:54:01 UTC
+++ electron/shell/common/node_bindings.cc
@@ -53,7 +53,7 @@
 #include "third_party/electron_node/src/module_wrap.h"
 #include "v8/include/v8-statistics.h"
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
 #include "shell/common/crash_keys.h"
 #endif
 
@@ -170,7 +170,7 @@ void V8FatalErrorCallback(const char* location, const 
 void V8FatalErrorCallback(const char* location, const char* message) {
   LOG(ERROR) << "Fatal error in V8: " << location << " " << message;
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   electron::crash_keys::SetCrashKey("electron.v8-fatal.message", message);
   electron::crash_keys::SetCrashKey("electron.v8-fatal.location", location);
 #endif
@@ -192,7 +192,7 @@ void V8OOMErrorCallback(const char* location, const v8
     LOG(ERROR) << "OOM detail: " << details.detail;
   }
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   electron::crash_keys::SetCrashKey("electron.v8-oom.is_heap_oom",
                                     base::NumberToString(details.is_heap_oom));
   if (location) {
@@ -683,7 +683,7 @@ void NodeBindings::Initialize(v8::Isolate* const isola
   TRACE_EVENT0("electron", "NodeBindings::Initialize");
   // Open node's error reporting system for browser process.
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Get real command line in renderer process forked by zygote.
   if (browser_env_ != BrowserEnvironment::kBrowser)
     ElectronCommandLine::InitializeFromCommandLine();
