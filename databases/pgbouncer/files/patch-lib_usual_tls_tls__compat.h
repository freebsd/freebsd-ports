--- lib/usual/tls/tls_compat.h.orig	2016-01-29 15:00:49 UTC
+++ lib/usual/tls/tls_compat.h
@@ -16,7 +16,18 @@
 /* OpenSSL 1.1+ has hidden struct fields */
 #if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
+/*
+ * USE_LIBSSL_OLD - old openssl 1.0 api
+ * USE_LIBSSL_INTERNALS - can access old openssl 1.0 structs
+ * otherwise - new openssl 1.1 api
+ */
+
+/* libressl has old api but unstable structs */
+#define USE_LIBSSL_OLD
+
+#ifndef LIBRESSL_VERSION_NUMBER
 #define USE_LIBSSL_INTERNALS
+#endif
 
 #define X509_get_key_usage(x509) ((x509)->ex_kusage)
 #define X509_get_extended_key_usage(x509) ((x509)->ex_xkusage)
