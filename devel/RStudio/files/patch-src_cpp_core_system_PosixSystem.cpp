--- src/cpp/core/system/PosixSystem.cpp.orig	2019-02-16 02:00:24 UTC
+++ src/cpp/core/system/PosixSystem.cpp
@@ -37,6 +37,7 @@
 #include <ifaddrs.h>
 #include <sys/socket.h>
 #include <netdb.h>
+#include <netinet/in.h>
 
 #include <uuid/uuid.h>
 
@@ -46,13 +47,22 @@
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
@@ -575,7 +585,35 @@ Error getOpenFds(std::vector<uint32_t>* 
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
 Error getOpenFds(pid_t pid, std::vector<uint32_t>* pFds)
 {
    std::string pidStr = safe_convert::numberToString(pid);
@@ -920,7 +958,11 @@ Error executablePath(const char * argv0,
 
 #elif defined(HAVE_PROCSELF)
 
+#if defined(__FreeBSD__)
+   executablePath = std::string("/proc/curproc/file");
+#else
    executablePath = std::string("/proc/self/exe");
+#endif
 
 #else
 
@@ -1395,7 +1437,7 @@ Error osResourceLimit(ResourceLimit limi
       case CpuLimit:
          *pLimit = RLIMIT_CPU;
          break;
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
       case NiceLimit:
          *pLimit = RLIMIT_NICE;
          break;
@@ -1468,7 +1510,7 @@ Error systemInformation(SysInfo* pSysInf
 {
    pSysInfo->cores = boost::thread::hardware_concurrency();
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
    struct sysinfo info;
    if (::sysinfo(&info) == -1)
       return systemError(errno, ERROR_LOCATION);
@@ -1501,7 +1543,7 @@ void toPids(const std::vector<std::strin
 
 } // anonymous namespace
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 core::Error pidof(const std::string& process, std::vector<PidType>* pPids)
 {
    // use pidof to capture pids
@@ -1908,7 +1950,7 @@ Error restrictCoreDumps()
       return error;
 
    // no ptrace core dumps permitted
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
    int res = ::prctl(PR_SET_DUMPABLE, 0);
    if (res == -1)
       return systemError(errno, ERROR_LOCATION);
@@ -1919,7 +1961,7 @@ Error restrictCoreDumps()
 
 Error enableCoreDumps()
 {
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
    int res = ::prctl(PR_SET_DUMPABLE, 1);
    if (res == -1)
       return systemError(errno, ERROR_LOCATION);
@@ -1945,7 +1987,7 @@ void printCoreDumpable(const std::string
    ostr << "  hard limit: " << rLimitHard << std::endl;
 
    // ptrace
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
    int dumpable = ::prctl(PR_GET_DUMPABLE, NULL, NULL, NULL, NULL);
    if (dumpable == -1)
       LOG_ERROR(systemError(errno, ERROR_LOCATION));
