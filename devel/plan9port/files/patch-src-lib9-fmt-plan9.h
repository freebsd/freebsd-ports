--- src/lib9/fmt/plan9.h.orig	Fri Dec 30 14:00:49 2005
+++ src/lib9/fmt/plan9.h	Sat Jan  7 00:15:40 2006
@@ -1,4 +1,13 @@
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
 
 /*
  * compiler directive on Plan 9
