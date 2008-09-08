--- Objects/longobject.c.orig	2007-05-07 19:30:48.000000000 +0100
+++ Objects/longobject.c	2008-08-30 10:16:13.000000000 +0100
@@ -70,6 +70,8 @@
 		PyErr_NoMemory();
 		return NULL;
 	}
+	/* XXX(nnorwitz): This can overflow --
+	   PyObject_NEW_VAR /  _PyObject_VAR_SIZE need to detect overflow */
 	return PyObject_NEW_VAR(PyLongObject, &PyLong_Type, size);
 }
 
