--- breezy/bzr/_dirstate_helpers_pyx.pyx.orig	2026-09-06 21:17:46 UTC
+++ breezy/bzr/_dirstate_helpers_pyx.pyx
@@ -98,7 +98,7 @@ cdef extern from "Python.h":
     object PyTuple_GetItem_void_object "PyTuple_GET_ITEM" (void* tpl, int index)
     object PyTuple_GET_ITEM(object tpl, Py_ssize_t index)
 
-    unsigned long PyInt_AsUnsignedLongMask(object number) except? -1
+    unsigned long PyLong_AsUnsignedLongMask(object number) except? -1
 
     char *PyBytes_AsString(object p)
     char *PyBytes_AsString_obj "PyBytes_AsString" (PyObject *string)
@@ -800,7 +800,7 @@ cdef unsigned long _time_to_unsigned(object t):  # can
 cdef unsigned long _time_to_unsigned(object t):  # cannot_raise
     if PyFloat_Check(t):
         t = t.__int__()
-    return PyInt_AsUnsignedLongMask(t)
+    return PyLong_AsUnsignedLongMask(t)
 
 
 cdef _pack_stat(stat_value):
@@ -812,13 +812,13 @@ cdef _pack_stat(stat_value):
     cdef char result[6*4] # 6 long ints
     cdef int *aliased
     aliased = <int *>result
-    aliased[0] = htonl(PyInt_AsUnsignedLongMask(stat_value.st_size))
+    aliased[0] = htonl(PyLong_AsUnsignedLongMask(stat_value.st_size))
     # mtime and ctime will often be floats but get converted to PyInt within
     aliased[1] = htonl(_time_to_unsigned(stat_value.st_mtime))
     aliased[2] = htonl(_time_to_unsigned(stat_value.st_ctime))
-    aliased[3] = htonl(PyInt_AsUnsignedLongMask(stat_value.st_dev))
-    aliased[4] = htonl(PyInt_AsUnsignedLongMask(stat_value.st_ino))
-    aliased[5] = htonl(PyInt_AsUnsignedLongMask(stat_value.st_mode))
+    aliased[3] = htonl(PyLong_AsUnsignedLongMask(stat_value.st_dev))
+    aliased[4] = htonl(PyLong_AsUnsignedLongMask(stat_value.st_ino))
+    aliased[5] = htonl(PyLong_AsUnsignedLongMask(stat_value.st_mode))
     packed = PyBytes_FromStringAndSize(result, 6*4)
     return _encode(packed)[:-1]
 
