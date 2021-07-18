--- include/system.h.orig	2021-03-22 22:28:14 UTC
+++ include/system.h
@@ -82,7 +82,9 @@ typedef long off_t;
 #if !defined(__SC__) && !defined(LINUX)
 E long random(void);
 #endif
-#if (!defined(SUNOS4) && !defined(bsdi) && !defined(__FreeBSD__)) \
+# if defined(__FreeBSD__)
+#include <stdlib.h> /* srandom() differs between versions of FreeBSD. */
+#elif (!defined(SUNOS4) && !defined(bsdi) && !defined(__FreeBSD__)) \
     || defined(RANDOM)
 E void srandom(unsigned int);
 #else
