
$FreeBSD$

--- config.h.orig	Mon Jan 24 01:18:02 2000
+++ config.h	Sat Oct 26 23:24:50 2002
@@ -359,3 +359,7 @@
   #include <errno.h>
   #define PI 3.14159265358979323846
 #endif
+
+#ifdef __FreeBSD__
+#define PI 3.14159265358979323846
+#endif
