--- src/pyvorbisfile.c.orig	Mon Sep 23 16:35:18 2002
+++ src/pyvorbisfile.c	Mon Sep 23 16:37:20 2002
@@ -1,5 +1,17 @@
 #include <stdio.h>
+
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
+#if (defined(BSD))
+#include <machine/endian.h>
+#define __BYTE_ORDER BYTE_ORDER
+#define __BIG_ENDIAN BIG_ENDIAN
+#else
 #include <endian.h>
+#endif
+
 #include <assert.h>
 
 #include "general.h"
