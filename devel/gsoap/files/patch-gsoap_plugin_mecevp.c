--- gsoap/plugin/mecevp.c.orig	2018-04-08 14:22:44 UTC
+++ gsoap/plugin/mecevp.c
@@ -284,7 +284,7 @@ soap_mec_init(struct soap *soap, struct soap_mec_data 
   int ok = 1;
   DBGLOG(TEST, SOAP_MESSAGE(fdebug, "soap_mec_init()\n"));
   soap_ssl_init();
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
   data->ctx = (EVP_CIPHER_CTX*)SOAP_MALLOC(soap, sizeof(EVP_CIPHER_CTX));
   if (data->ctx)
     EVP_CIPHER_CTX_init(data->ctx);
@@ -448,7 +448,7 @@ soap_mec_cleanup(struct soap *soap, struct soap_mec_da
   data->type = NULL;
   if (data->ctx)
   {
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
     EVP_CIPHER_CTX_cleanup(data->ctx);
     SOAP_FREE(soap, data->ctx);
 #else
