# Add closefrom(2) support
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=242274
# https://bugs.python.org/issue38061
# TODO: Upstream

--- Modules/posixmodule.c.orig	2019-10-14 22:32:36 UTC
+++ Modules/posixmodule.c
@@ -7810,8 +7810,16 @@ os_closerange_impl(PyObject *module, int fd_low, int f
     int i;
     Py_BEGIN_ALLOW_THREADS
     _Py_BEGIN_SUPPRESS_IPH
-    for (i = Py_MAX(fd_low, 0); i < fd_high; i++)
-        close(i);
+    fd_low = Py_MAX(fd_low, 0);
+#ifdef __FreeBSD__
+    if (fd_high >= sysconf(_SC_OPEN_MAX)) {
+        closefrom(fd_low);
+    } else
+#endif
+    {
+        for (i = fd_low; i < fd_high; i++)
+            close(i);
+    }
     _Py_END_SUPPRESS_IPH
     Py_END_ALLOW_THREADS
     Py_RETURN_NONE;
