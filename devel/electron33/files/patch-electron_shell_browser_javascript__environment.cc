--- electron/shell/browser/javascript_environment.cc.orig	2025-03-05 11:51:09 UTC
+++ electron/shell/browser/javascript_environment.cc
@@ -93,7 +93,7 @@ v8::Isolate* JavascriptEnvironment::Initialize(uv_loop
   auto* cmd = base::CommandLine::ForCurrentProcess();
   // --js-flags.
   std::string js_flags = "--no-freeze-flags-after-init ";
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // See https://issues.chromium.org/issues/378017037 - fixed in M134.
   js_flags.append("--nodecommit_pooled_pages ");
 #endif
