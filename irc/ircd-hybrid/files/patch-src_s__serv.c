--- src/s_serv.c.orig	2013-06-23 19:49:22.000000000 +0200
+++ src/s_serv.c	2015-02-27 13:02:55.849862715 +0100
@@ -690,9 +690,6 @@
   const char *inpath;
   static char inpath_ip[HOSTLEN * 2 + USERLEN + 6];
   dlink_node *ptr;
-#ifdef HAVE_LIBCRYPTO
-  const COMP_METHOD *compression = NULL, *expansion = NULL;
-#endif
 
   assert(client_p != NULL);
 
@@ -799,26 +796,23 @@
 #ifdef HAVE_LIBCRYPTO
   if (client_p->localClient->fd.ssl)
   {
-    compression = SSL_get_current_compression(client_p->localClient->fd.ssl);
-    expansion   = SSL_get_current_expansion(client_p->localClient->fd.ssl);
-
     sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                          "Link with %s established: [SSL: %s, Compression/Expansion method: %s/%s] (Capabilities: %s)",
                          inpath_ip, ssl_get_cipher(client_p->localClient->fd.ssl),
-                         compression ? SSL_COMP_get_name(compression) : "NONE",
-                         expansion ? SSL_COMP_get_name(expansion) : "NONE",
+                         "NONE",
+                         "NONE",
                          show_capabilities(client_p));
     /* Now show the masked hostname/IP to opers */
     sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                          "Link with %s established: [SSL: %s, Compression/Expansion method: %s/%s] (Capabilities: %s)",
                          inpath, ssl_get_cipher(client_p->localClient->fd.ssl),
-                         compression ? SSL_COMP_get_name(compression) : "NONE",
-                         expansion ? SSL_COMP_get_name(expansion) : "NONE",
+                         "NONE",
+                         "NONE",
                          show_capabilities(client_p));
     ilog(LOG_TYPE_IRCD, "Link with %s established: [SSL: %s, Compression/Expansion method: %s/%s] (Capabilities: %s)",
          inpath_ip, ssl_get_cipher(client_p->localClient->fd.ssl),
-         compression ? SSL_COMP_get_name(compression) : "NONE",
-         expansion ? SSL_COMP_get_name(expansion) : "NONE",
+         "NONE",
+         "NONE",
          show_capabilities(client_p));
   }
   else
