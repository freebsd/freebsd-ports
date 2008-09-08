--- Modules/arraymodule.c.orig	2008-02-15 19:11:46.000000000 +0000
+++ Modules/arraymodule.c	2008-08-30 10:39:43.000000000 +0100
@@ -816,6 +816,7 @@
 array_do_extend(arrayobject *self, PyObject *bb)
 {
 	Py_ssize_t size;
+	char *old_item;
 
 	if (!array_Check(bb))
 		return array_iter_extend(self, bb);
@@ -831,10 +832,11 @@
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
@@ -886,7 +888,7 @@
 			if (size > PY_SSIZE_T_MAX / n) {
 				return PyErr_NoMemory();
 			}
-			PyMem_Resize(items, char, n * size);
+			PyMem_RESIZE(items, char, n * size);
 			if (items == NULL)
 				return PyErr_NoMemory();
 			p = items;
