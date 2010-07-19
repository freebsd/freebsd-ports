--- Modules/fcntlmodule.c.orig	2009-05-24 11:46:13.000000000 -0400
+++ Modules/fcntlmodule.c	2010-06-24 22:30:32.000000000 -0400
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
 	Py_buffer pstr;
@@ -119,7 +114,7 @@
 	int mutate_arg = 1;
  	char buf[IOCTL_BUFSZ+1];  /* argument plus NUL byte */
 
-	if (PyArg_ParseTuple(args, "O&Iw*|i:ioctl",
+	if (PyArg_ParseTuple(args, "O&kw*|i:ioctl",
                              conv_descriptor, &fd, &code, 
 			     &pstr, &mutate_arg)) {
 		char *arg;
@@ -174,7 +169,7 @@
 	}
 
 	PyErr_Clear();
-	if (PyArg_ParseTuple(args, "O&Is*:ioctl",
+	if (PyArg_ParseTuple(args, "O&ks*:ioctl",
                              conv_descriptor, &fd, &code, &pstr)) {
 		str = pstr.buf;
 		len = pstr.len;
@@ -201,7 +196,7 @@
 	PyErr_Clear();
 	arg = 0;
 	if (!PyArg_ParseTuple(args,
-	     "O&I|i;ioctl requires a file or file descriptor,"
+	     "O&k|i;ioctl requires a file or file descriptor,"
 	     " an integer and optionally an integer or buffer argument",
 			      conv_descriptor, &fd, &code, &arg)) {
 	  return NULL;
