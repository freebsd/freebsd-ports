--- content/shell/renderer/shell_content_renderer_client.cc.orig	2025-03-24 20:50:14 UTC
+++ content/shell/renderer/shell_content_renderer_client.cc
@@ -55,7 +55,7 @@
 #include "media/base/media_switches.h"
 #endif
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
     (defined(ARCH_CPU_X86_64) || defined(ARCH_CPU_ARM64))
 #define ENABLE_WEB_ASSEMBLY_TRAP_HANDLER_LINUX
 #include "base/debug/stack_trace.h"
