--- Modules/stropmodule.c.orig	2008-02-14 11:26:18.000000000 +0000
+++ Modules/stropmodule.c	2008-08-30 10:16:13.000000000 +0100
@@ -216,6 +216,13 @@
 				return NULL;
 			}
 			slen = PyString_GET_SIZE(item);
+			if (slen > PY_SSIZE_T_MAX - reslen ||
+			    seplen > PY_SSIZE_T_MAX - reslen - seplen) {
+				PyErr_SetString(PyExc_OverflowError,
+						"input too long");
+				Py_DECREF(res);
+				return NULL;
+			}
 			while (reslen + slen + seplen >= sz) {
 				if (_PyString_Resize(&res, sz * 2) < 0)
 					return NULL;
@@ -253,6 +260,14 @@
 			return NULL;
 		}
 		slen = PyString_GET_SIZE(item);
+		if (slen > PY_SSIZE_T_MAX - reslen ||
+		    seplen > PY_SSIZE_T_MAX - reslen - seplen) {
+			PyErr_SetString(PyExc_OverflowError,
+					"input too long");
+			Py_DECREF(res);
+			Py_XDECREF(item);
+			return NULL;
+		}
 		while (reslen + slen + seplen >= sz) {
 			if (_PyString_Resize(&res, sz * 2) < 0) {
 				Py_DECREF(item);
