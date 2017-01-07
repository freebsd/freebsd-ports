Obtained from:	https://github.com/curl/curl/commit/a7b38c9dc98481e4a5fc37e51a8690337c674dfb

--- lib/vtls/vtls.c.orig	2016-12-19 07:27:56 UTC
+++ lib/vtls/vtls.c
@@ -484,7 +484,7 @@ void Curl_ssl_close_all(struct Curl_easy
   curlssl_close_all(data);
 }
 
-#if defined(USE_SSLEAY) || defined(USE_GNUTLS) || defined(USE_SCHANNEL) || \
+#if defined(USE_OPENSSL) || defined(USE_GNUTLS) || defined(USE_SCHANNEL) || \
     defined(USE_DARWINSSL) || defined(USE_NSS)
 /* This function is for OpenSSL, GnuTLS, darwinssl, and schannel only. */
 int Curl_ssl_getsock(struct connectdata *conn, curl_socket_t *socks,
@@ -518,7 +518,7 @@ int Curl_ssl_getsock(struct connectdata 
   (void)numsocks;
   return GETSOCK_BLANK;
 }
-/* USE_SSLEAY || USE_GNUTLS || USE_SCHANNEL || USE_DARWINSSL || USE_NSS */
+/* USE_OPENSSL || USE_GNUTLS || USE_SCHANNEL || USE_DARWINSSL || USE_NSS */
 #endif
 
 void Curl_ssl_close(struct connectdata *conn, int sockindex)
