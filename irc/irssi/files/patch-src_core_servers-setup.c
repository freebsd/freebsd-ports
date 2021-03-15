--- src/core/servers-setup.c.orig	2019-08-29 13:48:46 UTC
+++ src/core/servers-setup.c
@@ -108,6 +108,35 @@ void server_setup_fill_reconn(SERVER_CONNECT_REC *conn
 	if (sserver->password != NULL && conn->password == NULL)
 		conn->password = g_strdup(sserver->password);
 
+	if (sserver->no_proxy)
+		g_free_and_null(conn->proxy);
+
+	if (sserver->family != 0 && conn->family == 0)
+		conn->family = sserver->family;
+	if (sserver->address && !conn->address)
+		conn->address = g_strdup(sserver->address);
+	if (sserver->port > 0 && conn->port <= 0)
+		conn->port = sserver->port;
+
+	conn->use_tls = sserver->use_tls;
+	if (conn->tls_cert == NULL && sserver->tls_cert != NULL && sserver->tls_cert[0] != '\0')
+		conn->tls_cert = g_strdup(sserver->tls_cert);
+	if (conn->tls_pkey == NULL && sserver->tls_pkey != NULL && sserver->tls_pkey[0] != '\0')
+		conn->tls_pkey = g_strdup(sserver->tls_pkey);
+	if (conn->tls_pass == NULL && sserver->tls_pass != NULL && sserver->tls_pass[0] != '\0')
+		conn->tls_pass = g_strdup(sserver->tls_pass);
+	conn->tls_verify = sserver->tls_verify;
+	if (conn->tls_cafile == NULL && sserver->tls_cafile != NULL && sserver->tls_cafile[0] != '\0')
+		conn->tls_cafile = g_strdup(sserver->tls_cafile);
+	if (conn->tls_capath == NULL && sserver->tls_capath != NULL && sserver->tls_capath[0] != '\0')
+		conn->tls_capath = g_strdup(sserver->tls_capath);
+	if (conn->tls_ciphers == NULL && sserver->tls_ciphers != NULL && sserver->tls_ciphers[0] != '\0')
+		conn->tls_ciphers = g_strdup(sserver->tls_ciphers);
+	if (conn->tls_pinned_cert == NULL && sserver->tls_pinned_cert != NULL && sserver->tls_pinned_cert[0] != '\0')
+		conn->tls_pinned_cert = g_strdup(sserver->tls_pinned_cert);
+	if (conn->tls_pinned_pubkey == NULL && sserver->tls_pinned_pubkey != NULL && sserver->tls_pinned_pubkey[0] != '\0')
+		conn->tls_pinned_pubkey = g_strdup(sserver->tls_pinned_pubkey);
+
 	signal_emit("server setup fill reconn", 2, conn, sserver);
 }
 
@@ -158,33 +187,6 @@ static void server_setup_fill_server(SERVER_CONNECT_RE
 	g_return_if_fail(IS_SERVER_SETUP(sserver));
 
 	sserver->last_connect = time(NULL);
-
-        if (sserver->no_proxy)
-		g_free_and_null(conn->proxy);
-
-	if (sserver->family != 0 && conn->family == 0)
-                conn->family = sserver->family;
-	if (sserver->port > 0 && conn->port <= 0)
-		conn->port = sserver->port;
-
-	conn->use_tls = sserver->use_tls;
-	if (conn->tls_cert == NULL && sserver->tls_cert != NULL && sserver->tls_cert[0] != '\0')
-		conn->tls_cert = g_strdup(sserver->tls_cert);
-	if (conn->tls_pkey == NULL && sserver->tls_pkey != NULL && sserver->tls_pkey[0] != '\0')
-		conn->tls_pkey = g_strdup(sserver->tls_pkey);
-	if (conn->tls_pass == NULL && sserver->tls_pass != NULL && sserver->tls_pass[0] != '\0')
-		conn->tls_pass = g_strdup(sserver->tls_pass);
-	conn->tls_verify = sserver->tls_verify;
-	if (conn->tls_cafile == NULL && sserver->tls_cafile != NULL && sserver->tls_cafile[0] != '\0')
-		conn->tls_cafile = g_strdup(sserver->tls_cafile);
-	if (conn->tls_capath == NULL && sserver->tls_capath != NULL && sserver->tls_capath[0] != '\0')
-		conn->tls_capath = g_strdup(sserver->tls_capath);
-	if (conn->tls_ciphers == NULL && sserver->tls_ciphers != NULL && sserver->tls_ciphers[0] != '\0')
-		conn->tls_ciphers = g_strdup(sserver->tls_ciphers);
-	if (conn->tls_pinned_cert == NULL && sserver->tls_pinned_cert != NULL && sserver->tls_pinned_cert[0] != '\0')
-		conn->tls_pinned_cert = g_strdup(sserver->tls_pinned_cert);
-	if (conn->tls_pinned_pubkey == NULL && sserver->tls_pinned_pubkey != NULL && sserver->tls_pinned_pubkey[0] != '\0')
-		conn->tls_pinned_pubkey = g_strdup(sserver->tls_pinned_pubkey);
 
 	server_setup_fill_reconn(conn, sserver);
 
