--- src/dhcp.c.orig	2024-02-13 13:49:15 UTC
+++ src/dhcp.c
@@ -1121,6 +1121,9 @@ static int relay_upstream4(int iface_index, struct dhc
 	to.sa.sa_family = AF_INET;
 	to.in.sin_addr = relay->server.addr4;
 	to.in.sin_port = htons(relay->port);
+#ifdef HAVE_SOCKADDR_SA_LEN
+	to.in.sin_len = sizeof(struct sockaddr_in);
+#endif
 	
 	/* Broadcasting to server. */
 	if (relay->server.addr4.s_addr == 0)
