--- Objects/bufferobject.c.orig	2008-03-02 20:20:32.000000000 +0100
+++ Objects/bufferobject.c
@@ -384,6 +384,10 @@ buffer_repeat(PyBufferObject *self, int 
 		count = 0;
 	if (!get_buf(self, &ptr, &size))
 		return NULL;
+	if (count > INT_MAX / size) {
+		PyErr_SetString(PyExc_MemoryError, "result too large");
+		return NULL;
+	}
 	ob = PyString_FromStringAndSize(NULL, size * count);
 	if ( ob == NULL )
 		return NULL;
