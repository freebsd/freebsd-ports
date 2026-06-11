--- bytesex.h.orig	2003-08-09 16:42:24 UTC
+++ bytesex.h
@@ -3,15 +3,11 @@
 #ifndef S10SH_BYTESEX_H
 #define S10SH_BYTESEX_H
 
-#if 	defined(__i386__) \
-	|| defined(__alpha__) \
-	|| (defined(__mips__) && (defined(MIPSEL) || defined (__MIPSEL__)))
+#include <endian.h>
+
+#if BYTE_ORDER == LITTLE_ENDIAN
 #define BYTE_ORDER_LITTLE_ENDIAN
-#elif 	defined(__mc68000__) \
-	|| defined (__sparc__) \
-	|| defined (__sparc) \
-	|| defined (__PPC__) \
-	|| (defined(__mips__) && (defined(MIPSEB) || defined (__MIPSEB__)))
+#elif BYTE_ORDER == BIG_ENDIAN
 #define BYTE_ORDER_BIG_ENDIAN
 #else
 # error can not find the byte order for this architecture, fix bytesex.h
