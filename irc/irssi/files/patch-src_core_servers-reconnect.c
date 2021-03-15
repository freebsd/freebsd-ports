--- src/core/servers-reconnect.c.orig	2019-08-29 13:48:46 UTC
+++ src/core/servers-reconnect.c
@@ -151,10 +151,6 @@ static int server_reconnect_timeout(void)
 
 static void sserver_connect(SERVER_SETUP_REC *rec, SERVER_CONNECT_REC *conn)
 {
-        conn->family = rec->family;
-	conn->address = g_strdup(rec->address);
-	if (conn->port == 0) conn->port = rec->port;
-
 	server_setup_fill_reconn(conn, rec);
 	server_reconnect_add(conn, rec->last_connect+reconnect_time);
 	server_connect_unref(conn);
@@ -181,10 +177,20 @@ server_connect_copy_skeleton(SERVER_CONNECT_REC *src, 
 	dest->tag = g_strdup(src->tag);
 
 	if (connect_info) {
-                dest->family = src->family;
+		dest->family = src->family;
 		dest->address = g_strdup(src->address);
 		dest->port = src->port;
 		dest->password = g_strdup(src->password);
+
+		dest->use_tls = src->use_tls;
+		dest->tls_cert = g_strdup(src->tls_cert);
+		dest->tls_pkey = g_strdup(src->tls_pkey);
+		dest->tls_verify = src->tls_verify;
+		dest->tls_cafile = g_strdup(src->tls_cafile);
+		dest->tls_capath = g_strdup(src->tls_capath);
+		dest->tls_ciphers = g_strdup(src->tls_ciphers);
+		dest->tls_pinned_cert = g_strdup(src->tls_pinned_cert);
+		dest->tls_pinned_pubkey = g_strdup(src->tls_pinned_pubkey);
 	}
 
 	dest->chatnet = g_strdup(src->chatnet);
@@ -207,16 +213,6 @@ server_connect_copy_skeleton(SERVER_CONNECT_REC *src, 
 	dest->no_autosendcmd = src->no_autosendcmd;
 	dest->unix_socket = src->unix_socket;
 
-	dest->use_tls = src->use_tls;
-	dest->tls_cert = g_strdup(src->tls_cert);
-	dest->tls_pkey = g_strdup(src->tls_pkey);
-	dest->tls_verify = src->tls_verify;
-	dest->tls_cafile = g_strdup(src->tls_cafile);
-	dest->tls_capath = g_strdup(src->tls_capath);
-	dest->tls_ciphers = g_strdup(src->tls_ciphers);
-	dest->tls_pinned_cert = g_strdup(src->tls_pinned_cert);
-	dest->tls_pinned_pubkey = g_strdup(src->tls_pinned_pubkey);
-
 	return dest;
 }
 
@@ -293,7 +289,7 @@ static void sig_reconnect(SERVER_REC *server)
 		    (!rec->last_connect || !rec->last_failed ||
 		     rec->last_connect < now-FAILED_RECONNECT_WAIT)) {
 			if (rec == sserver)
-                                conn->port = server->connrec->port;
+				conn->port = server->connrec->port;
 			sserver_connect(rec, conn);
 			return;
 		}
