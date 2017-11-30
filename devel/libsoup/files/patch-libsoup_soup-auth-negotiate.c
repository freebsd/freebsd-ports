--- libsoup/soup-auth-negotiate.c.orig	2016-03-14 16:19:35 UTC
+++ libsoup/soup-auth-negotiate.c
@@ -14,7 +14,6 @@
 
 #ifdef LIBSOUP_HAVE_GSSAPI
 #include <gssapi/gssapi.h>
-#include <gssapi/gssapi_krb5.h>
 #endif /* LIBSOUP_HAVE_GSSAPI */
 
 #include "soup-auth-negotiate.h"
