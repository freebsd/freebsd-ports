--- camel/camel-sasl-gssapi.c.orig	2012-05-20 12:44:42.000000000 +0200
+++ camel/camel-sasl-gssapi.c	2012-05-20 12:45:21.000000000 +0200
@@ -66,7 +66,7 @@
 #endif /* HAVE_MIT_KRB5 */
 
 #ifdef HAVE_HEIMDAL_KRB5
-#include <gssapi.h>
+#include <gssapi/gssapi.h>
 #else
 #ifdef HAVE_SUN_KRB5
 #include <gssapi/gssapi.h>
