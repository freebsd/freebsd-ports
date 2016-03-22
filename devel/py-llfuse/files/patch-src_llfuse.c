--- src/llfuse.c.orig	2016-03-20 11:33:13 UTC
+++ src/llfuse.c
@@ -33573,7 +33573,7 @@ static PyObject *__pyx_pw_6llfuse_5setxa
 }
 
 static PyObject *__pyx_pf_6llfuse_4setxattr(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_path, PyObject *__pyx_v_name, PyObject *__pyx_v_value, PyObject *__pyx_v_namespace) {
-  int __pyx_v_ret;
+  ssize_t __pyx_v_ret;
   Py_ssize_t __pyx_v_len_;
   char *__pyx_v_cvalue;
   char *__pyx_v_cpath;
