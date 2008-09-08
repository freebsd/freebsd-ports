--- Modules/selectmodule.c.orig	2006-07-10 02:18:57.000000000 +0100
+++ Modules/selectmodule.c	2008-08-30 10:39:43.000000000 +0100
@@ -349,10 +349,12 @@
 {
 	Py_ssize_t i, pos;
 	PyObject *key, *value;
+        struct pollfd *old_ufds = self->ufds;
 
 	self->ufd_len = PyDict_Size(self->dict);
-	PyMem_Resize(self->ufds, struct pollfd, self->ufd_len);
+	PyMem_RESIZE(self->ufds, struct pollfd, self->ufd_len);
 	if (self->ufds == NULL) {
+                self->ufds = old_ufds;
 		PyErr_NoMemory();
 		return 0;
 	}
