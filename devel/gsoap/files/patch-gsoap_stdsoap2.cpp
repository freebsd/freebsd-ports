--- gsoap/stdsoap2.cpp.orig	2017-04-07 18:39:02 UTC
+++ gsoap/stdsoap2.cpp
@@ -3735,7 +3735,7 @@ ssl_auth_init(struct soap *soap)
   ERR_clear_error();
   if (!soap->ctx)
   {
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER))
     /* TLS_method: a TLS/SSL connection established may understand the SSLv3, TLSv1, TLSv1.1 and TLSv1.2 protocols. */
     soap->ctx = SSL_CTX_new(TLS_method());
 #else
@@ -3812,7 +3812,7 @@ ssl_auth_init(struct soap *soap)
 #endif
   if ((soap->ssl_flags & SOAP_SSL_RSA))
   {
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER))
     if (SSL_CTX_need_tmp_RSA(soap->ctx))
 #endif
     { RSA *rsa = RSA_generate_key(SOAP_SSL_RSA_BITS, RSA_F4, NULL, NULL);
@@ -5501,7 +5501,7 @@ tcp_disconnect(struct soap *soap)
             DBGLOG(TEST, SOAP_MESSAGE(fdebug, "Connection lost...\n"));
             soap->fclosesocket(soap, soap->socket);
             soap->socket = SOAP_INVALID_SOCKET;
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER))
             ERR_clear_error();
 #else
             ERR_remove_state(0);
@@ -5525,7 +5525,7 @@ tcp_disconnect(struct soap *soap)
     }
     SSL_free(soap->ssl);
     soap->ssl = NULL;
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER))
     ERR_clear_error();
 #else
     ERR_remove_state(0);
@@ -5703,6 +5703,9 @@ soap_bind(struct soap *soap, const char 
   }
 #endif
 #ifdef TCP_FASTOPEN
+       #ifndef SOL_TCP
+       #define SOL_TCP IPPROTO_TCP
+       #endif
   if (!(soap->omode & SOAP_IO_UDP) && setsockopt(soap->master, IPPROTO_TCP, TCP_FASTOPEN, (char*)&set, sizeof(int)))
   { /* silently ignore */
     DBGLOG(TEST, SOAP_MESSAGE(fdebug, "setsockopt TCP_FASTOPEN failed in soap_bind()\n"));
@@ -6146,7 +6149,7 @@ soap_done(struct soap *soap)
       soap->ctx = NULL;
     }
   }
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER))
   ERR_clear_error();
 #else
   ERR_remove_state(0);
