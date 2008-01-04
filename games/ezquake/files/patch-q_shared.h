--- q_shared.h.orig	Fri Jan  4 10:53:25 2008
+++ q_shared.h	Fri Jan  4 11:10:59 2008
@@ -32,6 +32,17 @@
 #include <ctype.h>
 #include <assert.h>
 
+#ifdef __FreeBSD__
+#include <machine/endian.h>
+#if BYTE_ORDER == BIG_ENDIAN
+#define __BIG_ENDIAN__ 1
+#elif BYTE_ORDER == LITTLE_ENDIAN
+#define __LITTLE_ENDIAN__ 1
+#elif BYTE_ORDER == PDP_ENDIAN
+#define __PDP_ENDIAN__ 1
+#endif
+#endif
+
 #define wchar unsigned short	// 16-bit Unicode char
 
 #include "mathlib.h"
