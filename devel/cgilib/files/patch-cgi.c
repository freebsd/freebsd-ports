--- cgi.c.orig	2008-05-03 09:51:51.000000000 -0700
+++ cgi.c	2008-05-03 09:52:40.000000000 -0700
@@ -227,6 +227,30 @@
     return strdup (template);
 }
 
+
+size_t
+strnlen(const char *s, size_t len)
+{
+    size_t i;
+
+    for(i = 0; i < len && s[i]; i++)
+	;
+    return i;
+}
+
+char *
+strndup(const char *old, size_t sz)
+{
+    size_t len = strnlen (old, sz);
+    char *t    = malloc(len + 1);
+
+    if (t != NULL) {
+	memcpy (t, old, len);
+	t[len] = '\0';
+    }
+    return t;
+}
+
 /* cgiReadMultipart()
  *
  * Decode multipart/form-data
