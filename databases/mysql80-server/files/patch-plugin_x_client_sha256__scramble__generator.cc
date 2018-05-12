--- plugin/x/client/sha256_scramble_generator.cc.orig	2018-05-09 14:20:16 UTC
+++ plugin/x/client/sha256_scramble_generator.cc
@@ -97,7 +97,7 @@ bool SHA256_digest::retrieve_digest(unsi
     DBUG_RETURN(true);
   }
   m_ok = EVP_DigestFinal_ex(md_context, m_digest, nullptr);
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if defined(LIBRESSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
   EVP_MD_CTX_cleanup(md_context);
 #else  /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   EVP_MD_CTX_reset(md_context);
