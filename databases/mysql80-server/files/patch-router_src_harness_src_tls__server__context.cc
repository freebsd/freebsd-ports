--- router/src/harness/src/tls_server_context.cc.orig	2022-12-11 13:24:16 UTC
+++ router/src/harness/src/tls_server_context.cc
@@ -272,7 +272,8 @@ stdx::expected<void, std::error_code> set_auto_dh_para
 #if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(3, 0, 0)
   SSL_CTX_set_dh_auto(ssl_ctx, 1);
 #else
-#if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(1, 1, 0)
+#if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(1, 1, 0) \
+  && !defined(LIBRESSL_VERSION_NUMBER)
   OsslUniquePtr<DH> dh_storage(DH_get_2048_256());
 #else
   /*
