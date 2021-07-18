--- base/process/memory.h.orig	2021-01-07 00:36:18 UTC
+++ base/process/memory.h
@@ -24,7 +24,7 @@ BASE_EXPORT void EnableTerminationOnOutOfMemory();
 // Crash reporting classifies such crashes as OOM.
 BASE_EXPORT void TerminateBecauseOutOfMemory(size_t size);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_AIX)
 BASE_EXPORT extern size_t g_oom_size;
 
