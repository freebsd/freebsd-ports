--- src/sha1.h.orig	Fri Jan 30 21:43:41 2004
+++ src/sha1.h	Fri Jan 30 21:45:58 2004
@@ -26,10 +26,7 @@
 #ifndef NETTLE_SHA1_H_INCLUDED
 #define NETTLE_SHA1_H_INCLUDED
 
-#ifndef _STDINT_H
-typedef unsigned int uint32_t;
-typedef unsigned char uint8_t;
-#endif
+#include <sys/types.h>
 
 #define SHA1_DIGEST_SIZE 20
 #define SHA1_DATA_SIZE 64
