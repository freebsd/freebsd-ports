--- plugins/qca-ossl/qca-ossl.cpp.orig	2019-04-24 12:58:14 UTC
+++ plugins/qca-ossl/qca-ossl.cpp
@@ -62,12 +62,12 @@
 #endif
 
 // OpenSSL 1.1.0 compatibility macros
-#ifdef OSSL_110
+#if defined(OSSL_110) && !defined(LIBRESSL_VERSION_NUMBER)
 #define M_ASN1_IA5STRING_new() ASN1_IA5STRING_new()
 #define RSA_F_RSA_EAY_PRIVATE_DECRYPT RSA_F_RSA_OSSL_PRIVATE_DECRYPT
 #endif
 
-#ifdef OSSL_110
+#if defined(OSSL_110) && !defined(LIBRESSL_VERSION_NUMBER)
 #include <openssl/kdf.h>
 #endif
 
@@ -1280,7 +1280,7 @@ class opensslPbkdf2Context : public KDFContext (public
 protected:
 };
 
-#ifdef OSSL_110
+#if defined(OSSL_110) && !defined(LIBRESSL_VERSION_NUMBER)
 class opensslHkdfContext : public HKDFContext
 {
 public:
@@ -7416,7 +7416,7 @@ class opensslProvider : public Provider (public)
 #endif
 		list += "pbkdf1(sha1)";
 		list += "pbkdf2(sha1)";
-#ifdef OSSL_110
+#if defined(OSSL_110) && !defined(LIBRESSL_VERSION_NUMBER)
 		list += "hkdf(sha256)";
 #endif
 		list += "pkey";
@@ -7489,7 +7489,7 @@ class opensslProvider : public Provider (public)
 #endif
 		else if ( type == "pbkdf2(sha1)" )
 			return new opensslPbkdf2Context( this, type );
-#ifdef OSSL_110
+#if defined(OSSL_110) && !defined(LIBRESSL_VERSION_NUMBER)
 		else if ( type == "hkdf(sha256)" )
 			return new opensslHkdfContext( this, type );
 #endif
