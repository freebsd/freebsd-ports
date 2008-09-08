--- Objects/stringobject.c.orig	2007-11-07 01:19:49.000000000 +0000
+++ Objects/stringobject.c	2008-08-30 10:16:13.000000000 +0100
@@ -71,6 +71,11 @@
 		return (PyObject *)op;
 	}
 
+	if (size > PY_SSIZE_T_MAX - sizeof(PyStringObject)) {
+		PyErr_SetString(PyExc_OverflowError, "string is too large");
+		return NULL;
+	}
+
 	/* Inline PyObject_NewVar */
 	op = (PyStringObject *)PyObject_MALLOC(sizeof(PyStringObject) + size);
 	if (op == NULL)
@@ -106,7 +111,7 @@
 
 	assert(str != NULL);
 	size = strlen(str);
-	if (size > PY_SSIZE_T_MAX) {
+	if (size > PY_SSIZE_T_MAX - sizeof(PyStringObject)) {
 		PyErr_SetString(PyExc_OverflowError,
 			"string is too long for a Python string");
 		return NULL;
@@ -967,14 +972,24 @@
 		Py_INCREF(a);
 		return (PyObject *)a;
 	}
+	/* Check that string sizes are not negative, to prevent an
+	   overflow in cases where we are passed incorrectly-created
+	   strings with negative lengths (due to a bug in other code).
+	*/
 	size = a->ob_size + b->ob_size;
-	if (size < 0) {
+	if (a->ob_size < 0 || b->ob_size < 0 ||
+	    a->ob_size > PY_SSIZE_T_MAX - b->ob_size) {
 		PyErr_SetString(PyExc_OverflowError,
 				"strings are too large to concat");
 		return NULL;
 	}
 	  
 	/* Inline PyObject_NewVar */
+	if (size > PY_SSIZE_T_MAX - sizeof(PyStringObject)) {
+		PyErr_SetString(PyExc_OverflowError,
+				"strings are too large to concat");
+		return NULL;
+	}
 	op = (PyStringObject *)PyObject_MALLOC(sizeof(PyStringObject) + size);
 	if (op == NULL)
 		return PyErr_NoMemory();
