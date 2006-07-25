--- unix/unix_udp.c.orig	Mon Jul 24 14:57:47 2006
+++ unix/unix_udp.c	Mon Jul 24 15:00:18 2006
@@ -88,18 +88,18 @@
 	}
 }
 
-char	*NET_AdrToString (netAdr_t a)
+char	*NET_AdrToString (netAdr_t *a)
 {
 	static	char	str[64];
 	
-	switch (a.naType) {
+	switch (a->naType) {
 	case NA_LOOPBACK:
 		Q_snprintfz (str, sizeof (str), "loopback");
 		break;
 
 	case NA_IP:
 		Q_snprintfz (str, sizeof (str), "%i.%i.%i.%i:%i",
-			a.ip[0], a.ip[1], a.ip[2], a.ip[3], ntohs(a.port));
+			a->ip[0], a->ip[1], a->ip[2], a->ip[3], ntohs(a->port));
 		break;
 	}
 
@@ -224,7 +224,7 @@
 =============================================================================
 */
 
-qBool	NET_GetLoopPacket (int sock, netAdr_t *net_from, netMsg_t *net_message)
+qBool	NET_GetLoopPacket (netSrc_t sock, netAdr_t *net_from, netMsg_t *net_message)
 {
 	int		i;
 	loopBack_t	*loop;
@@ -248,7 +248,7 @@
 }
 
 
-void NET_SendLoopPacket (int sock, int length, void *data, netAdr_t to)
+void NET_SendLoopPacket (netSrc_t sock, int length, void *data, netAdr_t to)
 {
 	int		i;
 	loopBack_t	*loop;
@@ -264,7 +264,7 @@
 
 //=============================================================================
 
-qBool NET_GetPacket (int sock, netAdr_t *net_from, netMsg_t *net_message)
+qBool NET_GetPacket (netSrc_t sock, netAdr_t *net_from, netMsg_t *net_message)
 {
 	int 	ret;
 	struct sockaddr_in	from;
@@ -290,12 +290,12 @@
 		if (err == EWOULDBLOCK || err == ECONNREFUSED)
 			return qFalse;
 		Com_Printf (0, "NET_GetPacket: %s from %s\n", NET_ErrorString(),
-					NET_AdrToString(*net_from));
+					NET_AdrToString(net_from));
 		return 0;
 	}
 
 	if (ret == net_message->maxSize) {
-		Com_Printf (0, "Oversize packet from %s\n", NET_AdrToString (*net_from));
+		Com_Printf (0, "Oversize packet from %s\n", NET_AdrToString (net_from));
 		return qFalse;
 	}
 
@@ -308,15 +308,15 @@
 
 //=============================================================================
 
-int NET_SendPacket (int sock, int length, void *data, netAdr_t to)
+int NET_SendPacket (netSrc_t sock, int length, void *data, netAdr_t *to)
 {
 	int		ret;
 	struct sockaddr_in	addr;
 	int		net_socket;
 
-	switch (to.naType) {
+	switch (to->naType) {
 	case NA_LOOPBACK:
-		NET_SendLoopPacket (sock, length, data, to);
+		NET_SendLoopPacket (sock, length, data, *to);
 		return 0;
 
 	case NA_BROADCAST:
@@ -332,11 +332,11 @@
 		break;
 
 	default:
-		Com_Error (ERR_FATAL, "NET_SendPacket: bad address type: %d", to.naType);
+		Com_Error (ERR_FATAL, "NET_SendPacket: bad address type: %d", to->naType);
 		break;
 	}
 
-	NET_NetadrToSockadr (&to, &addr);
+	NET_NetadrToSockadr (to, &addr);
 
 	ret = sendto (net_socket, data, length, 0, (struct sockaddr *)&addr, sizeof(addr));
 	if (ret == -1) {
@@ -358,7 +358,7 @@
 A single player game will only use the loopback code
 ====================
 */
-int NET_Config (int openFlags)
+netConfig_t NET_Config (netConfig_t openFlags)
 {
 	int		i;
 
@@ -583,7 +583,7 @@
 */
 void NET_Init (void)
 {
-  cmd_netStats = Cmd_AddCommand (qFalse, "net_stats", NET_Stats_f, "Prints out connection information");
+  cmd_netStats = Cmd_AddCommand ("net_stats", NET_Stats_f, "Prints out connection information");
 }
 
 
