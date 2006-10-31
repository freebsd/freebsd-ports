--- ./dump.c.orig	Sun May 29 23:48:57 2005
+++ ./dump.c	Mon Oct  9 23:53:07 2006
@@ -36,6 +36,12 @@
 #include <assert.h>
 #include "slump.h"
 
+#include <machine/endian.h>
+
+#if BYTE_ORDER == BIG_ENDIAN
+#define ENDIAN_BIG
+#endif
+
 /* Global variables */
 
 extern int current_level_number;
