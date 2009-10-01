--- src/common/bswap.h.orig	2009-09-29 20:25:24.000000000 +0200
+++ src/common/bswap.h	2009-09-29 20:27:50.000000000 +0200
@@ -23,21 +23,35 @@
 #ifdef HAVE_BYTESWAP_H
 #	include <byteswap.h>
 #endif
+#ifdef HAVE_SYS_ENDIAN_H
+#	include <sys/endian.h>
+#endif
 
 #ifndef HAVE_BSWAP_16
+#	ifdef HAVE_BSWAP16
+#	define bswap_16 bswap16
+#	else
 #	define bswap_16(num) \
 		(((num) << 8) | ((num) >> 8))
+#	endif
 #endif
 
 #ifndef HAVE_BSWAP_32
+#	ifdef HAVE_BSWAP32
+#	define bswap_32 bswap32
+#	else
 #	define bswap_32(num) \
 		( (((num) << 24)                       ) \
 		| (((num) <<  8) & UINT32_C(0x00FF0000)) \
 		| (((num) >>  8) & UINT32_C(0x0000FF00)) \
 		| (((num) >> 24)                       ) )
+#	endif
 #endif
 
 #ifndef HAVE_BSWAP_64
+#	ifdef HAVE_BSWAP64
+#	define bswap_64 bswap64
+#	else
 #	define bswap_64(num) \
 		( (((num) << 56)                               ) \
 		| (((num) << 40) & UINT64_C(0x00FF000000000000)) \
@@ -47,6 +61,7 @@
 		| (((num) >> 24) & UINT64_C(0x0000000000FF0000)) \
 		| (((num) >> 40) & UINT64_C(0x000000000000FF00)) \
 		| (((num) >> 56)                               ) )
+#	endif
 #endif
 
 #endif
