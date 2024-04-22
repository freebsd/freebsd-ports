--- components/services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.h.orig	2023-05-25 00:41:52 UTC
+++ components/services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.h
@@ -5,7 +5,13 @@
 #ifndef COMPONENTS_SERVICES_SCREEN_AI_SANDBOX_SCREEN_AI_SANDBOX_HOOK_LINUX_H_
 #define COMPONENTS_SERVICES_SCREEN_AI_SANDBOX_SCREEN_AI_SANDBOX_HOOK_LINUX_H_
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace screen_ai {
 
