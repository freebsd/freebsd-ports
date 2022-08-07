We have BIO_get_init() now.
https://github.com/libevent/libevent/pull/1227

Index: openssl-compat.h
--- openssl-compat.h.orig
+++ openssl-compat.h
@@ -40,7 +40,8 @@ static inline BIO_METHOD *BIO_meth_new(int type, const
 #endif /* (OPENSSL_VERSION_NUMBER < 0x10100000L) || \
 	(defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L) */
 
-#if defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER >= 0x20700000L
+#if defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER >= 0x20700000L && \
+	LIBRESSL_VERSION_NUMBER < 0x30500000L
 #define BIO_get_init(b) (b)->init
 #endif
 
