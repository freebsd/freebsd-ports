--- inc/stdtp.h.orig	2026-02-23 10:44:29 UTC
+++ inc/stdtp.h
@@ -339,21 +339,6 @@ typedef double real8; 
  
 #define MAX_NAT8  nat8(-1)
 
-#ifndef BIG_ENDIAN
-#define BIG_ENDIAN      4321    /* most-significant byte first (IBM, net) */
-#endif
-#ifndef LITTLE_ENDIAN
-#define LITTLE_ENDIAN   1234
-#endif
-
-#ifndef BYTE_ORDER
-#if defined(__sparc__) || defined(__m68k__)
-#define BYTE_ORDER      BIG_ENDIAN 
-#else
-#define BYTE_ORDER      LITTLE_ENDIAN
-#endif
-#endif
-
 #ifdef _WIN32
 typedef HANDLE descriptor_t; 
 #else
