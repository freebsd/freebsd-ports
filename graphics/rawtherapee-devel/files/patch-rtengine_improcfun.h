--- ./rtengine/improcfun.h.orig	2012-01-31 05:00:05.000000000 +0400
+++ ./rtengine/improcfun.h	2012-03-31 11:46:27.000000000 +0400
@@ -19,6 +19,11 @@
 #ifndef _IMPROCFUN_H_
 #define _IMPROCFUN_H_
 
+#include <sys/param.h>
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2(x) (log(x) / M_LN2)
+#endif
+
 #include "imagefloat.h"
 #include "image16.h"
 #include "image8.h"
