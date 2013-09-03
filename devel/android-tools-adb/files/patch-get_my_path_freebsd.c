--- get_my_path_freebsd.c.orig	2013-09-03 17:33:27.000000000 +0800
+++ get_my_path_freebsd.c	2013-09-03 17:41:13.000000000 +0800
@@ -18,19 +18,18 @@
  */
 
 #include <sys/types.h>
+#include <sys/sysctl.h>
 #include <unistd.h>
-#include <limits.h>
-#include <stdio.h>
 
 void
 get_my_path(char *exe, size_t maxLen)
 {
-    char proc[64];
+    int mib[4] = {
+        CTL_KERN,
+        KERN_PROC,
+        KERN_PROC_PATHNAME,
+        getpid()
+    };
 
-    snprintf(proc, sizeof(proc), "/proc/%d/file", getpid());
-
-    int err = readlink(proc, exe, maxLen - 1);
-
-    exe[err > 0 ? err : 0] = '\0';
+    sysctl(mib, 4, exe, &maxLen, NULL, 0);
 }
-
