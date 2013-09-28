--- ../../src/dmd/root/port.c.orig	2013-06-12 22:42:08.000000000 -0700
+++ ../../src/dmd/root/port.c	2013-09-27 17:56:26.292841909 -0700
@@ -406,7 +406,7 @@
 #else
     return __inline_isnan(r);
 #endif
-#elif __OpenBSD__
+#elif __OpenBSD__ || __FreeBSD__
     return isnan(r);
 #else
     #undef isnan
@@ -422,7 +422,7 @@
 #else
     return __inline_isnan(r);
 #endif
-#elif __OpenBSD__
+#elif __OpenBSD__ || __FreeBSD__
     return isnan(r);
 #else
     #undef isnan
@@ -456,7 +456,7 @@
 {
 #if __APPLE__
     return fpclassify(r) == FP_INFINITE;
-#elif __OpenBSD__
+#elif __OpenBSD__ || __FreeBSD__
     return isinf(r);
 #else
     #undef isinf
