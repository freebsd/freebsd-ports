--- gsoap/stdsoap2.c.orig	2019-01-27 15:50:05 UTC
+++ gsoap/stdsoap2.c
@@ -4302,7 +4302,7 @@ ssl_auth_init(struct soap *soap)
   ERR_clear_error();
   if (!soap->ctx)
   {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER))
     /* TLS_method: a TLS/SSL connection established may understand the SSLv3, TLSv1, TLSv1.1 and TLSv1.2 protocols. */
     soap->ctx = SSL_CTX_new(TLS_method());
 #else
@@ -4390,7 +4390,7 @@ ssl_auth_init(struct soap *soap)
 #endif
   if ((soap->ssl_flags & SOAP_SSL_RSA))
   {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER))
     if (SSL_CTX_need_tmp_RSA(soap->ctx))
 #endif
     {
@@ -6682,6 +6682,9 @@ soap_bind(struct soap *soap, const char *host, int por
   }
 #endif
 #ifdef TCP_FASTOPEN
+       #ifndef SOL_TCP
+       #define SOL_TCP IPPROTO_TCP
+       #endif
   if (!(soap->omode & SOAP_IO_UDP) && setsockopt(soap->master, IPPROTO_TCP, TCP_FASTOPEN, (char*)&set, sizeof(int)))
   {
     /* silently ignore */
