--- src/ipc/ipc_path_manager.cc.orig	2026-04-06 14:54:27 UTC
+++ src/ipc/ipc_path_manager.cc
@@ -85,6 +85,14 @@
 #include <unistd.h>
 #endif  // _WIN32
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/queue.h>
+#include <sys/socket.h>
+#include <sys/sysctl.h>
+#include <libprocstat.h>
+#endif  // __FreeBSD__
+
 namespace mozc {
 namespace {
 
@@ -281,10 +289,12 @@ bool IPCPathManager::GetPathName(std::string *ipc_name
   *ipc_name = kIPCPrefix;
 #endif  // _WIN32
 
-#ifdef __linux__
+#if !defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__)
   // On Linux, use abstract namespace which is independent of the file system.
   (*ipc_name)[0] = '\0';
 #endif  // __linux__
+#endif  // !__FreeBSD__
 
   ipc_name->append(ipc_path_info_.key());
   ipc_name->append(".");
@@ -390,6 +400,33 @@ bool IPCPathManager::IsValidServer(uint32_t pid,
 #endif  // __APPLE__
 
 #ifdef __linux__
+#ifdef __FreeBSD__
+  struct kinfo_proc *kipp;
+  struct procstat *prstat;
+  char filename[PATH_MAX];
+  unsigned int count;
+
+  prstat = procstat_open_sysctl();
+  if (prstat == NULL) {
+    LOG(ERROR) << "procstat_getprocs failed: " << strerror(errno);
+    return false;
+  }
+  kipp = procstat_getprocs(prstat, KERN_PROC_PID, pid, &count);
+  if (kipp == NULL) {
+    LOG(ERROR) << "procstat_getprocs failed: " << strerror(errno);
+    procstat_close(prstat);
+    return false;
+  }
+  if (procstat_getpathname(prstat, kipp, filename, sizeof(filename)) != 0) {
+    LOG(ERROR) << "procstat_getpathname failed: " << strerror(errno);
+    procstat_freeprocs(prstat, kipp);
+    procstat_close(prstat);
+    return false;
+  }
+  procstat_freeprocs(prstat, kipp);
+  procstat_close(prstat);
+  server_path_ = filename;
+#else
   // load from /proc/<pid>/exe
   std::string proc = absl::StrFormat("/proc/%u/exe", pid);
   absl::StatusOr<std::string> filename = FileUtil::ReadSymlink(proc);
@@ -399,6 +436,7 @@ bool IPCPathManager::IsValidServer(uint32_t pid,
   }
 
   server_path_ = filename.value();
+#endif // __FreeBSD__
   server_pid_ = pid;
 #endif  // __linux__
 
