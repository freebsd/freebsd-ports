Index: Modules/fcntlmodule.c
===================================================================
RCS file: /cvsroot/python/python/dist/src/Modules/fcntlmodule.c,v
retrieving revision 2.43
retrieving revision 2.44
diff -u -r2.43 -r2.44
--- Modules/fcntlmodule.c	30 Nov 2004 14:31:54 -0000	2.43
+++ Modules/fcntlmodule.c	27 Jul 2005 20:24:30 -0000	2.44
@@ -102,7 +102,7 @@
 	int mutate_arg = 1;
 	char buf[1024];
 
-	if (PyArg_ParseTuple(args, "O&iw#|i:ioctl",
+	if (PyArg_ParseTuple(args, "O&Iw#|i:ioctl",
                              conv_descriptor, &fd, &code, 
 			     &str, &len, &mutate_arg)) {
 		char *arg;
@@ -151,7 +151,7 @@
 	}
 
 	PyErr_Clear();
-	if (PyArg_ParseTuple(args, "O&is#:ioctl",
+	if (PyArg_ParseTuple(args, "O&Is#:ioctl",
                              conv_descriptor, &fd, &code, &str, &len)) {
 		if (len > sizeof buf) {
 			PyErr_SetString(PyExc_ValueError,
@@ -172,7 +172,7 @@
 	PyErr_Clear();
 	arg = 0;
 	if (!PyArg_ParseTuple(args,
-	     "O&i|i;ioctl requires a file or file descriptor,"
+	     "O&I|i;ioctl requires a file or file descriptor,"
 	     " an integer and optionally a integer or buffer argument",
 			      conv_descriptor, &fd, &code, &arg)) {
 	  return NULL;
