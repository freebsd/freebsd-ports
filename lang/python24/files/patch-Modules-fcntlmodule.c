--- Modules/fcntlmodule.c.orig	2006-09-27 15:17:32.000000000 -0400
+++ Modules/fcntlmodule.c	2010-06-24 21:15:48.000000000 -0400
@@ -95,7 +95,7 @@
 {
 #define IOCTL_BUFSZ 1024
 	int fd;
-	int code;
+	unsigned long code;
 	int arg;
 	int ret;
 	char *str;
@@ -103,7 +103,7 @@
 	int mutate_arg = 0;
 	char buf[IOCTL_BUFSZ+1];  /* argument plus NUL byte */
 
-	if (PyArg_ParseTuple(args, "O&iw#|i:ioctl",
+	if (PyArg_ParseTuple(args, "O&kw#|i:ioctl",
                              conv_descriptor, &fd, &code, 
 			     &str, &len, &mutate_arg)) {
 		char *arg;
@@ -164,7 +164,7 @@
 	}
 
 	PyErr_Clear();
-	if (PyArg_ParseTuple(args, "O&is#:ioctl",
+	if (PyArg_ParseTuple(args, "O&ks#:ioctl",
                              conv_descriptor, &fd, &code, &str, &len)) {
 		if (len > IOCTL_BUFSZ) {
 			PyErr_SetString(PyExc_ValueError,
@@ -186,7 +186,7 @@
 	PyErr_Clear();
 	arg = 0;
 	if (!PyArg_ParseTuple(args,
-	     "O&i|i;ioctl requires a file or file descriptor,"
+	     "O&k|i;ioctl requires a file or file descriptor,"
 	     " an integer and optionally a integer or buffer argument",
 			      conv_descriptor, &fd, &code, &arg)) {
 	  return NULL;
