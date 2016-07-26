--- scrobbler.c.orig	2005-02-21 00:45:05 UTC
+++ scrobbler.c
@@ -382,9 +382,9 @@ static int sc_parse_sb_res(void)
 
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
