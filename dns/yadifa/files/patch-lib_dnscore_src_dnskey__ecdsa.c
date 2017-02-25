--- lib/dnscore/src/dnskey_ecdsa.c.orig	2016-12-16 11:52:17 UTC
+++ lib/dnscore/src/dnskey_ecdsa.c
@@ -79,7 +79,7 @@
 #define DNSKEY_ALGORITHM_ECDSAP256SHA256_NID NID_X9_62_prime256v1
 #define DNSKEY_ALGORITHM_ECDSAP384SHA384_NID NID_secp384r1
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
 #define SSL_FIELD_GET(st_,f_) if(f_ != NULL) { *f_ = st_->f_; }
 #define SSL_FIELD_SET(st_,f_) if(f_ != NULL) { BN_free(st_->f_); st_->f_ = f_; }
