--- plugin/x/client/xconnection_impl.cc.orig	2021-12-17 16:07:27 UTC
+++ plugin/x/client/xconnection_impl.cc
@@ -618,6 +618,7 @@ XError Connection_impl::get_ssl_error(const int error_
   return XError(CR_SSL_CONNECTION_ERROR, buffer);
 }
 
+#ifndef LIBRESSL_VERSION_NUMBER
 /**
   Set fips mode in openssl library,
   When we set fips mode ON/STRICT, it will perform following operations:
@@ -657,6 +658,7 @@ int set_fips_mode(const uint32_t fips_mode,
 EXIT:
   return rc;
 }
+#endif
 
 XError Connection_impl::activate_tls() {
   if (nullptr == m_vio) return get_socket_error(SOCKET_ECONNRESET);
@@ -667,12 +669,14 @@ XError Connection_impl::activate_tls() {
   if (!m_context->m_ssl_config.is_configured())
     return XError{CR_SSL_CONNECTION_ERROR, ER_TEXT_TLS_NOT_CONFIGURATED, true};
 
+#ifndef LIBRESSL_VERSION_NUMBER
   char err_string[OPENSSL_ERROR_LENGTH] = {'\0'};
   if (set_fips_mode(
           static_cast<uint32_t>(m_context->m_ssl_config.m_ssl_fips_mode),
           err_string) != 1) {
     return XError{CR_SSL_CONNECTION_ERROR, err_string, true};
   }
+#endif
   auto ssl_ctx_flags = process_tls_version(
       details::null_when_empty(m_context->m_ssl_config.m_tls_version));
 
