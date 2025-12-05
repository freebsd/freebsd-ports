--- cargo-crates/openssl-sys-0.9.61/build/expando.c.orig2021-01-01 00:00:00 UTC
+++ cargo-crates/openssl-sys-0.9.61/build/expando.c
@@ -1,6 +1,15 @@
 #include <openssl/opensslv.h>
 #include <openssl/opensslconf.h>
 
+/*
+ * In OpenSSL 3.x, OPENSSL_VERSION_NUMBER is defined as a computed macro 
+ * expression rather than a simple literal, which breaks token pasting.
+ * We detect OpenSSL 3.x and emit a fixed version token instead.
+ */
+#if defined(OPENSSL_VERSION_MAJOR) && OPENSSL_VERSION_MAJOR >= 3
+/* OpenSSL 3.x detected - emit a version that indicates OpenSSL 3.0.0+ */
+RUST_VERSION_OPENSSL_0x30000000L
+#else
 #define VERSION2(n, v) RUST_VERSION_##n##_##v
 #define VERSION(n, v) VERSION2(n, v)
 
@@ -9,6 +18,7 @@
 #else
 VERSION(OPENSSL, OPENSSL_VERSION_NUMBER)
 #endif
+#endif
 
 #ifdef OPENSSL_NO_BF
 RUST_CONF_OPENSSL_NO_BF
