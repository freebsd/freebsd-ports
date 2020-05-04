--- sql/auth/sha2_password_common.cc
+++ sql/auth/sha2_password_common.cc
@@ -116,7 +116,8 @@ bool SHA256_digest::retrieve_digest(unsigned char *digest,
     DBUG_RETURN(true);
   }
   m_ok= EVP_DigestFinal_ex(md_context, m_digest, NULL);
-#if defined(HAVE_WOLFSSL) || OPENSSL_VERSION_NUMBER < 0x10100000L
+#if defined(HAVE_WOLFSSL) || OPENSSL_VERSION_NUMBER < 0x10100000L || \
+    (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x02090000fL)
   EVP_MD_CTX_cleanup(md_context);
 #else  /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   EVP_MD_CTX_reset(md_context);
