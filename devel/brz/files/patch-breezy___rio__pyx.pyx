--- breezy/_rio_pyx.pyx.orig	2021-12-07 02:24:26 UTC
+++ breezy/_rio_pyx.pyx
@@ -31,10 +31,6 @@ from cpython.unicode cimport (
 from cpython.unicode cimport (
     PyUnicode_CheckExact,
     PyUnicode_DecodeUTF8,
-    # Deprecated after PEP 393 changes
-    PyUnicode_AS_UNICODE,
-    PyUnicode_FromUnicode,
-    PyUnicode_GET_SIZE,
     )
 from cpython.list cimport (
     PyList_Append,
@@ -44,15 +40,9 @@ from cpython.mem cimport (
     PyMem_Malloc,
     PyMem_Realloc,
     )
-from cpython.version cimport (
-    PY_MAJOR_VERSION,
-    )
 
 cdef extern from "Python.h":
     ctypedef int Py_UNICODE
-    object PyUnicode_EncodeASCII(Py_UNICODE *, int, char *)
-    int Py_UNICODE_ISLINEBREAK(Py_UNICODE)
-
     # GZ 2017-09-11: Not sure why cython unicode module lacks this?
     object PyUnicode_FromStringAndSize(const char *u, Py_ssize_t size)
 
@@ -74,19 +64,13 @@ def _valid_tag(tag):
 
 
 def _valid_tag(tag):
-    cdef char *c_tag
+    cdef const char *c_tag
     cdef Py_ssize_t c_len
     cdef int i
     # GZ 2017-09-11: Encapsulate native string as ascii tag somewhere neater
-    if PY_MAJOR_VERSION >= 3:
-        if not PyUnicode_CheckExact(tag):
-            raise TypeError(tag)
-        c_tag = PyUnicode_AsUTF8AndSize(tag, &c_len)
-    else:
-        if not PyBytes_CheckExact(tag):
-            raise TypeError(tag)
-        c_tag = PyBytes_AS_STRING(tag)
-        c_len = PyBytes_GET_SIZE(tag)
+    if not PyUnicode_CheckExact(tag):
+        raise TypeError(tag)
+    c_tag = PyUnicode_AsUTF8AndSize(tag, &c_len)
     if c_len < 1:
         return False
     for i from 0 <= i < c_len:
@@ -104,27 +88,8 @@ cdef object _split_first_line_utf8(char *line, int len
                 raise ValueError("invalid tag in line %r" % line)
             memcpy(value, line+i+2, len-i-2)
             value_len[0] = len-i-2
-            if PY_MAJOR_VERSION >= 3:
-                return PyUnicode_FromStringAndSize(line, i)
-            return PyBytes_FromStringAndSize(line, i)
+            return PyUnicode_DecodeUTF8(line, i, "strict")
     raise ValueError('tag/value separator not found in line %r' % line)
-
-
-cdef object _split_first_line_unicode(Py_UNICODE *line, int len,
-                                      Py_UNICODE *value, Py_ssize_t *value_len):
-    cdef int i
-    for i from 0 <= i < len:
-        if line[i] == c':':
-            if line[i+1] != c' ':
-                raise ValueError("invalid tag in line %r" %
-                                 PyUnicode_FromUnicode(line, len))
-            memcpy(value, &line[i+2], (len-i-2) * sizeof(Py_UNICODE))
-            value_len[0] = len-i-2
-            if PY_MAJOR_VERSION >= 3:
-                return PyUnicode_FromUnicode(line, i)
-            return PyUnicode_EncodeASCII(line, i, "strict")
-    raise ValueError("tag/value separator not found in line %r" %
-                     PyUnicode_FromUnicode(line, len))
 
 
 def _read_stanza_utf8(line_iter):
