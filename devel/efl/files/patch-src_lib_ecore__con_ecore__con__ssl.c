--- src/lib/ecore_con/ecore_con_ssl.c.orig	2015-07-08 20:33:28.000000000 +0200
+++ src/lib/ecore_con/ecore_con_ssl.c	2015-09-19 12:15:30.503570123 +0200
@@ -1382,8 +1382,14 @@ _ecore_con_ssl_server_prepare_openssl(Ec
    if (ssl_type & ECORE_CON_USE_SSL2)
      return ECORE_CON_SSL_ERROR_SSL2_NOT_SUPPORTED;
 
+#ifdef OPENSSL_NO_SSL3
+   if (ssl_type & ECORE_CON_USE_SSL3)
+     return ECORE_CON_SSL_ERROR_NOT_SUPPORTED;
+#endif
+
    switch (ssl_type)
      {
+#ifndef OPENSSL_NO_SSL3
       case ECORE_CON_USE_SSL3:
       case ECORE_CON_USE_SSL3 | ECORE_CON_LOAD_CERT:
         if (!svr->created)
@@ -1391,9 +1397,15 @@ _ecore_con_ssl_server_prepare_openssl(Ec
         else
           SSL_ERROR_CHECK_GOTO_ERROR(!(svr->ssl_ctx = SSL_CTX_new(SSLv3_server_method())));
         break;
+#endif
 
       case ECORE_CON_USE_TLS:
       case ECORE_CON_USE_TLS | ECORE_CON_LOAD_CERT:
+	/*
+	 * XXX TLSv1_method restricts to TLSv1.0 only (disabling 1.1+).
+	 * SSLv23_method allows 1.1+ also, but requires options to be set
+	 * in order to disable SSLv2/3.
+	 */
         if (!svr->created)
           SSL_ERROR_CHECK_GOTO_ERROR(!(svr->ssl_ctx = SSL_CTX_new(TLSv1_client_method())));
         else
