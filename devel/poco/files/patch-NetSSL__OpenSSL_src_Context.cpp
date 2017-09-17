--- NetSSL_OpenSSL/src/Context.cpp.orig	2017-02-22 13:17:54 UTC
+++ NetSSL_OpenSSL/src/Context.cpp
@@ -494,7 +494,7 @@ void Context::initDH(const std::string& 
 			std::string msg = Utility::getLastError();
 			throw SSLContextException("Error creating Diffie-Hellman parameters", msg);
 		}
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 		BIGNUM* p = BN_bin2bn(dh1024_p, sizeof(dh1024_p), 0);
 		BIGNUM* g = BN_bin2bn(dh1024_g, sizeof(dh1024_g), 0);
 		DH_set0_pqg(dh, p, 0, g);
