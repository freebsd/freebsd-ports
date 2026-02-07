- Add FreeBSD-specific includes (netinet/in.h, dirent.h)
- Disable getOpenFds on FreeBSD (no /proc/{pid}/fd): https://github.com/rstudio/rstudio/issues/8912
- Use /proc/curproc/file instead of /proc/self/exe on FreeBSD

--- src/cpp/core/system/PosixSystem.cpp.orig	2025-10-20 20:09:32 UTC
+++ src/cpp/core/system/PosixSystem.cpp
@@ -65,6 +65,11 @@
 
 #endif
 
+#if defined(__FreeBSD__)
+#include <netinet/in.h>
+#include <dirent.h>
+#endif
+
 #include <boost/algorithm/string.hpp>
 #include <boost/algorithm/string/replace.hpp>
 #include <boost/algorithm/string/split.hpp>
@@ -680,6 +685,7 @@ Error getOpenFds(pid_t pid, std::vector<uint32_t>* pFd
 
 Error getOpenFds(pid_t pid, std::vector<uint32_t>* pFds)
 {
+#if !defined(__FreeBSD__)
    std::string pidStr = safe_convert::numberToString(pid);
    boost::format fmt("/proc/%1%/fd");
    FilePath filePath(boost::str(fmt % pidStr));
@@ -706,6 +712,7 @@ Error getOpenFds(pid_t pid, std::vector<uint32_t>* pFd
          pFds->push_back(fd.get());
       }
    }
+#endif
 
    return Success();
 }
@@ -1039,7 +1046,7 @@ Error executablePath(const char * argv0,
 
 #elif defined(HAVE_PROCSELF)
 
-   executablePath = std::string("/proc/self/exe");
+   executablePath = std::string("/proc/curproc/file");
 
 #else
 
