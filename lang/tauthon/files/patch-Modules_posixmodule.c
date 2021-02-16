# Add closefrom(2) support
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=242274
# https://bugs.python.org/issue38061
# TODO: Upstream

--- Modules/posixmodule.c.orig	2019-10-19 18:38:44 UTC
+++ Modules/posixmodule.c
@@ -6676,9 +6676,16 @@ posix_closerange(PyObject *self, PyObject *args)
     if (!PyArg_ParseTuple(args, "ii:closerange", &fd_from, &fd_to))
         return NULL;
     Py_BEGIN_ALLOW_THREADS
-    for (i = fd_from; i < fd_to; i++)
-        if (_PyVerify_fd(i))
-            close(i);
+#ifdef __FreeBSD__
+    if (fd_to >= sysconf(_SC_OPEN_MAX)) {
+        closefrom(fd_from);
+    } else
+#endif
+    {
+        for (i = fd_from; i < fd_to; i++)
+            if (_PyVerify_fd(i))
+                close(i);
+    }
     Py_END_ALLOW_THREADS
     Py_RETURN_NONE;
 }
