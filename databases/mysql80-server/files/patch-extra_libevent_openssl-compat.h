--- extra/libevent/openssl-compat.h.orig	2019-09-20 08:30:51 UTC
+++ extra/libevent/openssl-compat.h
@@ -24,12 +24,15 @@ static inline BIO_METHOD *BIO_meth_new(int type, const
 #define BIO_set_init(b, val) (b)->init = (val)
 #define BIO_set_data(b, val) (b)->ptr = (val)
 #define BIO_set_shutdown(b, val) (b)->shutdown = (val)
-#define BIO_get_init(b) (b)->init
 #define BIO_get_data(b) (b)->ptr
 #define BIO_get_shutdown(b) (b)->shutdown
 
 #define TLS_method SSLv23_method
 
 #endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
+
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#define BIO_get_init(b) (b)->init
+#endif
 
 #endif /* OPENSSL_COMPAT_H */
