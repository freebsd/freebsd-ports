--- pxz.c.orig	2010-11-23 10:35:25.720939440 +0100
+++ pxz.c	2010-11-23 10:46:28.910235910 +0100
@@ -21,11 +21,17 @@
 
 #include <string.h>
 #include <stdio.h>
-#include <stdio_ext.h>
+#ifndef __FreeBSD__
+#include <stdio_ext.h>
+#endif
 #include <stdlib.h>
 #include <inttypes.h>
 #include <unistd.h>
-#include <error.h>
+#ifdef __FreeBSD__
+#include <err.h>
+#else
+#include <error.h>
+#endif
 #include <errno.h>
 #include <sys/stat.h>
 #include <sys/mman.h>
@@ -40,6 +46,10 @@
 #include <omp.h>
 #endif
 
+#ifdef __FreeBSD__
+#define error errc
+#endif
+
 #ifndef XZ_BINARY
 #define XZ_BINARY "xz"
 #endif
@@ -119,6 +129,13 @@
 	{ NULL,             0,                 NULL,   0 }
 };
 
+#ifdef __FreeBSD__
+static size_t __fpending (FILE *fp)
+{
+	return (fp->_p - fp->_bf._base);
+}
+#endif
+
 void __attribute__((noreturn)) run_xz( char **argv ) {
 	execvp(XZ_BINARY, argv);
 	error(0, errno, "execution of "XZ_BINARY" binary failed");
