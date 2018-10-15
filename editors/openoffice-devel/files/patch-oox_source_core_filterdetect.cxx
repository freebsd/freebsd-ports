--- oox/source/core/filterdetect.cxx.orig	2018-04-13 00:54:08 UTC
+++ oox/source/core/filterdetect.cxx
@@ -26,6 +26,7 @@
 #include <com/sun/star/io/XStream.hpp>
 #include <comphelper/docpasswordhelper.hxx>
 #include <comphelper/mediadescriptor.hxx>
+#include <openssl/opensslv.h>
 #include <openssl/evp.h>
 #include <rtl/digest.h>
 #include "oox/core/fastparser.hxx"
@@ -355,25 +356,39 @@ bool lclCheckEncryptionData( const sal_uInt8* pnKey, s
     if ( nKeySize == 16 && nVerifierSize == 16 && nVerifierHashSize == 32 )
     {
         // check password
+        EVP_CIPHER_CTX *pAes_ctx;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
         EVP_CIPHER_CTX aes_ctx;
         EVP_CIPHER_CTX_init( &aes_ctx );
-        EVP_DecryptInit_ex( &aes_ctx, EVP_aes_128_ecb(), 0, pnKey, 0 );
-        EVP_CIPHER_CTX_set_padding( &aes_ctx, 0 );
+        pAes_ctx = &aes_ctx;
+#else
+        pAes_ctx = EVP_CIPHER_CTX_new();
+#endif
+        EVP_DecryptInit_ex( pAes_ctx, EVP_aes_128_ecb(), 0, pnKey, 0 );
+        EVP_CIPHER_CTX_set_padding( pAes_ctx, 0 );
         int nOutLen = 0;
         sal_uInt8 pnTmpVerifier[ 16 ];
         (void) memset( pnTmpVerifier, 0, sizeof(pnTmpVerifier) );
 
-        /*int*/ EVP_DecryptUpdate( &aes_ctx, pnTmpVerifier, &nOutLen, pnVerifier, nVerifierSize );
+        /*int*/ EVP_DecryptUpdate( pAes_ctx, pnTmpVerifier, &nOutLen, pnVerifier, nVerifierSize );
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
         EVP_CIPHER_CTX_cleanup( &aes_ctx );
 
         EVP_CIPHER_CTX_init( &aes_ctx );
-        EVP_DecryptInit_ex( &aes_ctx, EVP_aes_128_ecb(), 0, pnKey, 0 );
-        EVP_CIPHER_CTX_set_padding( &aes_ctx, 0 );
+#else
+        EVP_CIPHER_CTX_reset( pAes_ctx );
+#endif
+        EVP_DecryptInit_ex( pAes_ctx, EVP_aes_128_ecb(), 0, pnKey, 0 );
+        EVP_CIPHER_CTX_set_padding( pAes_ctx, 0 );
         sal_uInt8 pnTmpVerifierHash[ 32 ];
         (void) memset( pnTmpVerifierHash, 0, sizeof(pnTmpVerifierHash) );
 
-        /*int*/ EVP_DecryptUpdate( &aes_ctx, pnTmpVerifierHash, &nOutLen, pnVerifierHash, nVerifierHashSize );
+        /*int*/ EVP_DecryptUpdate( pAes_ctx, pnTmpVerifierHash, &nOutLen, pnVerifierHash, nVerifierHashSize );
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
         EVP_CIPHER_CTX_cleanup( &aes_ctx );
+#else
+        EVP_CIPHER_CTX_free( pAes_ctx );
+#endif
 
         rtlDigest aDigest = rtl_digest_create( rtl_Digest_AlgorithmSHA1 );
         rtlDigestError aError = rtl_digest_update( aDigest, pnTmpVerifier, sizeof( pnTmpVerifier ) );
@@ -562,10 +577,16 @@ Reference< XInputStream > FilterDetect::extractUnencry
                 BinaryXOutputStream aDecryptedPackage( xDecryptedPackage, true );
                 BinaryXInputStream aEncryptedPackage( xEncryptedPackage, true );
 
+                EVP_CIPHER_CTX *pAes_ctx;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
                 EVP_CIPHER_CTX aes_ctx;
                 EVP_CIPHER_CTX_init( &aes_ctx );
-                EVP_DecryptInit_ex( &aes_ctx, EVP_aes_128_ecb(), 0, aVerifier.getKey(), 0 );
-                EVP_CIPHER_CTX_set_padding( &aes_ctx, 0 );
+                pAes_ctx = &aes_ctx;
+#else
+                pAes_ctx = EVP_CIPHER_CTX_new();
+#endif
+                EVP_DecryptInit_ex( pAes_ctx, EVP_aes_128_ecb(), 0, aVerifier.getKey(), 0 );
+                EVP_CIPHER_CTX_set_padding( pAes_ctx, 0 );
 
                 sal_uInt8 pnInBuffer[ 1024 ];
                 sal_uInt8 pnOutBuffer[ 1024 ];
@@ -574,13 +595,17 @@ Reference< XInputStream > FilterDetect::extractUnencry
                 aEncryptedPackage.skip( 8 ); // decrypted size
                 while( (nInLen = aEncryptedPackage.readMemory( pnInBuffer, sizeof( pnInBuffer ) )) > 0 )
                 {
-                    EVP_DecryptUpdate( &aes_ctx, pnOutBuffer, &nOutLen, pnInBuffer, nInLen );
+                    EVP_DecryptUpdate( pAes_ctx, pnOutBuffer, &nOutLen, pnInBuffer, nInLen );
                     aDecryptedPackage.writeMemory( pnOutBuffer, nOutLen );
                 }
-                EVP_DecryptFinal_ex( &aes_ctx, pnOutBuffer, &nOutLen );
+                EVP_DecryptFinal_ex( pAes_ctx, pnOutBuffer, &nOutLen );
                 aDecryptedPackage.writeMemory( pnOutBuffer, nOutLen );
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
                 EVP_CIPHER_CTX_cleanup( &aes_ctx );
+#else
+                EVP_CIPHER_CTX_free( pAes_ctx );
+#endif
                 xDecryptedPackage->flush();
                 aDecryptedPackage.seekToStart();
 
