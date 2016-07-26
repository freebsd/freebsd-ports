--- base/include/swab.h.orig	2003-09-16 17:34:53 UTC
+++ base/include/swab.h
@@ -1,7 +1,10 @@
 #if !defined(_ZINF_SWAB_H)
 #define _ZINF_SWAB_H
 
+#include <inttypes.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 
 #define SWAB16(a) ( (((uint16_t)(a) << 8) & 0xFF00) | (((uint16_t)(a) >> 8) & 0x00FF) )
 #define SWAB32(a) ( (SWAB16(((a) >> 16) & 0xFFFF) << 0) | (SWAB16((a) & 0xFFFF) << 16) )
