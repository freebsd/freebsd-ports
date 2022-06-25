--- lib/zoneinfo_module.c.orig	2020-06-23 13:47:53 UTC
+++ lib/zoneinfo_module.c
@@ -617,7 +617,7 @@ zoneinfo_fromutc(PyObject *obj_self, PyObject *dt)
             Py_DECREF(args);
             Py_DECREF(kwargs);
             Py_DECREF(replace);
-#ifndef ATLEAST_37
+#ifdef ATLEAST_37
             Py_DECREF(one);
 #endif
 
