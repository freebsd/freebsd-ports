--- ./source/jaudiolib/util.h.orig	Wed Aug  2 00:35:30 2006
+++ ./source/jaudiolib/util.h	Wed Aug  2 00:35:30 2006
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
