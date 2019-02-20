--- gsoap/VisualStudio2005/wsdl2h/wsdl2h/stdsoap2.cpp.orig	2019-02-10 15:19:37 UTC
+++ gsoap/VisualStudio2005/wsdl2h/wsdl2h/stdsoap2.cpp
@@ -4306,7 +4306,7 @@ ssl_auth_init(struct soap *soap)
   ERR_clear_error();
   if (!soap->ctx)
   {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER))
     /* TLS_method: a TLS/SSL connection established may understand the SSLv3, TLSv1, TLSv1.1 and TLSv1.2 protocols. */
     soap->ctx = SSL_CTX_new(TLS_method());
 #else
@@ -4394,7 +4394,7 @@ ssl_auth_init(struct soap *soap)
 #endif
   if ((soap->ssl_flags & SOAP_SSL_RSA))
   {
-#if OPENSSL_VERSION_NUMBER >= 0x10002000L
+#if (OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(LIBRESSL_VERSION_NUMBER))
     if (SSL_CTX_need_tmp_RSA(soap->ctx))
     {
       unsigned long e = RSA_F4;
