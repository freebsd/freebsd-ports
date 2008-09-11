--- Modules/almodule.c.orig	2006-09-27 21:17:32.000000000 +0200
+++ Modules/almodule.c
@@ -1633,9 +1633,11 @@ al_QueryValues(PyObject *self, PyObject 
 	if (nvals < 0)
 		goto cleanup;
 	if (nvals > setsize) {
+		ALvalue *old_return_set = return_set;
 		setsize = nvals;
 		PyMem_RESIZE(return_set, ALvalue, setsize);
 		if (return_set == NULL) {
+			return_set = old_return_set;
 			PyErr_NoMemory();
 			goto cleanup;
 		}
