--- content/renderer/render_process_impl.cc.orig	2022-05-19 05:17:42 UTC
+++ content/renderer/render_process_impl.cc
@@ -47,7 +47,7 @@
 #if BUILDFLAG(IS_WIN)
 #include "base/win/win_util.h"
 #endif
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_X86_64)
 #include "v8/include/v8-wasm-trap-handler-posix.h"
 #endif
 
@@ -146,7 +146,7 @@ RenderProcessImpl::RenderProcessImpl()
   SetV8FlagIfNotFeature(features::kWebAssemblyCodeProtection,
                         "--no-wasm-write-protect-code-memory");
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_X86_64)
   SetV8FlagIfFeature(features::kWebAssemblyCodeProtectionPku,
                      "--wasm-memory-protection-keys");
   SetV8FlagIfNotFeature(features::kWebAssemblyCodeProtectionPku,
@@ -227,7 +227,7 @@ RenderProcessImpl::RenderProcessImpl()
   SetV8FlagIfFeature(features::kWebAssemblyDynamicTiering,
                      "--wasm-dynamic-tiering");
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_X86_64)
   if (base::FeatureList::IsEnabled(features::kWebAssemblyTrapHandler)) {
     if (command_line->HasSwitch(switches::kEnableCrashpad) ||
         command_line->HasSwitch(switches::kEnableCrashReporter) ||
