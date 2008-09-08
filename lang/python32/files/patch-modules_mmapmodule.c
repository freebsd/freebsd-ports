--- Modules/mmapmodule.c.orig	2006-08-22 14:57:07.000000000 +0100
+++ Modules/mmapmodule.c	2008-08-30 10:16:13.000000000 +0100
@@ -223,7 +223,7 @@
 		return(NULL);
 
 	/* silently 'adjust' out-of-range requests */
-	if ((self->pos + num_bytes) > self->size) {
+	if (num_bytes > self->size - self->pos) {
 		num_bytes -= (self->pos+num_bytes) - self->size;
 	}
 	result = Py_BuildValue("s#", self->data+self->pos, num_bytes);
