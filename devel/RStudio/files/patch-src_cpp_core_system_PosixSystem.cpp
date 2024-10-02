- one of the patches is a workaround for access to /proc/{pid}/fd : https://github.com/rstudio/rstudio/issues/8912

--- src/cpp/core/system/PosixSystem.cpp.orig	2024-06-04 21:19:10 UTC
+++ src/cpp/core/system/PosixSystem.cpp
@@ -69,6 +69,11 @@
 
 #endif
 
+#if defined(__FreeBSD__)
+#include <netinet/in.h>
+#include <dirent.h>
+#endif
+
 #include <boost/thread.hpp>
 #include <boost/format.hpp>
 #include <boost/lexical_cast.hpp>
@@ -633,6 +638,7 @@ Error getOpenFds(pid_t pid, std::vector<uint32_t>* pFd
 #ifndef __APPLE__
 Error getOpenFds(pid_t pid, std::vector<uint32_t>* pFds)
 {
+#if !defined(__FreeBSD__)
    std::string pidStr = safe_convert::numberToString(pid);
    boost::format fmt("/proc/%1%/fd");
    FilePath filePath(boost::str(fmt % pidStr));
@@ -659,6 +665,7 @@ Error getOpenFds(pid_t pid, std::vector<uint32_t>* pFd
          pFds->push_back(fd.get());
       }
    }
+#endif
 
    return Success();
 }
@@ -984,7 +991,7 @@ Error executablePath(const char * argv0,
 
 #elif defined(HAVE_PROCSELF)
 
-   executablePath = std::string("/proc/self/exe");
+   executablePath = std::string("/proc/curproc/file");
 
 #else
 
