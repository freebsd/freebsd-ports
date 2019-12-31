--- sql/auth/sha2_password_common.cc.orig	2019-05-16 05:06:00 UTC
+++ sql/auth/sha2_password_common.cc
@@ -146,7 +146,8 @@ bool SHA256_digest::retrieve_digest(unsigned char *dig
     DBUG_RETURN(true);
   }
   m_ok= EVP_DigestFinal_ex(md_context, m_digest, NULL);
-#if defined(HAVE_WOLFSSL) || OPENSSL_VERSION_NUMBER < 0x10100000L
+#if defined(HAVE_WOLFSSL) || OPENSSL_VERSION_NUMBER < 0x10100000L || \
+    (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x02070000fL)
   EVP_MD_CTX_cleanup(md_context);
 #else  /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   EVP_MD_CTX_reset(md_context);
