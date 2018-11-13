--- net/netsslcredentials.cc.orig	2018-02-05 20:46:46.000000000 +0000
+++ net/netsslcredentials.cc	2018-11-08 16:32:39.241553000 +0000
@@ -42,6 +42,7 @@ extern "C"
 # include <openssl/x509v3.h>
 # include <openssl/ssl.h>
 # include <openssl/x509_vfy.h>
+# include <openssl/opensslv.h>
 }
 # include <stdio.h>
 # include "netdebug.h"
@@ -218,7 +219,11 @@ NetSslCredentials::ReadCredentials(  Error *e )
 	privateKey = PEM_read_PrivateKey(fp, NULL, 0, NULL );
 	SSLNULLHANDLER( privateKey, e, "NetSslCredentials::ReadCredentials PEM_read_PrivateKey", failSetError );
 	// verify that RSA key
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	if (privateKey->type != EVP_PKEY_RSA)
+#else
+	if (EVP_PKEY_base_id(privateKey) != EVP_PKEY_RSA)
+#endif
 	{
 	    e->Set( MsgRpc::SslKeyNotRSA );
 	    goto fail;

