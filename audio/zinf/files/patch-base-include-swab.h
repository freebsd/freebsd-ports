--- base/include/swab.h.orig	Tue Mar 18 03:53:31 2003
+++ base/include/swab.h	Mon Aug 18 17:33:34 2003
@@ -1,7 +1,10 @@
 #if !defined(_ZINF_SWAB_H)
 #define _ZINF_SWAB_H
 
+#include <inttypes.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 
 #define SWAB16(a) ( (((uint16_t)(a) << 8) & 0xFF00) | (((uint16_t)(a) >> 8) & 0x00FF) )
 #define SWAB32(a) ( (SWAB16(((a) >> 16) & 0xFFFF) << 0) | (SWAB16((a) & 0xFFFF) << 16) )
