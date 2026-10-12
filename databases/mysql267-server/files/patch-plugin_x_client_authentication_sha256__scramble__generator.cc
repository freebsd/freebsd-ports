--- plugin/x/client/authentication/sha256_scramble_generator.cc.orig	2026-07-10 11:18:36 UTC
+++ plugin/x/client/authentication/sha256_scramble_generator.cc
@@ -100,7 +100,7 @@ bool SHA256_digest::retrieve_digest(unsigned char *dig
     return true;
   }
   m_ok = EVP_DigestFinal_ex(md_context, m_digest, nullptr);
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if defined(LIBRESSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
   EVP_MD_CTX_cleanup(md_context);
 #else  /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   EVP_MD_CTX_reset(md_context);
