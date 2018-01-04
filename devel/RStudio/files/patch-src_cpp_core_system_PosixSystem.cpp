--- src/cpp/core/system/PosixSystem.cpp.orig	2017-11-16 21:40:37 UTC
+++ src/cpp/core/system/PosixSystem.cpp
@@ -36,6 +36,7 @@
 #include <ifaddrs.h>
 #include <sys/socket.h>
 #include <netdb.h>
+#include <netinet/in.h>
 
 #include <uuid/uuid.h>
 
@@ -46,9 +47,9 @@
 #endif
 
 #ifndef __APPLE__
-#include <sys/prctl.h>
+//#include <sys/prctl.h>
 #include <sys/sysinfo.h>
-#include <linux/kernel.h>
+//#include <linux/kernel.h>
 #include <dirent.h>
 #endif
 
@@ -670,7 +671,7 @@ Error executablePath(const char * argv0,
 
 #elif defined(HAVE_PROCSELF)
 
-   executablePath = std::string("/proc/self/exe");
+   executablePath = std::string("/proc/curproc/file");
 
 #else
 
@@ -1102,7 +1103,7 @@ Error osResourceLimit(ResourceLimit limi
       case CpuLimit:
          *pLimit = RLIMIT_CPU;
          break;
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
       case NiceLimit:
          *pLimit = RLIMIT_NICE;
          break;
@@ -1175,7 +1176,7 @@ Error systemInformation(SysInfo* pSysInf
 {
    pSysInfo->cores = boost::thread::hardware_concurrency();
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    struct sysinfo info;
    if (::sysinfo(&info) == -1)
       return systemError(errno, ERROR_LOCATION);
@@ -1495,9 +1496,9 @@ Error restrictCoreDumps()
 
    // no ptrace core dumps permitted
 #ifndef __APPLE__
-   int res = ::prctl(PR_SET_DUMPABLE, 0);
-   if (res == -1)
-      return systemError(errno, ERROR_LOCATION);
+//   int res = ::prctl(PR_SET_DUMPABLE, 0);
+//   if (res == -1)
+//      return systemError(errno, ERROR_LOCATION);
 #endif
 
    return Success();
@@ -1521,10 +1522,10 @@ void printCoreDumpable(const std::string
 
    // ptrace
 #ifndef __APPLE__
-   int dumpable = ::prctl(PR_GET_DUMPABLE, NULL, NULL, NULL, NULL);
-   if (dumpable == -1)
-      LOG_ERROR(systemError(errno, ERROR_LOCATION));
-   ostr << "  pr_get_dumpable: " << dumpable << std::endl;
+//   int dumpable = ::prctl(PR_GET_DUMPABLE, NULL, NULL, NULL, NULL);
+//   if (dumpable == -1)
+//      LOG_ERROR(systemError(errno, ERROR_LOCATION));
+//   ostr << "  pr_get_dumpable: " << dumpable << std::endl;
 #endif
 
    std::cerr << ostr.str();
