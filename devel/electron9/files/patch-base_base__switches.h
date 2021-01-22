--- base/base_switches.h.orig	2020-05-26 07:48:14 UTC
+++ base/base_switches.h
@@ -38,7 +38,7 @@ extern const char kDisableHighResTimer[];
 extern const char kDisableUsbKeyboardDetect[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 extern const char kDisableDevShmUsage[];
 #endif
 
@@ -51,7 +51,7 @@ extern const char kEnableReachedCodeProfiler[];
 extern const char kOrderfileMemoryOptimization[];
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 extern const char kEnableThreadInstructionCount[];
 #endif
 
