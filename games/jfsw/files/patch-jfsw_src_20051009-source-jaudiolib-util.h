--- jfsw_src_20051009/source/jaudiolib/util.h.orig	1970-01-01 01:00:00.000000000 +0100
+++ jfsw_src_20051009/source/jaudiolib/util.h	2005-10-10 15:02:08.000000000 +0200
@@ -0,0 +1,12 @@
+#ifndef AUDIOLIB__UTIL_H
+#define AUDIOLIB__UTIL_H
+
+#ifndef min
+#define min(a, b)  ((a) < (b) ? (a) : (b))
+#endif
+
+#ifndef max
+#define max(a, b)  ((a) > (b) ? (a) : (b))
+#endif
+
+#endif
