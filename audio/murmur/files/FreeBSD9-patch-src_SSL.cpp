--- src/SSL.cpp.orig	2015-11-20 16:02:09 UTC
+++ src/SSL.cpp
@@ -43,7 +43,7 @@ QList<QSslCipher> MumbleSSL::ciphersFrom
 
 	SSL_CTX *ctx = NULL;
 	SSL *ssl = NULL;
-	const SSL_METHOD *meth = NULL;
+	SSL_METHOD *meth = NULL;
 	int i = 0;
 
 	QByteArray csbuf = cipherString.toLatin1();
