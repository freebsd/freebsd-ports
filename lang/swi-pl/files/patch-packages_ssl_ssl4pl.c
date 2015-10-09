--- packages/ssl/ssl4pl.c.orig	2015-06-09 09:25:57 UTC
+++ packages/ssl/ssl4pl.c
@@ -1127,9 +1127,11 @@ pl_ssl_context(term_t role, term_t confi
 
   if (!PL_get_atom(method, &method_name))
      return PL_domain_error("ssl_method", method);
+#ifndef OPENSSL_NO_SSL3
   if (method_name == ATOM_sslv3)
     ssl_method = SSLv3_method();
-#ifdef HAVE_SSLV2_METHOD
+#endif
+#ifndef OPENSSL_NO_SSL2
   else if (method_name == ATOM_sslv2)
     ssl_method = SSLv2_method();
 #endif
@@ -1736,9 +1738,11 @@ pl_ssl_session(term_t stream_t, term_t s
 		      PL_INTEGER, (int)session->ssl_version))
     return FALSE;
 
+#ifndef OPENSSL_NO_SSL2
   if ( !add_key_string(list_t, FUNCTOR_session_key1,
 		       session->key_arg_length, session->key_arg) )
     return FALSE;
+#endif
 
   if ( !add_key_string(list_t, FUNCTOR_master_key1,
 		       session->master_key_length, session->master_key) )
