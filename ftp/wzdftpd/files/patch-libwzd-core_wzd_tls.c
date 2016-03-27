--- libwzd-core/wzd_tls.c.orig	2007-10-25 17:25:33 UTC
+++ libwzd-core/wzd_tls.c
@@ -946,19 +946,13 @@ int tls_exit(void)
 
 static gnutls_session initialize_tls_session(gnutls_connection_end con_end)
 {
-  /* Allow connections to servers that have OpenPGP keys as well.
-   */
-  const int cert_type_priority[3] = { GNUTLS_CRT_X509, GNUTLS_CRT_OPENPGP, 0 };
-
   gnutls_session session;
 
   gnutls_init(&session, con_end);
 
-  /* avoid calling all the priority functions, since the defaults
-   * are adequate.
+  /* Allow connections to servers that have OpenPGP keys as well.
    */
-  gnutls_set_default_priority(session);
-  gnutls_certificate_type_set_priority(session, cert_type_priority);
+  gnutls_priority_set_direct(session, "NORMAL:+CTYPE-OPENPGP", NULL);
 
   gnutls_credentials_set(session, GNUTLS_CRD_CERTIFICATE, x509_cred);
 
@@ -1001,27 +995,6 @@ int tls_auth (const char *type, wzd_cont
   }
 
   /** \todo XXX parse TLS cipher names */
-  {
-    /** Note that the priority is set on the client. The server does not use
-     * the algorithm's priority except for disabling algorithms that were not
-     * specified.
-     */
-    const int cipherPriority[] =
-    {
-      GNUTLS_CIPHER_ARCFOUR_128,
-      GNUTLS_CIPHER_3DES_CBC,
-      GNUTLS_CIPHER_AES_128_CBC,
-      GNUTLS_CIPHER_AES_256_CBC,
-      GNUTLS_CIPHER_ARCFOUR_40,
-#if ( (LIBGNUTLS_VERSION_MAJOR > 1) || (LIBGNUTLS_VERSION_MINOR >= 3) )
-      GNUTLS_CIPHER_RC2_40_CBC,
-      GNUTLS_CIPHER_DES_CBC,
-#endif
-      0
-    };
-
-    gnutls_cipher_set_priority(session, cipherPriority);
-  }
 
   /* ensure socket is non-blocking */
 #if defined(_MSC_VER) || (defined(__CYGWIN__) && defined(WINSOCK_SUPPORT))
