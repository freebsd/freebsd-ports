--- src/unicode.c.orig	Wed Feb 25 16:44:19 2004
+++ src/unicode.c	Wed Apr 21 00:00:39 2004
@@ -36,6 +36,12 @@
 #  define INTERNAL_CHARSET "UCS-4LE"
 #endif
 
+#include <sys/param.h>
+#if __FreeBSD_version < 500000
+#include <limits.h>
+#define UINT16_MAX USHRT_MAX
+#endif
+
 ucs4char_t* convert_to_internal (char* from_code,
 				 char* input,
 				 size_t insize)
