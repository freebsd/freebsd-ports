--- src/cpp/core/system/PosixSystem.cpp.orig	2018-05-16 18:21:36 UTC
+++ src/cpp/core/system/PosixSystem.cpp
@@ -36,6 +36,7 @@
 #include <ifaddrs.h>
 #include <sys/socket.h>
 #include <netdb.h>
+#include <netinet/in.h>
 
 #include <uuid/uuid.h>
 
@@ -45,13 +46,22 @@
 #include <libproc.h>
 #endif
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 #include <sys/prctl.h>
 #include <sys/sysinfo.h>
 #include <linux/kernel.h>
 #include <dirent.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/queue.h>
+#include <sys/socket.h>
+#include <libprocstat.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#endif
+
 #include <boost/thread.hpp>
 #include <boost/format.hpp>
 #include <boost/lexical_cast.hpp>
@@ -569,7 +579,35 @@ Error getOpenFds(std::vector<unsigned in
    return getOpenFds(getpid(), pFds);
 }
 
-#ifndef __APPLE__
+#if defined(__FreeBSD__)
+Error getOpenFds(pid_t pid, std::vector<unsigned int>* pFds)
+{
+   struct procstat *prstat;
+   struct kinfo_proc *kipp, *p;
+   struct filestat_list *head;
+   struct filestat *fst;
+   unsigned i, cnt;
+
+   prstat = procstat_open_sysctl();
+   p = procstat_getprocs(prstat, KERN_PROC_PROC, pid, &cnt);
+
+   for (i = 0; i < cnt; i++) {
+      kipp = &p[i];
+      if (kipp->ki_pid == pid) {
+         head = procstat_getfiles(prstat, kipp, 0);
+         if (head != NULL)
+            STAILQ_FOREACH(fst, head, next)
+               if (fst->fs_fd >= 0)
+                  pFds->push_back(fst->fs_fd);
+      }
+   }
+
+   procstat_freeprocs(prstat, p);
+   procstat_close(prstat);
+
+   return Success();
+}
+#elif !defined(__APPLE__)
 Error getOpenFds(pid_t pid, std::vector<unsigned int>* pFds)
 {
    std::string pidStr = safe_convert::numberToString(pid);
@@ -859,7 +897,11 @@ Error executablePath(const char * argv0,
 
 #elif defined(HAVE_PROCSELF)
 
+#if defined(__FreeBSD__)
+   executablePath = std::string("/proc/curproc/file");
+#else
    executablePath = std::string("/proc/self/exe");
+#endif
 
 #else
 
@@ -1296,7 +1338,7 @@ Error osResourceLimit(ResourceLimit limi
       case CpuLimit:
          *pLimit = RLIMIT_CPU;
          break;
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
       case NiceLimit:
          *pLimit = RLIMIT_NICE;
          break;
@@ -1369,7 +1411,7 @@ Error systemInformation(SysInfo* pSysInf
 {
    pSysInfo->cores = boost::thread::hardware_concurrency();
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
    struct sysinfo info;
    if (::sysinfo(&info) == -1)
       return systemError(errno, ERROR_LOCATION);
@@ -1402,7 +1444,7 @@ void toPids(const std::vector<std::strin
 
 } // anonymous namespace
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 core::Error pidof(const std::string& process, std::vector<PidType>* pPids)
 {
    // use pidof to capture pids
@@ -1711,7 +1753,7 @@ Error restrictCoreDumps()
       return error;
 
    // no ptrace core dumps permitted
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
    int res = ::prctl(PR_SET_DUMPABLE, 0);
    if (res == -1)
       return systemError(errno, ERROR_LOCATION);
@@ -1722,7 +1764,7 @@ Error restrictCoreDumps()
 
 Error enableCoreDumps()
 {
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
    int res = ::prctl(PR_SET_DUMPABLE, 1);
    if (res == -1)
       return systemError(errno, ERROR_LOCATION);
@@ -1748,7 +1790,7 @@ void printCoreDumpable(const std::string
    ostr << "  hard limit: " << rLimitHard << std::endl;
 
    // ptrace
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
    int dumpable = ::prctl(PR_GET_DUMPABLE, NULL, NULL, NULL, NULL);
    if (dumpable == -1)
       LOG_ERROR(systemError(errno, ERROR_LOCATION));
