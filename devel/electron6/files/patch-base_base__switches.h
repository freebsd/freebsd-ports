--- base/base_switches.h.orig	2019-09-10 11:13:31 UTC
+++ base/base_switches.h
@@ -36,7 +36,7 @@ extern const char kWaitForDebugger[];
 extern const char kDisableUsbKeyboardDetect[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 extern const char kDisableDevShmUsage[];
 #endif
 
@@ -49,7 +49,7 @@ extern const char kEnableReachedCodeProfiler[];
 extern const char kOrderfileMemoryOptimization[];
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 extern const char kEnableThreadInstructionCount[];
 #endif
 
