--- ./xdg-user-dirs-update.c.orig	2007-08-20 12:12:20.000000000 +0400
+++ ./xdg-user-dirs-update.c	2008-07-15 23:26:50.000000000 +0400
@@ -16,6 +16,19 @@
 #include <iconv.h>
 #include <langinfo.h>
 
+#if defined(__FreeBSD__)
+static char *strndup(const char *str, int len) {
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
+
 typedef struct {
   char *name;
   char *path;
