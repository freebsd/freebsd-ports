--- base/process/kill.h.orig	2025-03-24 20:50:14 UTC
+++ base/process/kill.h
@@ -123,7 +123,7 @@ GetKnownDeadTerminationStatus(ProcessHandle handle, in
 BASE_EXPORT TerminationStatus
 GetKnownDeadTerminationStatus(ProcessHandle handle, int* exit_code);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Spawns a thread to wait asynchronously for the child |process| to exit
 // and then reaps it.
 BASE_EXPORT void EnsureProcessGetsReaped(Process process);
