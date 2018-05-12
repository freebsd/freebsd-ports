--- sql-common/client.cc.orig	2018-04-08 06:44:49 UTC
+++ sql-common/client.cc
@@ -2649,11 +2649,11 @@ static int ssl_verify_server_cert(Vio *v
     goto error;
   }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
-  cn = (char *)ASN1_STRING_data(cn_asn1);
-#else  /* OPENSSL_VERSION_NUMBER < 0x10100000L */
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
   cn = (char *)ASN1_STRING_get0_data(cn_asn1);
-#endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
+#else  /* OPENSSL_VERSION_NUMBER >= 0x10100000L */
+  cn = (char *)ASN1_STRING_data(cn_asn1);
+#endif /* OPENSSL_VERSION_NUMBER >= 0x10100000L */
 
   // There should not be any NULL embedded in the CN
   if ((size_t)ASN1_STRING_length(cn_asn1) != strlen(cn)) {
@@ -5596,7 +5596,7 @@ int STDCALL mysql_options(MYSQL *mysql, 
 #endif
       break;
     case MYSQL_OPT_SSL_FIPS_MODE: {
-#if defined(HAVE_OPENSSL) && !defined(HAVE_WOLFSSL)
+#if defined(HAVE_OPENSSL) && !defined(HAVE_WOLFSSL) && !defined(LIBRESSL_VERSION_NUMBER)
       char ssl_err_string[OPENSSL_ERROR_LENGTH] = {'\0'};
       ENSURE_EXTENSIONS_PRESENT(&mysql->options);
       mysql->options.extension->ssl_fips_mode = *(uint *)arg;
