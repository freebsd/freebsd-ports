--- src/cmd/eqn/e.h.orig	Sat Dec 31 14:00:37 2005
+++ src/cmd/eqn/e.h	Sat Jan  7 00:16:57 2006
@@ -2,7 +2,16 @@
 #include <stdlib.h>
 #include <string.h>
 #include <errno.h>
+#if defined(__FreeBSD__)
+#if __FreeBSD__ >= 2
+#include <osreldate.h>
+#if __FreeBSD_version < 500000
+#include <inttypes.h>
+#else
 #include <stdint.h>
+#endif
+#endif
+#endif
 
 #undef sqrt
 #define sqrt p9_sqrt
