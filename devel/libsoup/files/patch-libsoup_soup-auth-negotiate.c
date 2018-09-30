--- libsoup/soup-auth-negotiate.c.orig	2016-04-07 16:25:20.853309000 +0200
+++ libsoup/soup-auth-negotiate.c	2016-04-07 16:25:49.465869000 +0200
@@ -11,6 +11,8 @@
 #endif
 
 #include <string.h>
+#include <time.h>
+#include <stdint.h>
 
 #ifdef LIBSOUP_HAVE_GSSAPI
 #include <gssapi/gssapi.h>
