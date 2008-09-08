--- Objects/bufferobject.c.orig	2008-02-14 11:26:18.000000000 +0000
+++ Objects/bufferobject.c	2008-08-30 10:16:13.000000000 +0100
@@ -427,6 +427,10 @@
 		count = 0;
 	if (!get_buf(self, &ptr, &size, ANY_BUFFER))
 		return NULL;
+	if (count > PY_SSIZE_T_MAX / size) {
+		PyErr_SetString(PyExc_MemoryError, "result too large");
+		return NULL;
+	}
 	ob = PyString_FromStringAndSize(NULL, size * count);
 	if ( ob == NULL )
 		return NULL;
