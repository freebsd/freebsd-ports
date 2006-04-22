--- lib/utils.c.orig	Sat Apr 22 12:28:47 2006
+++ lib/utils.c	Sat Apr 22 12:29:37 2006
@@ -32,3 +32,12 @@
 int cisalpha(int c) {
 	return ((c>='a') && (c<='z')) || ((c>='A') && (c<='Z'));
 }
+
+#ifdef __FreeBSD__
+size_t
+strnlen (const char *string, size_t maxlen)
+{
+	const char *end = memchr (string, '\0', maxlen);
+	return end ? (size_t) (end - string) : maxlen;
+}
+#endif
