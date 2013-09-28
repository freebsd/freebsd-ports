--- ../../src/dmd/root/port.c.orig	2012-12-31 12:16:46.000000000 -0800
+++ ../../src/dmd/root/port.c	2013-09-27 22:41:16.360128824 -0700
@@ -386,7 +386,7 @@
 #else
     return __inline_isnan(r);
 #endif
-#elif __OpenBSD__
+#elif __OpenBSD__ || __FreeBSD__
     return isnan(r);
 #else
     #undef isnan
@@ -402,7 +402,7 @@
 #else
     return __inline_isnan(r);
 #endif
-#elif __OpenBSD__
+#elif __OpenBSD__ || __FreeBSD__
     return isnan(r);
 #else
     #undef isnan
@@ -436,7 +436,7 @@
 {
 #if __APPLE__
     return fpclassify(r) == FP_INFINITE;
-#elif __OpenBSD__
+#elif __OpenBSD__ || __FreeBSD__
     return isinf(r);
 #else
     #undef isinf
