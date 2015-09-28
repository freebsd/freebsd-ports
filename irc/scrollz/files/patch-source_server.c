--- source/server.c.orig	2015-09-28 16:49:24 UTC
+++ source/server.c
@@ -1512,9 +1512,16 @@ login_to_server(server)
             err = gnutls_handshake(server_list[server].session);
 #elif defined(HAVE_OPENSSL)
             SSLeay_add_ssl_algorithms();
+#ifndef OPENSSL_NO_SSL3
             server_list[server].meth = SSLv3_client_method();
-            SSL_load_error_strings();
-            server_list[server].ctx = SSL_CTX_new(server_list[server].meth);
+	    SSL_load_error_strings();
+	    server_list[server].ctx = SSL_CTX_new(server_list[server].meth);
+#else
+	    server_list[server].meth = SSLv23_client_method();
+	    SSL_load_error_strings();
+	    server_list[server].ctx = SSL_CTX_new(server_list[server].meth);
+	    SSL_CTX_set_options(server_list[server].ctx, SSL_OP_NO_SSLv3 | SSL_OP_NO_SSLv2);
+#endif
             CHK_NULL(server_list[server].ctx);
             server_list[server].ssl_fd = SSL_new(server_list[server].ctx);
             CHK_NULL(server_list[server].ssl_fd);
