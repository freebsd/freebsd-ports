--- Modules/selectmodule.c.orig	2006-09-27 21:17:32.000000000 +0200
+++ Modules/selectmodule.c
@@ -342,10 +342,12 @@ update_ufd_array(pollObject *self)
 {
 	int i, pos;
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
