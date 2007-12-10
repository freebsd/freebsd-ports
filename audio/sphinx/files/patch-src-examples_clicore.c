--- src/examples/clicore.c.orig	2007-12-06 18:36:24.000000000 +0100
+++ src/examples/clicore.c	2007-12-06 18:36:39.000000000 +0100
@@ -323,7 +323,7 @@
 	memcpy (&addr.sin_addr, hp->h_addr, hp->h_length);
 	addr.sin_port = htons((u_short) port);
 	
-	if (connect (conn_sd, &addr, sizeof(addr)) == 0)
+	if (connect (conn_sd, (struct sockaddr *)&addr, sizeof(addr)) == 0)
 	    break;
 	print_errno ("connect");
 	cli_close (conn_sd);
