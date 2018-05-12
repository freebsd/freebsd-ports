--- sql/auth/sha2_password_common.cc.orig	2018-05-06 18:47:55 UTC
+++ sql/auth/sha2_password_common.cc
@@ -101,7 +101,7 @@ bool SHA256_digest::retrieve_digest(unsi
     DBUG_RETURN(true);
   }
   m_ok = EVP_DigestFinal_ex(md_context, m_digest, NULL);
-#if defined(HAVE_WOLFSSL) || OPENSSL_VERSION_NUMBER < 0x10100000L
+#if defined(HAVE_WOLFSSL) || defined(LIBRESSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
   EVP_MD_CTX_cleanup(md_context);
 #else  /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   EVP_MD_CTX_reset(md_context);
