--- python/lcms_wrap.cxx.orig	2009-10-13 14:48:08.000000000 +0400
+++ python/lcms_wrap.cxx	2009-10-13 14:48:48.000000000 +0400
@@ -2958,7 +2958,7 @@
 {
   if (PyString_Check(obj)) {
     char *cstr; Py_ssize_t len;
-    PyString_AsStringAndSize(obj, &cstr, &len);
+    PyString_AsStringAndSize(obj, &cstr, (Py_ssize_t *)&len);
     if (cptr)  {
       if (alloc) {
 	/* 
