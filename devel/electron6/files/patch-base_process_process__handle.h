--- base/process/process_handle.h.orig	2019-09-10 11:13:31 UTC
+++ base/process/process_handle.h
@@ -64,7 +64,7 @@ BASE_EXPORT ProcessId GetCurrentProcId();
 // a process's PID.
 BASE_EXPORT uint32_t GetUniqueIdForProcess();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // When a process is started in a different PID namespace from the browser
 // process, this function must be called with the process's PID in the browser's
 // PID namespace in order to initialize its unique ID. Not thread safe.
