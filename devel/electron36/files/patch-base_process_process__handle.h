--- base/process/process_handle.h.orig	2024-02-21 00:20:30 UTC
+++ base/process/process_handle.h
@@ -86,7 +86,7 @@ BASE_EXPORT UniqueProcId GetUniqueIdForProcess();
 // processes may be reused.
 BASE_EXPORT UniqueProcId GetUniqueIdForProcess();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // When a process is started in a different PID namespace from the browser
 // process, this function must be called with the process's PID in the browser's
 // PID namespace in order to initialize its unique ID. Not thread safe.
