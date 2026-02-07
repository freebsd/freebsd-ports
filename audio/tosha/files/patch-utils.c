--- utils.c.orig	1999-01-01 23:57:50 UTC
+++ utils.c
@@ -59,6 +59,9 @@ void *tmalloc (size_t size)
 	return (mem);
 }
 
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if __FreeBSD_version <= 800057 && __FreeBSD_version > 800000 || __FreeBSD_version <= 701100
 char *strndup (char *src, int num)
 {
 	char *dst;
@@ -68,6 +71,8 @@ char *strndup (char *src, int num)
 	dst[num] = '\0';
 	return (strncpy(dst, src, num));
 }
+#endif
+#endif
 
 char *justify (char *str)
 {
