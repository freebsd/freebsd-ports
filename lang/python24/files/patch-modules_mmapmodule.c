--- Modules/mmapmodule.c.orig	2008-08-05 12:00:52.000000000 +0200
+++ Modules/mmapmodule.c
@@ -223,7 +223,7 @@ mmap_read_method(mmap_object *self,
 		return(NULL);
 
 	/* silently 'adjust' out-of-range requests */
-	if ((self->pos + num_bytes) > self->size) {
+	if (num_bytes > self->size - self->pos) {
 		num_bytes -= (self->pos+num_bytes) - self->size;
 	}
 	result = Py_BuildValue("s#", self->data+self->pos, num_bytes);
