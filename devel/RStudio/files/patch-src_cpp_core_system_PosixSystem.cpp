- one of the patches is a workaround for access to /proc/{pid}/fd : https://github.com/rstudio/rstudio/issues/8912

--- src/cpp/core/system/PosixSystem.cpp.orig	2020-09-17 18:16:48 UTC
+++ src/cpp/core/system/PosixSystem.cpp
@@ -40,20 +40,25 @@
 
 #include <uuid/uuid.h>
 
-#ifdef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <mach-o/dyld.h>
 #include <sys/proc_info.h>
 #include <libproc.h>
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
@@ -575,6 +580,7 @@ Error getOpenFds(std::vector<uint32_t>* pFds)
 #ifndef __APPLE__
 Error getOpenFds(pid_t pid, std::vector<uint32_t>* pFds)
 {
+#if !defined(__FreeBSD__)
    std::string pidStr = safe_convert::numberToString(pid);
    boost::format fmt("/proc/%1%/fd");
    FilePath filePath(boost::str(fmt % pidStr));
@@ -601,6 +607,7 @@ Error getOpenFds(pid_t pid, std::vector<uint32_t>* pFd
          pFds->push_back(fd.get());
       }
    }
+#endif
 
    return Success();
 }
@@ -922,7 +929,7 @@ Error executablePath(const char * argv0,
 
 #elif defined(HAVE_PROCSELF)
 
-   executablePath = std::string("/proc/self/exe");
+   executablePath = std::string("/proc/curproc/file");
 
 #else
 
@@ -1431,7 +1438,7 @@ Error osResourceLimit(ResourceLimit limit, int* pLimit
       case CpuLimit:
          *pLimit = RLIMIT_CPU;
          break;
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
       case NiceLimit:
          *pLimit = RLIMIT_NICE;
          break;
@@ -1504,7 +1511,7 @@ Error systemInformation(SysInfo* pSysInfo)
 {
    pSysInfo->cores = boost::thread::hardware_concurrency();
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    struct sysinfo info;
    if (::sysinfo(&info) == -1)
       return systemError(errno, ERROR_LOCATION);
@@ -1944,7 +1951,7 @@ Error restrictCoreDumps()
       return error;
 
    // no ptrace core dumps permitted
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    int res = ::prctl(PR_SET_DUMPABLE, 0);
    if (res == -1)
       return systemError(errno, ERROR_LOCATION);
@@ -1955,7 +1962,7 @@ Error restrictCoreDumps()
 
 Error enableCoreDumps()
 {
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    int res = ::prctl(PR_SET_DUMPABLE, 1);
    if (res == -1)
       return systemError(errno, ERROR_LOCATION);
@@ -1981,7 +1988,7 @@ void printCoreDumpable(const std::string& context)
    ostr << "  hard limit: " << rLimitHard << std::endl;
 
    // ptrace
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    int dumpable = ::prctl(PR_GET_DUMPABLE, nullptr, nullptr, nullptr, nullptr);
    if (dumpable == -1)
       LOG_ERROR(systemError(errno, ERROR_LOCATION));
