--- libarchive/archive_openssl_evp_private.h.orig	Sun Jan 29 06:06:27 2017
+++ libarchive/archive_openssl_evp_private.h	Fri Mar 10 12:53:43 2017
@@ -28,7 +28,7 @@
 #include <openssl/evp.h>
 #include <openssl/opensslv.h>
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #include <stdlib.h> /* malloc, free */
 #include <string.h> /* memset */
 static inline EVP_MD_CTX *EVP_MD_CTX_new(void)
