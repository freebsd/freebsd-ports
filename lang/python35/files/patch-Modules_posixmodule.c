# Add closefrom(2) support
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=242274
# https://bugs.python.org/issue38061
# TODO: Upstream

--- Modules/posixmodule.c.orig	2019-11-01 23:02:34 UTC
+++ Modules/posixmodule.c
@@ -7853,9 +7853,16 @@ os_closerange_impl(PyObject *module, int fd_low, int f
     int i;
     Py_BEGIN_ALLOW_THREADS
     _Py_BEGIN_SUPPRESS_IPH
-    for (i = fd_low; i < fd_high; i++)
-        if (_PyVerify_fd(i))
-            close(i);
+#ifdef __FreeBSD__
+    if (fd_high >= sysconf(_SC_OPEN_MAX)) {
+        closefrom(fd_low);
+    } else
+#endif
+    {
+        for (i = fd_low; i < fd_high; i++)
+            if (_PyVerify_fd(i))
+                close(i);
+    }
     _Py_END_SUPPRESS_IPH
     Py_END_ALLOW_THREADS
     Py_RETURN_NONE;
