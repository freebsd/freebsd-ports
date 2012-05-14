--- src/libpiano/crypt.h.orig	2012-05-06 07:33:54.000000000 -0700
+++ src/libpiano/crypt.h	2012-05-12 19:42:29.000000000 -0700
@@ -24,6 +24,7 @@
 #ifndef _CRYPH_H
 #define _CRYPT_H
 
+#define _GCRYPT_IN_LIBGCRYPT
 #include <gcrypt.h>
 
 char *PianoDecryptString (gcry_cipher_hd_t, const char * const,
