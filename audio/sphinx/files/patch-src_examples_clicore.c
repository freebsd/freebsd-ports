--- src/examples/clicore.c.orig	2001-12-13 21:11:13 UTC
+++ src/examples/clicore.c
@@ -323,7 +323,7 @@ SOCKET cli_open (char *hostname, int32 p
 	memcpy (&addr.sin_addr, hp->h_addr, hp->h_length);
 	addr.sin_port = htons((u_short) port);
 	
-	if (connect (conn_sd, &addr, sizeof(addr)) == 0)
+	if (connect (conn_sd, (struct sockaddr *)&addr, sizeof(addr)) == 0)
 	    break;
 	print_errno ("connect");
 	cli_close (conn_sd);
