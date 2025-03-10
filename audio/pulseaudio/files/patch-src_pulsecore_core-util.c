--- src/pulsecore/core-util.c.orig	2024-01-12 17:22:09 UTC
+++ src/pulsecore/core-util.c
@@ -2850,12 +2850,19 @@ int pa_close_allv(const int except_fds[]) {
     }
 
 #endif
-
+#if defined(__FreeBSD__)
+    maxfd = 0;
+    for (int i = 0; except_fds[i] >= 0; i++)
+        if (except_fds[i] > maxfd)
+            maxfd = except_fds[i];
+    maxfd++;
+    closefrom(MAX(maxfd, STDERR_FILENO + 1));
+#else
     if (getrlimit(RLIMIT_NOFILE, &rl) >= 0)
         maxfd = (int) rl.rlim_max;
     else
         maxfd = sysconf(_SC_OPEN_MAX);
-
+#endif
     for (fd = 3; fd < maxfd; fd++) {
         int i;
         bool found;
