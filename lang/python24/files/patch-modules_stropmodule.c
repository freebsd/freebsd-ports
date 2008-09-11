--- Modules/stropmodule.c.orig	2008-03-02 20:20:32.000000000 +0100
+++ Modules/stropmodule.c
@@ -214,6 +214,13 @@ strop_joinfields(PyObject *self, PyObjec
 				return NULL;
 			}
 			slen = PyString_GET_SIZE(item);
+			if (slen > INT_MAX - reslen ||
+			    seplen > INT_MAX - reslen - seplen) {
+				PyErr_SetString(PyExc_OverflowError,
+						"input too long");
+				Py_DECREF(res);
+				return NULL;
+			}
 			while (reslen + slen + seplen >= sz) {
 				if (_PyString_Resize(&res, sz * 2) < 0)
 					return NULL;
@@ -251,6 +258,14 @@ strop_joinfields(PyObject *self, PyObjec
 			return NULL;
 		}
 		slen = PyString_GET_SIZE(item);
+		if (slen > INT_MAX - reslen ||
+		    seplen > INT_MAX - reslen - seplen) {
+			PyErr_SetString(PyExc_OverflowError,
+					"input too long");
+			Py_DECREF(res);
+			Py_XDECREF(item);
+			return NULL;
+		}
 		while (reslen + slen + seplen >= sz) {
 			if (_PyString_Resize(&res, sz * 2) < 0) {
 				Py_DECREF(item);
