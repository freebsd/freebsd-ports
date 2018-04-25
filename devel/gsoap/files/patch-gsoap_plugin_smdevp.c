--- gsoap/plugin/smdevp.c.orig	2018-04-08 14:22:44 UTC
+++ gsoap/plugin/smdevp.c
@@ -479,7 +479,7 @@ soap_smd_init(struct soap *soap, struct soap_smd_data 
   /* allocate and init the OpenSSL HMAC or EVP_MD context */
   if ((alg & SOAP_SMD_ALGO) == SOAP_SMD_HMAC)
   {
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
     data->ctx = (void*)SOAP_MALLOC(soap, sizeof(HMAC_CTX));
     if (data->ctx)
       HMAC_CTX_init((HMAC_CTX*)data->ctx);
@@ -489,7 +489,7 @@ soap_smd_init(struct soap *soap, struct soap_smd_data 
   }
   else
   {
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
     data->ctx = (void*)SOAP_MALLOC(soap, sizeof(EVP_MD_CTX));
     if (data->ctx)
       EVP_MD_CTX_init((EVP_MD_CTX*)data->ctx);
@@ -642,7 +642,7 @@ soap_smd_final(struct soap *soap, struct soap_smd_data
       *len = (int)n;
   }
   /* cleanup */
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
   if ((data->alg & SOAP_SMD_ALGO) == SOAP_SMD_HMAC)
     HMAC_CTX_cleanup((HMAC_CTX*)data->ctx);
   else
@@ -687,7 +687,7 @@ soap_smd_check(struct soap *soap, struct soap_smd_data
     }
     if (data->ctx)
     {
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
       if ((data->alg & SOAP_SMD_ALGO) == SOAP_SMD_HMAC)
         HMAC_CTX_cleanup((HMAC_CTX*)data->ctx);
       else
