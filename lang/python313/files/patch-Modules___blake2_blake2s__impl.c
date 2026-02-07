--- Modules/_blake2/blake2s_impl.c.orig	2025-10-14 13:52:31 UTC
+++ Modules/_blake2/blake2s_impl.c
@@ -103,10 +103,10 @@ py_blake2s_new_impl(PyTypeObject *type, PyObject *data
 {
     BLAKE2sObject *self = NULL;
     PyObject *data;
+    Py_buffer buf;
     if (_Py_hashlib_data_argument(&data, data_obj, string) < 0) {
         return NULL;
     }
-    Py_buffer buf;
 
     self = new_BLAKE2sObject(type);
     if (self == NULL) {
