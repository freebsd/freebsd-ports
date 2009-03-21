--- utils/utils.c.orig	2009-02-23 16:51:16.000000000 +0100
+++ utils/utils.c	2009-02-23 16:53:54.000000000 +0100
@@ -31,6 +31,9 @@
 	return (mem);
 }
 
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if __FreeBSD_version <= 800057 && __FreeBSD_version > 800000 || __FreeBSD_version <= 701100
 char *strndup (const char *src, int num)
 {
 	char *dst;
@@ -40,6 +43,8 @@
 	dst[num] = '\0';
 	return (strncpy(dst, src, num));
 }
+#endif
+#endif
 
 char *justify (char *str)
 {
