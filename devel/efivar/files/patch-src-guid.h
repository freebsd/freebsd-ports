--- src/guid.h.orig	2014-10-15 15:48:49.000000000 +0200
+++ src/guid.h	2015-01-19 15:34:12.000000000 +0100
@@ -19,7 +19,7 @@
 #ifndef LIBEFIVAR_GUID_H
 #define LIBEFIVAR_GUID_H 1
 
-#include <endian.h>
+#include <sys/endian.h>
 #include <errno.h>
 #include <limits.h>
 #include <stdlib.h>
@@ -111,7 +111,7 @@ text_to_guid(const char *text, efi_guid_
 	strncpy(fourbytes, text+19, 4);
 	if (check_segment_sanity(fourbytes, 4) < 0)
 		return -1;
-	guid->d = bswap_16((uint16_t)strtoul(fourbytes, NULL, 16));
+	guid->d = bswap16((uint16_t)strtoul(fourbytes, NULL, 16));
 
 	/* 84be9c3e-8a32-42c0-891c-4cd3b072becc
 	 *                         ^ */
