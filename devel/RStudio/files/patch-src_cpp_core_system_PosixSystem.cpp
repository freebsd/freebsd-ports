- one of the patches is a workaround for access to /proc/{pid}/fd : https://github.com/rstudio/rstudio/issues/8912

--- src/cpp/core/system/PosixSystem.cpp.orig	2022-12-03 07:38:59 UTC
+++ src/cpp/core/system/PosixSystem.cpp
@@ -56,6 +56,11 @@
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
@@ -619,6 +624,7 @@ Error getOpenFds(std::vector<uint32_t>* pFds)
 #ifndef __APPLE__
 Error getOpenFds(pid_t pid, std::vector<uint32_t>* pFds)
 {
+#if !defined(__FreeBSD__)
    std::string pidStr = safe_convert::numberToString(pid);
    boost::format fmt("/proc/%1%/fd");
    FilePath filePath(boost::str(fmt % pidStr));
@@ -645,6 +651,7 @@ Error getOpenFds(pid_t pid, std::vector<uint32_t>* pFd
          pFds->push_back(fd.get());
       }
    }
+#endif
 
    return Success();
 }
@@ -970,7 +977,7 @@ Error executablePath(const char * argv0,
 
 #elif defined(HAVE_PROCSELF)
 
-   executablePath = std::string("/proc/self/exe");
+   executablePath = std::string("/proc/curproc/file");
 
 #else
 
