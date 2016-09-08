--- src/VBox/Runtime/common/crypto/digest-builtin.cpp.orig	2016-08-16 20:00:25 UTC
+++ src/VBox/Runtime/common/crypto/digest-builtin.cpp
@@ -561,7 +561,7 @@ static PCRTCRDIGESTDESC const g_apDigest
  * OpenSSL EVP.
  */
 
-# if OPENSSL_VERSION_NUMBER >= 0x10100000
+# if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
 /** @impl_interface_method{RTCRDIGESTDESC::pfnNew} */
 static DECLCALLBACK(void*) rtCrDigestOsslEvp_New(void)
 {
@@ -597,7 +597,7 @@ static DECLCALLBACK(int) rtCrDigestOsslE
     if (fReInit)
     {
         pEvpType = EVP_MD_CTX_md(pThis);
-# if OPENSSL_VERSION_NUMBER >= 0x10100000
+# if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
         EVP_MD_CTX_reset(pThis);
 # else
         EVP_MD_CTX_cleanup(pThis);
@@ -616,7 +616,7 @@ static DECLCALLBACK(int) rtCrDigestOsslE
 static DECLCALLBACK(void) rtCrDigestOsslEvp_Delete(void *pvState)
 {
     EVP_MD_CTX *pThis = (EVP_MD_CTX *)pvState;
-# if OPENSSL_VERSION_NUMBER >= 0x10100000
+# if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
     EVP_MD_CTX_reset(pThis);
 # else
     EVP_MD_CTX_cleanup(pThis);
@@ -661,13 +661,13 @@ static RTCRDIGESTDESC const g_rtCrDigest
     NULL,
     RTDIGESTTYPE_UNKNOWN,
     EVP_MAX_MD_SIZE,
-# if OPENSSL_VERSION_NUMBER >= 0x10100000
+# if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
     0,
 # else
     sizeof(EVP_MD_CTX),
 # endif
     0,
-# if OPENSSL_VERSION_NUMBER >= 0x10100000
+# if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
     rtCrDigestOsslEvp_New,
     rtCrDigestOsslEvp_Free,
 # else
