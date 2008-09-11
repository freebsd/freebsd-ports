--- Modules/arraymodule.c.orig	2008-03-02 20:20:32.000000000 +0100
+++ Modules/arraymodule.c
@@ -814,6 +814,7 @@ static int
 array_do_extend(arrayobject *self, PyObject *bb)
 {
 	int size;
+	char *old_item;
 
 	if (!array_Check(bb))
 		return array_iter_extend(self, bb);
@@ -829,10 +830,11 @@ array_do_extend(arrayobject *self, PyObj
 			return -1;
 	}
 	size = self->ob_size + b->ob_size;
+	old_item = self->ob_item;
         PyMem_RESIZE(self->ob_item, char, size*self->ob_descr->itemsize);
         if (self->ob_item == NULL) {
-                PyObject_Del(self);
-                PyErr_NoMemory();
+		self->ob_item = old_item;
+		PyErr_NoMemory();
 		return -1;
         }
 	memcpy(self->ob_item + self->ob_size*self->ob_descr->itemsize,
@@ -884,7 +886,7 @@ array_inplace_repeat(arrayobject *self, 
 			if (size > INT_MAX / n) {
 				return PyErr_NoMemory();
 			}
-			PyMem_Resize(items, char, n * size);
+			PyMem_RESIZE(items, char, n * size);
 			if (items == NULL)
 				return PyErr_NoMemory();
 			p = items;
