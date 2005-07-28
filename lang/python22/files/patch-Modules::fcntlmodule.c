--- Modules/fcntlmodule.c.orig	Sat Jan 12 20:13:23 2002
+++ Modules/fcntlmodule.c	Thu Jul 28 16:10:26 2005
@@ -100,7 +100,7 @@
 	int len;
 	char buf[1024];
 
-	if (PyArg_ParseTuple(args, "O&is#:ioctl",
+	if (PyArg_ParseTuple(args, "O&Is#:ioctl",
                              conv_descriptor, &fd, &code, &str, &len)) {
 		if (len > sizeof buf) {
 			PyErr_SetString(PyExc_ValueError,
@@ -121,7 +121,7 @@
 	PyErr_Clear();
 	arg = 0;
 	if (!PyArg_ParseTuple(args,
-	     "O&i|i;ioctl requires a file or file descriptor,"
+	     "O&I|i;ioctl requires a file or file descriptor,"
 	     " an integer and optionally a third integer or a string",
 			      conv_descriptor, &fd, &code, &arg)) {
 	  return NULL;
