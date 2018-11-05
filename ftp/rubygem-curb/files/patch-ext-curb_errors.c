--- ext/curb_errors.c.orig	2018-11-03 08:38:15 UTC
+++ ext/curb_errors.c
@@ -307,9 +307,11 @@ VALUE rb_curl_easy_error(CURLcode code) 
       exclz = eCurlErrObsolete;
       break;
 #endif
+#if LIBCURL_VERSION_NUM < 0x073e00
     case CURLE_SSL_PEER_CERTIFICATE:    /* 51 - peer's certificate wasn't ok */
       exclz = eCurlErrSSLPeerCertificate;
       break;
+#endif
     case CURLE_GOT_NOTHING:             /* 52 - when this is a specific error */
       exclz = eCurlErrGotNothing;
       break;
@@ -334,8 +336,13 @@ VALUE rb_curl_easy_error(CURLcode code) 
     case CURLE_SSL_CIPHER:              /* 59 - couldn't use specified cipher */
       exclz = eCurlErrSSLCipher;
       break;
+#if LIBCURL_VERSION_NUM >= 0x073e00
+    case CURLE_PEER_FAILED_VERIFICATION:              /* 60 - problem with the CA cert (path?) */
+      exclz = eCurlErrSSLPeerCertificate;
+#else
     case CURLE_SSL_CACERT:              /* 60 - problem with the CA cert (path?) */
       exclz = eCurlErrSSLCACertificate;
+#endif
       break;
     case CURLE_BAD_CONTENT_ENCODING:    /* 61 - Unrecognized transfer encoding */
       exclz = eCurlErrBadContentEncoding;
