--- Modules/_decimal/_decimal.c.orig	2020-12-07 14:02:38 UTC
+++ Modules/_decimal/_decimal.c
@@ -3280,7 +3280,7 @@ dec_format(PyObject *dec, PyObject *args)
     }
     else {
         size_t n = strlen(spec.dot);
-        if (n > 1 || (n == 1 && !isascii((uchar)spec.dot[0]))) {
+        if (n > 1 || (n == 1 && !isascii((unsigned char)spec.dot[0]))) {
             /* fix locale dependent non-ascii characters */
             dot = dotsep_as_utf8(spec.dot);
             if (dot == NULL) {
@@ -3289,7 +3289,7 @@ dec_format(PyObject *dec, PyObject *args)
             spec.dot = PyBytes_AS_STRING(dot);
         }
         n = strlen(spec.sep);
-        if (n > 1 || (n == 1 && !isascii((uchar)spec.sep[0]))) {
+        if (n > 1 || (n == 1 && !isascii((unsigned char)spec.sep[0]))) {
             /* fix locale dependent non-ascii characters */
             sep = dotsep_as_utf8(spec.sep);
             if (sep == NULL) {
