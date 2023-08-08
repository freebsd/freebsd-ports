--- Crypto/src/OpenSSLInitializer.cpp.orig	2023-07-04 22:23:04 UTC
+++ Crypto/src/OpenSSLInitializer.cpp
@@ -137,7 +137,6 @@ void OpenSSLInitializer::initialize()
 		if (!_legacyProvider)
 		{
 			_legacyProvider = OSSL_PROVIDER_load(NULL, "legacy");
-			if (!_legacyProvider) throw CryptoException("Failed to load OpenSSL legacy provider");
 		}
 #endif
 	}
