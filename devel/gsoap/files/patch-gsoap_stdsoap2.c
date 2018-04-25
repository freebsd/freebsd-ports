--- gsoap/stdsoap2.c.orig	2018-04-08 14:22:45 UTC
+++ gsoap/stdsoap2.c
@@ -4281,7 +4281,7 @@ ssl_auth_init(struct soap *soap)
   ERR_clear_error();
   if (!soap->ctx)
   {
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER))
     /* TLS_method: a TLS/SSL connection established may understand the SSLv3, TLSv1, TLSv1.1 and TLSv1.2 protocols. */
     soap->ctx = SSL_CTX_new(TLS_method());
 #else
@@ -4369,7 +4369,7 @@ ssl_auth_init(struct soap *soap)
 #endif
   if ((soap->ssl_flags & SOAP_SSL_RSA))
   {
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER))
     if (SSL_CTX_need_tmp_RSA(soap->ctx))
 #endif
     {
@@ -6390,7 +6390,7 @@ tcp_disconnect(struct soap *soap)
             DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Connection lost...\n"));
             soap->fclosesocket(soap, soap->socket);
             soap->socket = SOAP_INVALID_SOCKET;
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER))
             ERR_clear_error();
 #else
             ERR_remove_state(0);
@@ -6416,7 +6416,7 @@ tcp_disconnect(struct soap *soap)
     }
     SSL_free(soap->ssl);
     soap->ssl = NULL;
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER))
     ERR_clear_error();
 #else
     ERR_remove_state(0);
@@ -6603,6 +6603,9 @@ soap_bind(struct soap *soap, const char *host, int por
   }
 #endif
 #ifdef TCP_FASTOPEN
+       #ifndef SOL_TCP
+       #define SOL_TCP IPPROTO_TCP
+       #endif
   if (!(soap->omode & SOAP_IO_UDP) && setsockopt(soap->master, IPPROTO_TCP, TCP_FASTOPEN, (char*)&set, sizeof(int)))
   {
     /* silently ignore */
@@ -7096,7 +7099,7 @@ soap_done(struct soap *soap)
       soap->ctx = NULL;
     }
   }
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER))
   ERR_clear_error();
 #else
   ERR_remove_state(0);
