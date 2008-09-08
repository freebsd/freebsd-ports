--- Modules/almodule.c.orig	2006-09-25 07:53:42.000000000 +0100
+++ Modules/almodule.c	2008-08-30 10:39:43.000000000 +0100
@@ -1633,9 +1633,11 @@
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
