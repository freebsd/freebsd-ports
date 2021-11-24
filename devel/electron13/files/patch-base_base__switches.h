--- base/base_switches.h.orig	2021-07-15 19:13:29 UTC
+++ base/base_switches.h
@@ -42,8 +42,8 @@ extern const char kDisableUsbKeyboardDetect[];
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
-    !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_BSD) || (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
+    !BUILDFLAG(IS_CHROMEOS_LACROS))
 extern const char kDisableDevShmUsage[];
 #endif
 
@@ -59,7 +59,7 @@ extern const char kEnableIdleTracing[];
 extern const char kForceFieldTrialParams[];
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 extern const char kEnableThreadInstructionCount[];
 
 // TODO(crbug.com/1176772): Remove kEnableCrashpad and IsCrashpadEnabled() when
