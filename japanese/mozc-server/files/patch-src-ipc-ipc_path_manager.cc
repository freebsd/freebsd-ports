--- src/ipc/ipc_path_manager.cc.orig	2026-10-16 12:33:33 UTC
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
 
@@ -389,7 +397,37 @@ bool IPCPathManager::IsValidServer(uint32_t pid,
   server_pid_ = pid;
 #endif  // __APPLE__
 
-#ifdef __linux__
+#if defined(__FreeBSD__)
+  struct kinfo_proc *kipp;
+  struct procstat *prstat;
+  char filename[PATH_MAX];
+  unsigned int count = 0;
+
+  prstat = procstat_open_sysctl();
+  if (prstat == NULL) {
+    LOG(ERROR) << "procstat_open_sysctl failed: " << strerror(errno);
+    return false;
+  }
+  kipp = procstat_getprocs(prstat, KERN_PROC_PID, pid, &count);
+  if (kipp == nullptr || count != 1) {
+    LOG(ERROR) << "Cannot find a unique process for pid: " << pid;
+    if (kipp != nullptr) {
+      procstat_freeprocs(prstat, kipp);
+    }
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
+  server_pid_ = pid;
+#elif defined(__linux__)
   // load from /proc/<pid>/exe
   std::string proc = absl::StrFormat("/proc/%u/exe", pid);
   absl::StatusOr<std::string> filename = FileUtil::ReadSymlink(proc);
@@ -400,7 +438,7 @@ bool IPCPathManager::IsValidServer(uint32_t pid,
 
   server_path_ = filename.value();
   server_pid_ = pid;
-#endif  // __linux__
+#endif // __FreeBSD__
 
   MOZC_VLOG(1) << "server path: " << server_path << " " << server_path_;
 
