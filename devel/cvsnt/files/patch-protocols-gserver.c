--- protocols/gserver.c.orig	Sun Feb 20 16:35:47 2005
+++ protocols/gserver.c	Sun Feb 20 16:35:55 2005
@@ -43,12 +43,13 @@
 
 #ifdef HAVE_GSSAPI_H
 #include <gssapi.h>
-#endif
+#else
 #ifdef HAVE_GSSAPI_GSSAPI_H
 #include <gssapi/gssapi.h>
 #endif
 #ifdef HAVE_GSSAPI_GSSAPI_GENERIC_H
 #include <gssapi/gssapi_generic.h>
+#endif
 #endif
 #include <krb5.h>
 
