--- Objects/stringobject.c.orig	2006-10-06 21:26:14.000000000 +0200
+++ Objects/stringobject.c
@@ -69,6 +69,11 @@ PyString_FromStringAndSize(const char *s
 		return (PyObject *)op;
 	}
 
+	if (size > INT_MAX - sizeof(PyStringObject)) {
+		PyErr_SetString(PyExc_OverflowError, "string is too large");
+		return NULL;
+	}
+
 	/* Inline PyObject_NewVar */
 	op = (PyStringObject *)PyObject_MALLOC(sizeof(PyStringObject) + size);
 	if (op == NULL)
@@ -104,7 +109,7 @@ PyString_FromString(const char *str)
 
 	assert(str != NULL);
 	size = strlen(str);
-	if (size > INT_MAX) {
+	if (size > INT_MAX - sizeof(PyStringObject)) {
 		PyErr_SetString(PyExc_OverflowError,
 			"string is too long for a Python string");
 		return NULL;
@@ -907,7 +912,18 @@ string_concat(register PyStringObject *a
 		Py_INCREF(a);
 		return (PyObject *)a;
 	}
+	/* Check that string sizes are not negative, to prevent an
+	   overflow in cases where we are passed incorrectly-created
+	   strings with negative lengths (due to a bug in other code).
+	*/
 	size = a->ob_size + b->ob_size;
+	if (a->ob_size < 0 || b->ob_size < 0 ||
+	    a->ob_size > INT_MAX - b->ob_size) {
+		PyErr_SetString(PyExc_OverflowError,
+				"strings are too large to concat");
+		return NULL;
+	}
+
 	/* Inline PyObject_NewVar */
 	op = (PyStringObject *)PyObject_MALLOC(sizeof(PyStringObject) + size);
 	if (op == NULL)
