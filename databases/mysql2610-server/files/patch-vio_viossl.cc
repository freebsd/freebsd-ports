--- vio/viossl.cc.orig	2026-10-30 11:03:27 UTC
+++ vio/viossl.cc
@@ -689,7 +689,7 @@
 #if !defined(NDEBUG)
     {
       STACK_OF(SSL_COMP) *ssl_comp_methods = nullptr;
-      ssl_comp_methods = SSL_COMP_get_compression_methods();
+      ssl_comp_methods = (STACK_OF(SSL_COMP) *)SSL_COMP_get_compression_methods();
       n = sk_SSL_COMP_num(ssl_comp_methods);
       DBUG_PRINT("info", ("Available compression methods:\n"));
       if (n == 0)
@@ -697,8 +697,12 @@
       else
         for (j = 0; j < n; j++) {
           SSL_COMP *c = sk_SSL_COMP_value(ssl_comp_methods, j);
+#if defined(LIBRESSL_VERSION_NUMBER)
+          DBUG_PRINT("info", ("  %s\n", SSL_COMP_get_name(c)));
+#else
           DBUG_PRINT("info",
                      ("  %d: %s\n", SSL_COMP_get_id(c), SSL_COMP_get0_name(c)));
+#endif
         }
     }
 #endif
