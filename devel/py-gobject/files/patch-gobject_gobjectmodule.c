--- gobject/gobjectmodule.c.orig	2008-06-29 19:20:31.000000000 -0400
+++ gobject/gobjectmodule.c	2008-06-29 19:21:16.000000000 -0400
@@ -2564,7 +2564,7 @@ pyg_markup_escape_text(PyObject *unused,
 {
     static char *kwlist[] = { "text", NULL };
     char *text_in, *text_out;
-    int text_size;
+    Py_ssize_t text_size;
     PyObject *retval;
 
     if (!PyArg_ParseTupleAndKeywords(args, kwargs,
