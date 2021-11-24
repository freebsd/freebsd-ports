--- content/renderer/render_process_impl.cc.orig	2021-07-15 19:13:39 UTC
+++ content/renderer/render_process_impl.cc
@@ -47,7 +47,7 @@
 #if defined(OS_WIN)
 #include "base/win/win_util.h"
 #endif
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
 #include "v8/include/v8-wasm-trap-handler-posix.h"
 #endif
 namespace {
@@ -197,7 +197,7 @@ RenderProcessImpl::RenderProcessImpl()
 
   SetV8FlagIfNotFeature(features::kWebAssemblyTrapHandler,
                         "--no-wasm-trap-handler");
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
   if (base::FeatureList::IsEnabled(features::kWebAssemblyTrapHandler)) {
     if (command_line->HasSwitch(switches::kEnableCrashpad) ||
         command_line->HasSwitch(switches::kEnableCrashReporter) ||
