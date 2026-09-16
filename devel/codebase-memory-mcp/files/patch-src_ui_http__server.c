--- src/ui/http_server.c.orig	2026-08-18 20:39:59 UTC
+++ src/ui/http_server.c
@@ -61,6 +61,10 @@
 #endif
 #ifdef __APPLE__
 #include <mach-o/dyld.h>
+#endif
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
 #endif
 
 /* ── Constants ────────────────────────────────────────────────── */
@@ -929,6 +933,15 @@
         return copy_path(out, outsz, buf);
     }
     return false;
+#elif defined(__FreeBSD__)
+    /* No /proc by default on FreeBSD; ask the kernel for our own path. */
+    char buf[1024];
+    int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
+    size_t cb = sizeof(buf);
+    if (sysctl(mib, 4, buf, &cb, NULL, 0) == 0 && cb > 0) {
+        return copy_path(out, outsz, buf);
+    }
+    return false;
 #else
     char buf[1024];
     ssize_t len = readlink("/proc/self/exe", buf, sizeof(buf) - 1);
