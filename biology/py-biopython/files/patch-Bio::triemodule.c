--- Bio/triemodule.c.orig	Thu Dec  2 14:44:14 2004
+++ Bio/triemodule.c	Thu Dec  2 14:47:57 2004
@@ -477,7 +477,11 @@
     int length;
     int success = 0;
 
+#ifdef Py_MARSHAL_VERSION
+    if(!(py_marshalled = PyMarshal_WriteObjectToString(py_value, Py_MARSHAL_VERSION)))
+#else
     if(!(py_marshalled = PyMarshal_WriteObjectToString(py_value)))
+#endif
 	goto _write_value_to_handle_cleanup;
     if(PyString_AsStringAndSize(py_marshalled, &marshalled, &length) == -1)
 	goto _write_value_to_handle_cleanup;
