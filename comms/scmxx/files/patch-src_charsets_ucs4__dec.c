
$FreeBSD$

--- src/charsets/ucs4_dec.c.orig	Thu Jul 22 18:16:40 2004
+++ src/charsets/ucs4_dec.c	Thu Jul 22 18:20:04 2004
@@ -19,6 +19,12 @@
 #include <errno.h>
 #include <iconv.h>
 
+#include <sys/param.h>
+#if __FreeBSD_version < 500000
+#include <limits.h>
+#define UINT16_MAX USHRT_MAX
+#endif
+
 #include <config.h>
 #ifndef ICONV_CAST
 #  define ICONV_CAST char**
