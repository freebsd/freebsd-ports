https://github.com/indygreg/python-zstandard/commit/7d7ff179e9a3e7569960f5167ae2729b16535f30

--- contrib/python-zstandard/c-ext/backend_c.c.orig	2025-11-13 20:57:16 UTC
+++ contrib/python-zstandard/c-ext/backend_c.c
@@ -313,7 +313,7 @@ int safe_pybytes_resize(PyObject **obj, Py_ssize_t siz
 int safe_pybytes_resize(PyObject **obj, Py_ssize_t size) {
     PyObject *tmp;
 
-    if ((*obj)->ob_refcnt == 1) {
+    if (Py_REFCNT(*obj) == 1) {
         return _PyBytes_Resize(obj, size);
     }
 
