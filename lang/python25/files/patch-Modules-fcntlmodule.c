--- Modules/fcntlmodule.c.orig	2008-08-03 20:45:34.000000000 -0400
+++ Modules/fcntlmodule.c	2010-06-24 22:22:33.000000000 -0400
@@ -97,20 +97,15 @@
 {
 #define IOCTL_BUFSZ 1024
 	int fd;
-	/* In PyArg_ParseTuple below, we use the unsigned non-checked 'I'
+	/* In PyArg_ParseTuple below, we use the unsigned non-checked 'k'
 	   format for the 'code' parameter because Python turns 0x8000000
 	   into either a large positive number (PyLong or PyInt on 64-bit
 	   platforms) or a negative number on others (32-bit PyInt)
 	   whereas the system expects it to be a 32bit bit field value
 	   regardless of it being passed as an int or unsigned long on
-	   various platforms.  See the termios.TIOCSWINSZ constant across
-	   platforms for an example of thise.
-
-	   If any of the 64bit platforms ever decide to use more than 32bits
-	   in their unsigned long ioctl codes this will break and need
-	   special casing based on the platform being built on.
+	   various platforms.
 	 */
-	unsigned int code;
+	unsigned long code;
 	int arg;
 	int ret;
 	char *str;
@@ -118,7 +113,7 @@
 	int mutate_arg = 1;
  	char buf[IOCTL_BUFSZ+1];  /* argument plus NUL byte */
 
-	if (PyArg_ParseTuple(args, "O&Iw#|i:ioctl",
+	if (PyArg_ParseTuple(args, "O&kw#|i:ioctl",
                              conv_descriptor, &fd, &code, 
 			     &str, &len, &mutate_arg)) {
 		char *arg;
@@ -169,7 +164,7 @@
 	}
 
 	PyErr_Clear();
-	if (PyArg_ParseTuple(args, "O&Is#:ioctl",
+	if (PyArg_ParseTuple(args, "O&ks#:ioctl",
                              conv_descriptor, &fd, &code, &str, &len)) {
 		if (len > IOCTL_BUFSZ) {
 			PyErr_SetString(PyExc_ValueError,
@@ -191,7 +186,7 @@
 	PyErr_Clear();
 	arg = 0;
 	if (!PyArg_ParseTuple(args,
-	     "O&I|i;ioctl requires a file or file descriptor,"
+	     "O&k|i;ioctl requires a file or file descriptor,"
 	     " an integer and optionally an integer or buffer argument",
 			      conv_descriptor, &fd, &code, &arg)) {
 	  return NULL;
