--- src/endian.h.orig	1998-11-08 23:22:55 UTC
+++ src/endian.h
@@ -16,7 +16,7 @@ typedef unsigned short u_int16_t;
 #define big_endian 1
 #endif
 
-#elif defined (linux) || defined (sun) || defined (FreeBSD)
+#elif defined (linux) || defined (sun) || defined (__FreeBSD__)
 
 #if BYTE_ORDER==LITTLE_ENDIAN
 #define little_endian 1
