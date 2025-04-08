--- services/video_effects/video_effects_sandbox_hook_linux.h.orig	2025-01-27 17:37:37 UTC
+++ services/video_effects/video_effects_sandbox_hook_linux.h
@@ -5,7 +5,13 @@
 #ifndef SERVICES_VIDEO_EFFECTS_VIDEO_EFFECTS_SANDBOX_HOOK_LINUX_H_
 #define SERVICES_VIDEO_EFFECTS_VIDEO_EFFECTS_SANDBOX_HOOK_LINUX_H_
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace video_effects {
 
