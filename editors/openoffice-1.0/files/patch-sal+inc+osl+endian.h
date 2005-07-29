--- sal/inc/osl/endian.h.orig	Thu May  8 20:19:09 2003
+++ sal/inc/osl/endian.h	Thu May  8 20:29:00 2003
@@ -107,7 +107,9 @@
 #endif
 
 #ifdef FREEBSD
+#   include <sys/param.h>
 #   include <machine/endian.h>
+#if __FreeBSD_version < 500000
 #   if BYTE_ORDER == LITTLE_ENDIAN
 #   	define _LITTLE_ENDIAN
 #   elif BYTE_ORDER == BIG_ENDIAN
@@ -115,6 +117,7 @@
 #   elif BYTE_ORDER == PDP_ENDIAN
 #   	define _PDP_ENDIAN
 #   endif
+#endif
 #endif
 
 #ifdef SCO
