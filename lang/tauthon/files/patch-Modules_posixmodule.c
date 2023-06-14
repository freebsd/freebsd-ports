# Add closefrom(2) support
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=242274
# https://bugs.python.org/issue38061
# TODO: Upstream

--- Modules/posixmodule.c.orig	2023-02-04 10:09:53 UTC
+++ Modules/posixmodule.c
@@ -6812,11 +6812,18 @@ posix_closerange(PyObject *self, PyObject *args)
         return NULL;
     Py_BEGIN_ALLOW_THREADS
     _Py_BEGIN_SUPPRESS_IPH
-    for (i = fd_from; i < fd_to; i++)
-        if (_PyVerify_fd(i)) {
-            errno = 0;
-            close(i);
-        }
+#ifdef __FreeBSD__
+    if (fd_to >= sysconf(_SC_OPEN_MAX)) {
+        closefrom(fd_from);
+    } else
+#endif
+    {
+        for (i = fd_from; i < fd_to; i++)
+            if (_PyVerify_fd(i)) {
+                errno = 0;
+                close(i);
+            }
+    }
     _Py_END_SUPPRESS_IPH
     Py_END_ALLOW_THREADS
     Py_RETURN_NONE;
