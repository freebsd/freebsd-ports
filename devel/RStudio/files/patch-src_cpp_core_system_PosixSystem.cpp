- one of the patches is a workaround for access to /proc/{pid}/fd : https://github.com/rstudio/rstudio/issues/8912

--- src/cpp/core/system/PosixSystem.cpp.orig	2021-05-24 22:22:25 UTC
+++ src/cpp/core/system/PosixSystem.cpp
@@ -41,20 +41,25 @@
 
 #include <shared_core/system/PosixSystem.hpp>
 
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
@@ -560,6 +565,7 @@ Error getOpenFds(std::vector<uint32_t>* pFds)
 #ifndef __APPLE__
 Error getOpenFds(pid_t pid, std::vector<uint32_t>* pFds)
 {
+#if !defined(__FreeBSD__)
    std::string pidStr = safe_convert::numberToString(pid);
    boost::format fmt("/proc/%1%/fd");
    FilePath filePath(boost::str(fmt % pidStr));
@@ -586,6 +592,7 @@ Error getOpenFds(pid_t pid, std::vector<uint32_t>* pFd
          pFds->push_back(fd.get());
       }
    }
+#endif
 
    return Success();
 }
@@ -911,7 +918,7 @@ Error executablePath(const char * argv0,
 
 #elif defined(HAVE_PROCSELF)
 
-   executablePath = std::string("/proc/self/exe");
+   executablePath = std::string("/proc/curproc/file");
 
 #else
 
@@ -1420,7 +1427,7 @@ Error osResourceLimit(ResourceLimit limit, int* pLimit
       case CpuLimit:
          *pLimit = RLIMIT_CPU;
          break;
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
       case NiceLimit:
          *pLimit = RLIMIT_NICE;
          break;
@@ -1493,7 +1500,7 @@ Error systemInformation(SysInfo* pSysInfo)
 {
    pSysInfo->cores = boost::thread::hardware_concurrency();
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    struct sysinfo info;
    if (::sysinfo(&info) == -1)
       return systemError(errno, ERROR_LOCATION);
@@ -1897,7 +1904,7 @@ Error restrictCoreDumps()
       return error;
 
    // no ptrace core dumps permitted
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    int res = ::prctl(PR_SET_DUMPABLE, 0);
    if (res == -1)
       return systemError(errno, ERROR_LOCATION);
@@ -1928,7 +1935,7 @@ void printCoreDumpable(const std::string& context)
    ostr << "  hard limit: " << rLimitHard << std::endl;
 
    // ptrace
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
    int dumpable = ::prctl(PR_GET_DUMPABLE, nullptr, nullptr, nullptr, nullptr);
    if (dumpable == -1)
       LOG_ERROR(systemError(errno, ERROR_LOCATION));
