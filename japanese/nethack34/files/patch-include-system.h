--- include/system.h.orig	2014-08-28 14:59:56.000000000 +0900
+++ include/system.h	2014-08-28 15:15:45.000000000 +0900
@@ -79,7 +79,9 @@
 # if !defined(__SC__) && !defined(LINUX)
 E  long NDECL(random);
 # endif
-# if (!defined(SUNOS4) && !defined(bsdi) && !defined(__FreeBSD__)) || defined(RANDOM)
+# if defined(__FreeBSD__)
+#include <stdlib.h> /* srandom() differs between versions of FreeBSD. */
+# elif (!defined(SUNOS4) && !defined(bsdi) && !defined(__FreeBSD__)) || defined(RANDOM)
 E void FDECL(srandom, (unsigned int));
 # else
 #  if !defined(bsdi) && !defined(__FreeBSD__)
