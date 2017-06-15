--- lib/dnscore/src/dnskey_rsa.c.orig	2016-12-16 11:52:17 UTC
+++ lib/dnscore/src/dnskey_rsa.c
@@ -64,7 +64,7 @@
 
 #define MODULE_MSG_HANDLE g_system_logger
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
 #define SSL_FIELD_GET(st_,f_) if(f_ != NULL) { *f_ = st_->f_; }
 #define SSL_FIELD_SET(st_,f_) if(f_ != NULL) { BN_free(st_->f_); st_->f_ = f_; }
