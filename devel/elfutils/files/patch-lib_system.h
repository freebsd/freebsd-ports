--- lib/system.h.orig	2016-12-28 09:32:00 UTC
+++ lib/system.h
@@ -33,6 +33,8 @@
 # include <config.h>
 #endif
 
+#include <ssp/string.h>
+
 #include <argp.h>
 #include <errno.h>
 #include <stddef.h>
@@ -42,16 +44,18 @@
 #include <byteswap.h>
 #include <unistd.h>
 
+#include <eu-config.h>
+
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 # define LE32(n)	(n)
 # define LE64(n)	(n)
-# define BE32(n)	bswap_32 (n)
-# define BE64(n)	bswap_64 (n)
+# define BE32(n)	bswap32 (n)
+# define BE64(n)	bswap64 (n)
 #elif __BYTE_ORDER == __BIG_ENDIAN
 # define BE32(n)	(n)
 # define BE64(n)	(n)
-# define LE32(n)	bswap_32 (n)
-# define LE64(n)	bswap_64 (n)
+# define LE32(n)	bswap32 (n)
+# define LE64(n)	bswap64 (n)
 #else
 # error "Unknown byte order"
 #endif
