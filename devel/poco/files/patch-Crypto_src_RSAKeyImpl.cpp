--- Crypto/src/RSAKeyImpl.cpp.orig	2017-02-22 13:17:54 UTC
+++ Crypto/src/RSAKeyImpl.cpp
@@ -207,7 +207,7 @@ int RSAKeyImpl::size() const
 
 RSAKeyImpl::ByteVec RSAKeyImpl::modulus() const
 {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 	const BIGNUM* n = 0;
 	const BIGNUM* e = 0;
 	const BIGNUM* d = 0;
@@ -221,7 +221,7 @@ RSAKeyImpl::ByteVec RSAKeyImpl::modulus(
 
 RSAKeyImpl::ByteVec RSAKeyImpl::encryptionExponent() const
 {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 	const BIGNUM* n = 0;
 	const BIGNUM* e = 0;
 	const BIGNUM* d = 0;
@@ -235,7 +235,7 @@ RSAKeyImpl::ByteVec RSAKeyImpl::encrypti
 
 RSAKeyImpl::ByteVec RSAKeyImpl::decryptionExponent() const
 {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 	const BIGNUM* n = 0;
 	const BIGNUM* e = 0;
 	const BIGNUM* d = 0;
