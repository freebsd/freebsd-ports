--- src/libcw/libcw_console.c.orig	2013-01-08 14:50:13.000000000 -0500
+++ src/libcw/libcw_console.c	2013-07-15 18:53:39.000000000 -0500
@@ -39,6 +39,16 @@
 #       include <sys/kbio.h>
 #endif
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+# include <sys/param.h>
+#endif
+
+#ifdef __FreeBSD__
+#include <fcntl.h>
+#include <errno.h>
+#include <assert.h>
+#endif
+
 
 #include "libcw_console.h"
 #include "libcw_debug.h"
