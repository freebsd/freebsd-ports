
$FreeBSD$

--- zzip-stdint.h.orig	Sun Dec 22 13:59:40 2002
+++ zzip-stdint.h	Sun Dec 22 14:00:28 2002
@@ -13,6 +13,8 @@
 #ifdef ZZIP_HAVE_STDINT_H
     /* ISO C 9X: 7.18 Integer types <stdint.h> */
 #include <stdint.h>
+#elif defined ZZIP_HAVE_INTTYPES_H	/* FreeBSD 4.x */
+#include <inttypes.h>
 #elif defined ZZIP_HAVE_SYS_INT_TYPES_H /*solaris*/
 #include <sys/int_types.h>
 #else
