--- src/endian.h.orig	Mon Nov  9 08:22:55 1998
+++ src/endian.h	Fri Jun 30 19:49:16 2000
@@ -16,7 +16,7 @@
 #define big_endian 1
 #endif
 
-#elif defined (linux) || defined (sun) || defined (FreeBSD)
+#elif defined (linux) || defined (sun) || defined (__FreeBSD__)
 
 #if BYTE_ORDER==LITTLE_ENDIAN
 #define little_endian 1
