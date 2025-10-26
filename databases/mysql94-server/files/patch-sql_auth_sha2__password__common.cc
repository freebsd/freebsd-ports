--- sql/auth/sha2_password_common.cc.orig	2024-04-10 06:26:28 UTC
+++ sql/auth/sha2_password_common.cc
@@ -102,7 +102,7 @@ bool SHA256_digest::retrieve_digest(unsigned char *dig
     return true;
   }
   m_ok = EVP_DigestFinal_ex(md_context, m_digest, nullptr);
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if defined(LIBRESSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
   EVP_MD_CTX_cleanup(md_context);
 #else  /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   EVP_MD_CTX_reset(md_context);
