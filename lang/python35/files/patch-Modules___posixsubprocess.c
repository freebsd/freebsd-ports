# Add closefrom(2) support
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=242274
# https://bugs.python.org/issue38061
# TODO: Upstream

--- Modules/_posixsubprocess.c.orig	2019-11-01 23:02:34 UTC
+++ Modules/_posixsubprocess.c
@@ -233,8 +233,15 @@ _close_fds_by_brute_force(long start_fd, PyObject *py_
         start_fd = keep_fd + 1;
     }
     if (start_fd <= end_fd) {
-        for (fd_num = start_fd; fd_num < end_fd; ++fd_num) {
-            close(fd_num);
+#ifdef __FreeBSD__
+        if (end_fd >= sysconf(_SC_OPEN_MAX)) {
+            closefrom(start_fd);
+        } else
+#endif
+        {
+            for (fd_num = start_fd; fd_num < end_fd; ++fd_num) {
+                close(fd_num);
+            }
         }
     }
 }
