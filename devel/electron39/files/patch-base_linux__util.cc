--- base/linux_util.cc.orig	2025-04-22 20:15:27 UTC
+++ base/linux_util.cc
@@ -163,10 +163,14 @@ bool GetThreadsForProcess(pid_t pid, std::vector<pid_t
 }
 
 bool GetThreadsForProcess(pid_t pid, std::vector<pid_t>* tids) {
+#if BUILDFLAG(IS_BSD)
+  return false;
+#else
   // 25 > strlen("/proc//task") + strlen(base::NumberToString(INT_MAX)) + 1 = 22
   char buf[25];
   strings::SafeSPrintf(buf, "/proc/%d/task", pid);
   return GetThreadsFromProcessDir(buf, tids);
+#endif
 }
 
 bool GetThreadsForCurrentProcess(std::vector<pid_t>* tids) {
