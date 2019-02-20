--- gsoap/stdsoap2.c.orig	2019-02-10 15:19:37 UTC
+++ gsoap/stdsoap2.c
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
@@ -4473,10 +4473,12 @@ ssl_auth_init(struct soap *soap)
     minv = TLS1_1_VERSION;
   else if ((soap->ssl_flags & SOAP_TLSv1_2))
     minv = TLS1_2_VERSION;
+#ifdef TLS1_3_VERSION
   else if ((soap->ssl_flags & SOAP_TLSv1_3))
     minv = TLS1_3_VERSION;
   if ((soap->ssl_flags & SOAP_TLSv1_3) && OpenSSL_version_num() >= 0x10101000L)
     maxv = TLS1_3_VERSION;
+#endif
   else if ((soap->ssl_flags & SOAP_TLSv1_2))
     maxv = TLS1_2_VERSION;
   else if ((soap->ssl_flags & SOAP_TLSv1_1))
@@ -6714,6 +6716,9 @@ soap_bind(struct soap *soap, const char *host, int por
   }
 #endif
 #ifdef TCP_FASTOPEN
+       #ifndef SOL_TCP
+       #define SOL_TCP IPPROTO_TCP
+       #endif
   if (!(soap->omode & SOAP_IO_UDP) && setsockopt(soap->master, IPPROTO_TCP, TCP_FASTOPEN, (char*)&set, sizeof(int)))
   {
     /* silently ignore */
