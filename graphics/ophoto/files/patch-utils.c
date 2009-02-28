--- utils.c.orig	2009-02-24 14:08:54.000000000 +0100
+++ utils.c	2009-02-24 14:07:20.000000000 +0100
@@ -54,6 +54,9 @@
 	return (mem);
 }
 
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if __FreeBSD_version <= 800057 && __FreeBSD_version > 800000 || __FreeBSD_version <= 701100
 char *strndup (const char *src, int num)
 {
 	char *dst;
@@ -63,6 +66,8 @@
 	dst[num] = '\0';
 	return (strncpy(dst, src, num));
 }
+#endif
+#endif
 
 char *justify (char *str)
 {
