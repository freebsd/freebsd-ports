--- libwzd/libwzd_tls.c.orig	2006-09-19 13:28:28 UTC
+++ libwzd/libwzd_tls.c
@@ -153,7 +153,6 @@ int tls_write(const char *buffer, int length)
 #elif HAVE_GNUTLS
 
 #include <gnutls/gnutls.h>
-#include <gcrypt.h>
 
 #define DH_BITS 1024
 
