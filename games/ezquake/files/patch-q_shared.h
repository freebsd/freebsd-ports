--- q_shared.h.orig	2008-04-27 17:51:54.000000000 -0300
+++ q_shared.h	2008-05-06 15:08:25.000000000 -0300
@@ -161,10 +161,13 @@
 //======================= FreeBSD DEFINES ====================================
 #ifdef __FreeBSD__
 
-#if !idppc
-#define __LITTLE_ENDIAN__
-#else
-#define __BIG_ENDIAN__
+#include <machine/endian.h>
+#if BYTE_ORDER == BIG_ENDIAN
+#define __BIG_ENDIAN__ 1
+#elif BYTE_ORDER == LITTLE_ENDIAN
+#define __LITTLE_ENDIAN__ 1
+#elif BYTE_ORDER == PDP_ENDIAN
+#define __PDP_ENDIAN__ 1
 #endif
 
 #endif
