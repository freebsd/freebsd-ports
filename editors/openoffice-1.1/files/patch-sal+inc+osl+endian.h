--- ../sal/inc/osl/endian.h.orig	Thu May  8 19:38:17 2003
+++ ../sal/inc/osl/endian.h	Thu May  8 19:40:11 2003
@@ -108,13 +108,6 @@
 
 #ifdef FREEBSD
 #   include <machine/endian.h>
-#   if BYTE_ORDER == LITTLE_ENDIAN
-#   	define _LITTLE_ENDIAN
-#   elif BYTE_ORDER == BIG_ENDIAN
-#   	define _BIG_ENDIAN
-#   elif BYTE_ORDER == PDP_ENDIAN
-#   	define _PDP_ENDIAN
-#   endif
 #endif
 
 #ifdef SCO
