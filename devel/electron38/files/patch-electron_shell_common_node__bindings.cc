--- electron/shell/common/node_bindings.cc.orig	2025-09-02 20:56:04 UTC
+++ electron/shell/common/node_bindings.cc
@@ -46,7 +46,7 @@
 #include "third_party/electron_node/src/debug_utils.h"
 #include "third_party/electron_node/src/module_wrap.h"
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
 #include "shell/common/crash_keys.h"
 #endif
 
@@ -161,7 +161,7 @@ void V8FatalErrorCallback(const char* location, const 
 void V8FatalErrorCallback(const char* location, const char* message) {
   LOG(ERROR) << "Fatal error in V8: " << location << " " << message;
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   electron::crash_keys::SetCrashKey("electron.v8-fatal.message", message);
   electron::crash_keys::SetCrashKey("electron.v8-fatal.location", location);
 #endif
@@ -183,7 +183,7 @@ void V8OOMErrorCallback(const char* location, const v8
     LOG(ERROR) << "OOM detail: " << details.detail;
   }
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   electron::crash_keys::SetCrashKey("electron.v8-oom.is_heap_oom",
                                     std::to_string(details.is_heap_oom));
   if (location) {
@@ -580,7 +580,7 @@ void NodeBindings::Initialize(v8::Isolate* const isola
   TRACE_EVENT0("electron", "NodeBindings::Initialize");
   // Open node's error reporting system for browser process.
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Get real command line in renderer process forked by zygote.
   if (browser_env_ != BrowserEnvironment::kBrowser)
     ElectronCommandLine::InitializeFromCommandLine();
