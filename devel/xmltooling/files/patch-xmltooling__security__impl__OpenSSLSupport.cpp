--- xmltooling/security/impl/OpenSSLSupport.cpp.orig	2018-07-10 01:00:14 UTC
+++ xmltooling/security/impl/OpenSSLSupport.cpp
@@ -91,6 +91,7 @@ const BIGNUM *xmltooling::DSA_get0_privk
 #endif
 }
 
+#if (OPENSSL_VERSION_NUMBER < 0x1010100fL)
 const BIGNUM *xmltooling::RSA_get0_n(const RSA *rsa)
 {
 #if (OPENSSL_VERSION_NUMBER < 0x10100000L)
@@ -123,3 +124,4 @@ const BIGNUM *xmltooling::RSA_get0_d(con
     return result;
 #endif
 }
+#endif
--- xmltooling/security/impl/OpenSSLSupport.h.bak	2018-10-12 08:58:16.782132000 +0200
+++ xmltooling/security/impl/OpenSSLSupport.h	2018-10-12 08:59:14.767210000 +0200
@@ -75,8 +75,9 @@
     const BIGNUM *DSA_get0_pubkey(const DSA *dsa);
     const BIGNUM *DSA_get0_privkey(const DSA *dsa);
 
+#if (OPENSSL_VERSION_NUMBER < 0x1010100fL)
     const BIGNUM *RSA_get0_n(const RSA *rsa);
     const BIGNUM *RSA_get0_d(const RSA *rsa);
     const BIGNUM *RSA_get0_e(const RSA *rsa);
-
+#endif
 }
