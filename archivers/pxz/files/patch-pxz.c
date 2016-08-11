--- pxz.c.orig	2014-10-18 17:06:27 UTC
+++ pxz.c
@@ -23,11 +23,17 @@
 
 #include <string.h>
 #include <stdio.h>
+#ifndef __FreeBSD__
 #include <stdio_ext.h>
+#endif
 #include <stdlib.h>
 #include <inttypes.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <err.h>
+#else
 #include <error.h>
+#endif
 #include <errno.h>
 #include <sys/stat.h>
 #include <sys/mman.h>
@@ -42,6 +48,10 @@
 #include <omp.h>
 #endif
 
+#ifdef __FreeBSD__
+#define error errc
+#endif
+
 #ifndef XZ_BINARY
 #define XZ_BINARY "xz"
 #endif
@@ -121,6 +131,13 @@ const struct option long_opts[] = {
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
