--- src/butil/process_util.cc.orig	2026-02-23 02:11:29 UTC
+++ src/butil/process_util.cc
@@ -31,7 +31,10 @@
 #include "butil/process_util.h"
 
 #if defined(OS_MACOSX)
-#include <libproc.h>                   // proc_pidpath
+#include <libproc.h>
+#elif defined(OS_FREEBSD)
+#include <sys/types.h>
+#include <sys/sysctl.h>                   // proc_pidpath
 #endif
 namespace butil {
 
@@ -47,7 +50,7 @@ ssize_t ReadCommandLine(char* buf, size_t len, bool wi
         LOG(ERROR) << "Fail to read /proc/self/cmdline";
         return -1;
     }
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
     static pid_t pid = getpid();
     std::ostringstream oss;
     char cmdbuf[32];
@@ -97,6 +100,14 @@ ssize_t GetProcessAbsolutePath(char *buf, size_t len) 
     memset(buf, 0, len);
     int ret = proc_pidpath(getpid(), buf, len);
     return ret;
+#elif defined(OS_FREEBSD)
+    memset(buf, 0, len);
+    int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
+    size_t cb = len;
+    if (sysctl(mib, 4, buf, &cb, NULL, 0) == 0) {
+        return (ssize_t)cb;
+    }
+    return -1;
 #endif
 }
 
