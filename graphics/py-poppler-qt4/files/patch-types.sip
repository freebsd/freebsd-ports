PyList_SET_ITEM() is supposed to be void, but as a macro it's an
expression and has a pointer value. Clang 4.0 trips on the bogus
pointer comparison; given the comparison, it should be PyList_SetItem()
which returns -1 on failure.

--- types.sip.orig	2017-01-21 07:19:29 UTC
+++ types.sip
@@ -27,7 +27,7 @@
     foreach (Poppler::Document::RenderBackend value, set)
     {
         PyObject *obj = PyLong_FromLong ((long) value);
-        if (obj == NULL || PyList_SET_ITEM (l, i, obj) < 0)
+        if (obj == NULL || PyList_SetItem (l, i, obj) < 0)
         {
             Py_DECREF(l);
 
