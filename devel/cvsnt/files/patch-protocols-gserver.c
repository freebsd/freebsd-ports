--- protocols/gserver.c.orig	Fri Mar 18 20:56:35 2005
+++ protocols/gserver.c	Wed Apr 20 01:49:15 2005
@@ -43,12 +43,13 @@
 
 #ifdef HAVE_GSSAPI_H
 #include <gssapi.h>
-#endif
+#else
 #ifdef HAVE_GSSAPI_GSSAPI_H
 #include <gssapi/gssapi.h>
 #endif /* freebsd needs 'else' but this breaks on other platforms so is incorrect for the main distribution.  Fix manually if building on that platform */
 #ifdef HAVE_GSSAPI_GSSAPI_GENERIC_H
 #include <gssapi/gssapi_generic.h>
+#endif
 #endif
 #include <krb5.h>
 
