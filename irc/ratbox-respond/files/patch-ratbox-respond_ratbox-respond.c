--- ratbox-respond/ratbox-respond.c.orig	2018-10-09 21:09:45 UTC
+++ ratbox-respond/ratbox-respond.c
@@ -27,8 +27,10 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <openssl/evp.h>
 #include <openssl/err.h>
 #include <openssl/rsa.h>
+#include <openssl/opensslv.h>
 #include <openssl/pem.h>
 #include <openssl/sha.h>
 #include <unistd.h>
@@ -235,7 +237,9 @@ main(int argc, char **argv)
 		return -1;
 	}
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	SSLeay_add_all_ciphers();
+#endif
 	rsa = PEM_read_RSAPrivateKey(kfile, NULL,pass_cb, NULL);
 
 	if(!rsa)
