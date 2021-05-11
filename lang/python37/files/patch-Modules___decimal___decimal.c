--- Modules/_decimal/_decimal.c.orig	2021-02-17 21:21:24 UTC
+++ Modules/_decimal/_decimal.c
@@ -58,6 +58,11 @@
 
 #define BOUNDS_CHECK(x, MIN, MAX) x = (x < MIN || MAX < x) ? MAX : x
 
+#if defined(__GNUC__) && !defined(__INTEL_COMPILER)
+  #define UNUSED __attribute__((unused))
+#else
+  #define UNUSED
+#endif
 
 /* _Py_DEC_MINALLOC >= MPD_MINALLOC */
 #define _Py_DEC_MINALLOC 4
@@ -3277,7 +3282,7 @@ dec_format(PyObject *dec, PyObject *args)
     }
     else {
         size_t n = strlen(spec.dot);
-        if (n > 1 || (n == 1 && !isascii((uchar)spec.dot[0]))) {
+        if (n > 1 || (n == 1 && !isascii((unsigned char)spec.dot[0]))) {
             /* fix locale dependent non-ascii characters */
             dot = dotsep_as_utf8(spec.dot);
             if (dot == NULL) {
@@ -3286,7 +3291,7 @@ dec_format(PyObject *dec, PyObject *args)
             spec.dot = PyBytes_AS_STRING(dot);
         }
         n = strlen(spec.sep);
-        if (n > 1 || (n == 1 && !isascii((uchar)spec.sep[0]))) {
+        if (n > 1 || (n == 1 && !isascii((unsigned char)spec.sep[0]))) {
             /* fix locale dependent non-ascii characters */
             sep = dotsep_as_utf8(spec.sep);
             if (sep == NULL) {
