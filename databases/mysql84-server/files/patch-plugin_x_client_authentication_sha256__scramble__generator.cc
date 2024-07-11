--- plugin/x/client/authentication/sha256_scramble_generator.cc.orig	2024-04-10 06:26:28 UTC
+++ plugin/x/client/authentication/sha256_scramble_generator.cc
@@ -98,7 +98,7 @@ bool SHA256_digest::retrieve_digest(unsigned char *dig
     return true;
   }
   m_ok = EVP_DigestFinal_ex(md_context, m_digest, nullptr);
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if defined(LIBRESSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
   EVP_MD_CTX_cleanup(md_context);
 #else  /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   EVP_MD_CTX_reset(md_context);
