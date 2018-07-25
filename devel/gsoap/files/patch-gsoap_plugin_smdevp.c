--- gsoap/plugin/smdevp.c.orig	2018-07-22 18:18:22 UTC
+++ gsoap/plugin/smdevp.c
@@ -480,7 +480,7 @@ soap_smd_init(struct soap *soap, struct soap_smd_data 
   /* allocate and init the OpenSSL HMAC or EVP_MD context */
   if ((alg & SOAP_SMD_ALGO) == SOAP_SMD_HMAC)
   {
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
     data->ctx = (void*)SOAP_MALLOC(soap, sizeof(HMAC_CTX));
     if (data->ctx)
       HMAC_CTX_init((HMAC_CTX*)data->ctx);
@@ -490,7 +490,7 @@ soap_smd_init(struct soap *soap, struct soap_smd_data 
   }
   else
   {
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
     data->ctx = (void*)SOAP_MALLOC(soap, sizeof(EVP_MD_CTX));
     if (data->ctx)
       EVP_MD_CTX_init((EVP_MD_CTX*)data->ctx);
@@ -510,7 +510,7 @@ soap_smd_init(struct soap *soap, struct soap_smd_data 
     case SOAP_SMD_SHA1:
       type = EVP_sha1();
       break;
-#if (OPENSSL_VERSION_NUMBER >= 0x0090800fL)
+#if (OPENSSL_VERSION_NUMBER >= 0x0090800fL || defined(LIBRESSL_VERSION_NUMBER))
     case SOAP_SMD_SHA224:
       type = EVP_sha224();
       break;
@@ -662,7 +662,7 @@ soap_smd_cleanup(struct soap *soap, struct soap_smd_da
   (void)soap;
   if (data->ctx)
   {
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
     if ((data->alg & SOAP_SMD_ALGO) == SOAP_SMD_HMAC)
       HMAC_CTX_cleanup((HMAC_CTX*)data->ctx);
     else
@@ -706,7 +706,7 @@ soap_smd_check(struct soap *soap, struct soap_smd_data
     }
     if (data->ctx)
     {
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER))
       if ((data->alg & SOAP_SMD_ALGO) == SOAP_SMD_HMAC)
         HMAC_CTX_cleanup((HMAC_CTX*)data->ctx);
       else
