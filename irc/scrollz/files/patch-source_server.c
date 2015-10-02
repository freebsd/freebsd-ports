--- source/server.c.orig	2013-12-09 16:16:54.000000000 +0100
+++ source/server.c	2015-10-02 16:53:01.001012834 +0200
@@ -1512,9 +1512,16 @@ login_to_server(server)
             err = gnutls_handshake(server_list[server].session);
 #elif defined(HAVE_OPENSSL)
             SSLeay_add_ssl_algorithms();
+#ifndef OPENSSL_NO_SSL3
             server_list[server].meth = SSLv3_client_method();
+#else
+            server_list[server].meth = SSLv23_client_method();
+#endif
             SSL_load_error_strings();
             server_list[server].ctx = SSL_CTX_new(server_list[server].meth);
+#ifdef OPENSSL_NO_SSL3
+	    SSL_CTX_set_options(server_list[server].ctx, SSL_OP_NO_SSLv2);
+#endif
             CHK_NULL(server_list[server].ctx);
             server_list[server].ssl_fd = SSL_new(server_list[server].ctx);
             CHK_NULL(server_list[server].ssl_fd);
