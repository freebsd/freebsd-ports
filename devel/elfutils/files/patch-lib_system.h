--- lib/system.h.orig	2014-02-05 00:21:43 UTC
+++ lib/system.h
@@ -29,6 +29,8 @@
 #ifndef LIB_SYSTEM_H
 #define LIB_SYSTEM_H	1
 
+#include <ssp/string.h>
+
 #include <argp.h>
 #include <stddef.h>
 #include <stdint.h>
@@ -36,16 +38,18 @@
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
