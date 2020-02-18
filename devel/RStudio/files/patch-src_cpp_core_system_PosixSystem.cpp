--- src/cpp/core/system/PosixSystem.cpp.orig	2020-01-23 23:30:24 UTC
+++ src/cpp/core/system/PosixSystem.cpp
@@ -47,13 +47,18 @@
 #include <gsl/gsl>
 #endif
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <sys/prctl.h>
 #include <sys/sysinfo.h>
 #include <linux/kernel.h>
 #include <dirent.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <netinet/in.h>
+#include <dirent.h>
+#endif
+
 #include <boost/thread.hpp>
 #include <boost/format.hpp>
 #include <boost/lexical_cast.hpp>
@@ -917,7 +922,7 @@ Error executablePath(const char * argv0,
 
 #elif defined(HAVE_PROCSELF)
 
-   executablePath = std::string("/proc/self/exe");
+   executablePath = std::string("/proc/curproc/file");
 
 #else
 
@@ -1426,7 +1431,7 @@ Error osResourceLimit(ResourceLimit limit, int* pLimit
       case CpuLimit:
          *pLimit = RLIMIT_CPU;
          break;
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
       case NiceLimit:
          *pLimit = RLIMIT_NICE;
          break;
@@ -1499,7 +1504,7 @@ Error systemInformation(SysInfo* pSysInfo)
 {
    pSysInfo->cores = boost::thread::hardware_concurrency();
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    struct sysinfo info;
    if (::sysinfo(&info) == -1)
       return systemError(errno, ERROR_LOCATION);
@@ -1939,7 +1944,7 @@ Error restrictCoreDumps()
       return error;
 
    // no ptrace core dumps permitted
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    int res = ::prctl(PR_SET_DUMPABLE, 0);
    if (res == -1)
       return systemError(errno, ERROR_LOCATION);
@@ -1950,7 +1955,7 @@ Error restrictCoreDumps()
 
 Error enableCoreDumps()
 {
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    int res = ::prctl(PR_SET_DUMPABLE, 1);
    if (res == -1)
       return systemError(errno, ERROR_LOCATION);
@@ -1976,7 +1981,7 @@ void printCoreDumpable(const std::string& context)
    ostr << "  hard limit: " << rLimitHard << std::endl;
 
    // ptrace
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    int dumpable = ::prctl(PR_GET_DUMPABLE, nullptr, nullptr, nullptr, nullptr);
    if (dumpable == -1)
       LOG_ERROR(systemError(errno, ERROR_LOCATION));
