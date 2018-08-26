--- psycopg/config.h.orig	2018-06-17 16:07:41 UTC
+++ psycopg/config.h
@@ -154,6 +154,7 @@ typedef unsigned __int64    uint64_t;
 #endif
 
 /* what's this, we have no round function either? */
+#include <sys/param.h>
 #if (defined(__FreeBSD__) && __FreeBSD_version < 503000) \
     || (defined(_WIN32) && !defined(__GNUC__)) \
     || (defined(sun) || defined(__sun__)) \
