--- ./src/libs/tgfclient/screen.cpp.orig	Fri Feb  4 23:29:59 2005
+++ ./src/libs/tgfclient/screen.cpp	Mon Feb 28 19:21:11 2005
@@ -52,6 +52,19 @@
 #include <X11/extensions/Xrandr.h>
 #endif // USE_RANDR_EXT
 
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
 static int GfScrWidth;
 static int GfScrHeight;
 static int GfViewWidth;
