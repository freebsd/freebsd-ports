--- ./xdg-user-dirs-update.c.orig	2007-08-20 12:12:20.000000000 +0400
+++ ./xdg-user-dirs-update.c	2008-07-15 23:26:50.000000000 +0400
@@ -16,6 +16,22 @@
 #include <iconv.h>
 #include <langinfo.h>
 
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if (__FreeBSD_version >= 800000 && __FreeBSD_version <= 800057) || __FreeBSD_version <= 701101
+static char *strndup(const char *str, size_t len) {
+	char *ret;
+	
+	if ((str == NULL || len < 0)) return(NULL);
+	ret = (char *)malloc(len + 1);
+	if (ret == NULL) return(NULL);
+	memcpy(ret, str, len);
+	ret[len] = '\0';
+	return(ret);
+}
+#endif
+#endif
+
 typedef struct {
   char *name;
   char *path;
