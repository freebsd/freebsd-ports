--- include/system.h.orig	2015-12-07 08:26:01 UTC
+++ include/system.h
@@ -81,7 +81,9 @@ typedef long off_t;
 #if !defined(__SC__) && !defined(LINUX)
 E long NDECL(random);
 #endif
-#if (!defined(SUNOS4) && !defined(bsdi) && !defined(__FreeBSD__)) \
+# if defined(__FreeBSD__)
+#include <stdlib.h> /* srandom() differs between versions of FreeBSD. */
+#elif (!defined(SUNOS4) && !defined(bsdi) && !defined(__FreeBSD__)) \
     || defined(RANDOM)
 E void FDECL(srandom, (unsigned int));
 #else
