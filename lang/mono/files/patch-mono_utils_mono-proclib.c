--- mono/utils/mono-proclib.c.orig	2009-03-08 16:22:48.000000000 +0000
+++ mono/utils/mono-proclib.c	2009-03-08 16:23:02.000000000 +0000
@@ -13,6 +13,9 @@
 #endif
 
 /* FIXME: bsds untested */
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#endif
 #if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #include <sys/types.h>
 #include <sys/sysctl.h>
