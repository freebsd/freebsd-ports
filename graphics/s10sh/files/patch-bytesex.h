--- bytesex.h.orig	Sat Mar 17 22:27:18 2007
+++ bytesex.h	Sat Mar 17 22:30:35 2007
@@ -5,7 +5,8 @@
 
 #if 	defined(__i386__) \
 	|| defined(__alpha__) \
-	|| (defined(__mips__) && (defined(MIPSEL) || defined (__MIPSEL__)))
+	|| (defined(__mips__) && (defined(MIPSEL) || defined (__MIPSEL__))) \
+	|| defined(__amd64__) || defined(__ia64__)
 #define BYTE_ORDER_LITTLE_ENDIAN
 #elif 	defined(__mc68000__) \
 	|| defined (__sparc__) \
