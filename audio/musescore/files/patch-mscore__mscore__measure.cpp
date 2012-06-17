--- mscore/mscore/measure.cpp.orig	2012-03-13 22:32:27.000000000 +0900
+++ mscore/mscore/measure.cpp	2012-06-09 13:58:36.000000000 +0900
@@ -77,6 +77,11 @@
 #include "spacer.h"
 #include "duration.h"
 
+#include <sys/param.h>
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2(x) (log(x)/log(2.0))
+#endif
+
 //---------------------------------------------------------
 //   MStaff
 //---------------------------------------------------------
