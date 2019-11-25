--- base/base_switches.cc.orig	2019-09-10 11:13:31 UTC
+++ base/base_switches.cc
@@ -107,7 +107,7 @@ const char kProfilingFlush[] = "profiling-flush";
 const char kDisableUsbKeyboardDetect[]      = "disable-usb-keyboard-detect";
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // The /dev/shm partition is too small in certain VM environments, causing
 // Chrome to fail or crash (see http://crbug.com/715363). Use this flag to
 // work-around this issue (a temporary directory will always be used to create
@@ -128,7 +128,7 @@ const char kEnableCrashReporterForTesting[] =
 const char kEnableReachedCodeProfiler[] = "enable-reached-code-profiler";
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Controls whether or not retired instruction counts are surfaced for threads
 // in trace events on Linux.
 //
