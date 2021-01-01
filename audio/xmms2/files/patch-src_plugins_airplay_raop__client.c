--- src/plugins/airplay/raop_client.c.orig	2011-10-20 19:26:08 UTC
+++ src/plugins/airplay/raop_client.c
@@ -1,6 +1,8 @@
 #include <string.h>
 #include <unistd.h>
 
+#include <openssl/opensslv.h>
+#include <openssl/ossl_typ.h>
 #include <openssl/rand.h>
 #include <openssl/rsa.h>
 #include <openssl/bio.h>
@@ -137,8 +139,13 @@ raop_rsa_encrypt (guchar *text, gint len, guchar *res)
 	static const guchar exp[] = {0x01, 0x00, 0x01};
 
 	rsa = RSA_new ();
+
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	rsa->n = BN_bin2bn (mod, 256, NULL);
 	rsa->e = BN_bin2bn (exp, 3, NULL);
+#else
+	RSA_set0_key(rsa, BN_bin2bn (mod, 256, NULL), BN_bin2bn (exp, 3, NULL), NULL);
+#endif
 
 	size = RSA_public_encrypt (len, text, res, rsa, RSA_PKCS1_OAEP_PADDING);
 
