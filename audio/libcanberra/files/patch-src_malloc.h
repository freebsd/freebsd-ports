--- src/malloc.h.orig	2008-06-10 10:42:46.000000000 -0400
+++ src/malloc.h	2008-08-05 23:34:40.000000000 -0400
@@ -31,6 +31,32 @@
 #define ca_free free
 #define ca_malloc0(size) calloc(1, (size))
 #define ca_strdup strdup
+#ifdef __FreeBSD__
+static inline char *strndup (const char *s, size_t n)
+{
+	size_t nAvail;
+	char *p;
+
+	if (!s) {
+		return NULL;
+	}
+
+	if (memchr (s, '\0', n) != NULL) {
+		nAvail = strlen (s);
+		if (nAvail > n)
+			nAvail = n;
+	} else {
+		nAvail = n;
+	}
+	p = ca_malloc (nAvail + 1);
+	if (p == NULL)
+		return NULL;
+	memcpy (p, s, nAvail);
+	p[nAvail] = '\0';
+
+	return p;
+}
+#endif
 #define ca_strndup strndup
 
 void* ca_memdup(const void* p, size_t size);
