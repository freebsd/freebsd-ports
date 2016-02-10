--- src/dnssec/lib/binary.c.orig	2016-02-08 15:31:05 UTC
+++ src/dnssec/lib/binary.c
@@ -22,18 +22,7 @@
 #include "error.h"
 #include "shared.h"
 
-typedef
-#ifdef HAVE_NETTLE_VERSION_H
-	#include <nettle/version.h>
-	#if NETTLE_VERSION_MAJOR >= 3
-		size_t
-	#else
-		unsigned
-	#endif
-#else
-	unsigned
-#endif
-nettle_len;
+typedef size_t nettle_len;
 
 static size_t base64_decode_raw(const uint8_t *src, size_t src_len,
 				uint8_t *dst, size_t dst_max_size)
