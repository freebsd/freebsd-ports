--- libwzd-core/wzd_tls.c.orig	2007-10-25 17:25:33 UTC
+++ libwzd-core/wzd_tls.c
@@ -297,7 +297,7 @@ int tls_init(void)
       return 1;
     }
 
-    SSL_CTX_set_client_CA_list(tls_ctx, (STACK *)ca_list);
+    SSL_CTX_set_client_CA_list(tls_ctx, ca_list);
   }
 
   SSL_CTX_set_session_cache_mode(tls_ctx, SSL_SESS_CACHE_CLIENT);
@@ -777,12 +777,11 @@ void * ssl_get_obj(wzd_context_t * context)
 
 #include <stdlib.h>
 #include <stdio.h>
+#include <string.h>
 
 #include <gnutls/gnutls.h>
-#include <gcrypt.h>
 #include <errno.h>
 #include <pthread.h>
-GCRY_THREAD_OPTION_PTHREAD_IMPL;
 
 #include <fcntl.h>
 
@@ -892,7 +891,6 @@ int tls_init(void)
 
   /* The order matters.
    */
-  gcry_control (GCRYCTL_SET_THREAD_CBS, &gcry_threads_pthread);
   gnutls_global_init();
 
   /** \todo TODO XXX move this code to global init ? */
@@ -946,19 +944,13 @@ int tls_exit(void)
 
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
 
@@ -1001,27 +993,6 @@ int tls_auth (const char *type, wzd_context_t * contex
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
