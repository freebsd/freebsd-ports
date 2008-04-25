--- Modules/zlibmodule.c.orig	2008-04-25 01:47:26.000000000 +0200
+++ Modules/zlibmodule.c	2008-04-25 01:48:17.000000000 +0200
@@ -774,6 +774,10 @@
 
     if (!PyArg_ParseTuple(args, "|i:flush", &length))
 	return NULL;
+    if (length <= 0) {
+	PyErr_SetString(PyExc_ValueError, "length must be greater than zero");
+	return NULL;
+	}
     if (!(retval = PyString_FromStringAndSize(NULL, length)))
 	return NULL;
 
