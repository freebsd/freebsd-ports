--- third_party/crashpad/crashpad/util/misc/capture_context.h.orig	2023-10-19 19:59:07 UTC
+++ third_party/crashpad/crashpad/util/misc/capture_context.h
@@ -21,7 +21,8 @@
 #include <mach/mach.h>
 #elif BUILDFLAG(IS_WIN)
 #include <windows.h>
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
+      BUILDFLAG(IS_FREEBSD)
 #include <ucontext.h>
 #endif  // BUILDFLAG(IS_APPLE)
 
@@ -35,7 +36,8 @@ using NativeCPUContext = arm_unified_thread_state;
 #endif
 #elif BUILDFLAG(IS_WIN)
 using NativeCPUContext = CONTEXT;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
+      BUILDFLAG(IS_BSD)
 using NativeCPUContext = ucontext_t;
 #endif  // BUILDFLAG(IS_APPLE)
 
