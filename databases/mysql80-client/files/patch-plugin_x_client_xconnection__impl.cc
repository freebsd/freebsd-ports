--- plugin/x/client/xconnection_impl.cc.orig	2018-04-08 06:44:49 UTC
+++ plugin/x/client/xconnection_impl.cc
@@ -182,12 +182,12 @@ XError ssl_verify_server_cert(Vio *vio, 
     return XError{CR_SSL_CONNECTION_ERROR, "Failed to get CN from CN entry"};
   }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
-  const auto cn = reinterpret_cast<char *>(ASN1_STRING_data(cn_asn1));
-#else  /* OPENSSL_VERSION_NUMBER < 0x10100000L */
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
   const auto cn =
       reinterpret_cast<const char *>(ASN1_STRING_get0_data(cn_asn1));
-#endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
+#else
+  const auto cn = reinterpret_cast<char *>(ASN1_STRING_data(cn_asn1));
+#endif /* OPENSSL_VERSION_NUMBER >= 0x10100000L */
   const auto cn_len = static_cast<size_t>(ASN1_STRING_length(cn_asn1));
 
   // There should not be any NULL embedded in the CN
@@ -451,7 +451,7 @@ XError Connection_impl::get_ssl_error(co
   return XError(CR_SSL_CONNECTION_ERROR, buffer);
 }
 
-#ifndef HAVE_WOLFSSL
+#if !defined(HAVE_WOLFSSL) && !defined(LIBRESSL_VERSION_NUMBER)
 /**
   Set fips mode in openssl library,
   When we set fips mode ON/STRICT, it will perform following operations:
@@ -501,7 +501,7 @@ XError Connection_impl::activate_tls() {
   if (!m_context->m_ssl_config.is_configured())
     return XError{CR_SSL_CONNECTION_ERROR, ER_TEXT_TLS_NOT_CONFIGURATED};
 
-#ifndef HAVE_WOLFSSL
+#if !defined(HAVE_WOLFSSL) && !defined(LIBRESSL_VERSION_NUMBER)
   char err_string[OPENSSL_ERROR_LENGTH] = {'\0'};
   if (set_fips_mode((int)m_context->m_ssl_config.m_ssl_fips_mode, err_string) !=
       1) {
