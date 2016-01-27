--- iputils.hh.orig	2016-01-13 10:18:24 UTC
+++ iputils.hh
@@ -59,6 +59,11 @@
 #define le64toh(x) OSSwapLittleToHostInt64(x)
 #endif
 
+// for FreeBSD
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#endif
+
 // for illumos
 #ifdef BE_64
 
