--- scrobbler.c.orig	Mon Feb 21 03:45:05 2005
+++ scrobbler.c	Sat Nov 26 20:14:10 2005
@@ -382,9 +382,9 @@
 
 static gchar *sc_itemtag(char c, int n, char *str)
 {
-    static char buf[256]; 
-    snprintf(buf, 256, "&%c[%d]=%s", c, n, str);
-    return buf;
+	static char buf[1024];
+	snprintf(buf, 1024, "&%c[%d]=%s", c, n, str);
+	return buf;
 }
 
 #define cfa(f, l, n, v) \
