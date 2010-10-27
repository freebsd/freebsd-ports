--- upnp/src/api/UpnpString.c.orig      2010-10-26 21:46:15.000000000 +0200
+++ upnp/src/api/UpnpString.c   2010-10-26 21:51:47.000000000 +0200
@@ -165,8 +165,10 @@

 int UpnpString_set_StringN(UpnpString *p, const char *s, size_t n)
 {
-       char *q = strndup(s, n);
+       char *q = malloc(n+1);
        if (!q) goto error_handler1;
+       strncpy(q, s, n);
+       q[n-1] = '\0';
        free(((struct SUpnpString *)p)->m_string);
        ((struct SUpnpString *)p)->m_length = strlen(q);
        ((struct SUpnpString *)p)->m_string = q;
