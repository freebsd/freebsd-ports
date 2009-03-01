--- utils.c.orig	2009-02-24 14:41:16.000000000 +0100
+++ utils.c	2009-02-24 14:41:55.000000000 +0100
@@ -59,6 +59,9 @@
 	return (mem);
 }
 
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if __FreeBSD_version <= 800057 && __FreeBSD_version > 800000 || __FreeBSD_version <= 701100
 char *strndup (char *src, int num)
 {
 	char *dst;
@@ -68,6 +71,8 @@
 	dst[num] = '\0';
 	return (strncpy(dst, src, num));
 }
+#endif
+#endif
 
 char *justify (char *str)
 {
