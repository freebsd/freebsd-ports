--- content/renderer/render_process_impl.cc.orig	2023-01-30 07:58:59 UTC
+++ content/renderer/render_process_impl.cc
@@ -46,7 +46,7 @@
 #if BUILDFLAG(IS_WIN)
 #include "base/win/win_util.h"
 #endif
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_X86_64)
 #include "v8/include/v8-wasm-trap-handler-posix.h"
 #endif
 
@@ -154,7 +154,7 @@ RenderProcessImpl::RenderProcessImpl()
   SetV8FlagIfNotFeature(features::kWebAssemblyCodeProtection,
                         "--no-wasm-write-protect-code-memory");
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_X86_64)
   SetV8FlagIfFeature(features::kWebAssemblyCodeProtectionPku,
                      "--wasm-memory-protection-keys");
   SetV8FlagIfNotFeature(features::kWebAssemblyCodeProtectionPku,
@@ -231,7 +231,7 @@ RenderProcessImpl::RenderProcessImpl()
   // Freezing flags after init conflicts with node in the renderer.
   v8::V8::SetFlagsFromString("--no-freeze-flags-after-init");
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_X86_64)
   if (base::FeatureList::IsEnabled(features::kWebAssemblyTrapHandler)) {
     base::CommandLine* const command_line =
         base::CommandLine::ForCurrentProcess();
