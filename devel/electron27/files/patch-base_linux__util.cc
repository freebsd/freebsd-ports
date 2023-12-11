--- base/linux_util.cc.orig	2023-10-19 19:57:58 UTC
+++ base/linux_util.cc
@@ -15,6 +15,7 @@
 
 #include <iomanip>
 #include <memory>
+#include <sstream>
 
 #include "base/base_export.h"
 #include "base/files/dir_reader_posix.h"
@@ -135,6 +136,9 @@ void SetLinuxDistro(const std::string& distro) {
 }
 
 bool GetThreadsForProcess(pid_t pid, std::vector<pid_t>* tids) {
+#if BUILDFLAG(IS_BSD)
+  return false;
+#else
   // 25 > strlen("/proc//task") + strlen(std::to_string(INT_MAX)) + 1 = 22
   char buf[25];
   strings::SafeSPrintf(buf, "/proc/%d/task", pid);
@@ -152,6 +156,7 @@ bool GetThreadsForProcess(pid_t pid, std::vector<pid_t
   }
 
   return true;
+#endif
 }
 
 pid_t FindThreadIDWithSyscall(pid_t pid, const std::string& expected_data,
