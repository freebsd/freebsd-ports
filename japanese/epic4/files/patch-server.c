--- source/server.c.orig	Fri Sep 29 03:16:55 2000
+++ source/server.c	Mon Dec  4 03:44:17 2000
@@ -826,6 +826,7 @@
 	char	buffer[BIG_BUFFER_SIZE * 3 + 1]; /* make this buffer *much*
 						  * bigger than needed */
 	size_t	size = BIG_BUFFER_SIZE * 3;
+	char    jis_buffer[BIG_BUFFER_SIZE + 1];
 	int	len,
 		des;
 	int	server;
@@ -845,16 +846,18 @@
 				yell("mangle_line truncated results!  Ick.");
 		}
 
+		Euc2Jis(buffer, jis_buffer, IRCD_BUFFER_SIZE -2);
+		len = strlen(jis_buffer);
 		server_list[server].sent = 1;
 		if (len > (IRCD_BUFFER_SIZE - 2) || len == -1)
 			buffer[IRCD_BUFFER_SIZE - 2] = 0;
 		if (x_debug & DEBUG_OUTBOUND)
 			yell("[%d] -> [%s]", des, buffer);
-		strmcat(buffer, "\r\n", IRCD_BUFFER_SIZE);
+		strmcat(jis_buffer, "\r\n", IRCD_BUFFER_SIZE);
 		if (do_hook(SEND_TO_SERVER_LIST, "%d %d %s", 
-				server, des, buffer))
+				server, des, jis_buffer))
 		{
-		    if (write(des, buffer, strlen(buffer)) == -1 && 
+		    if (write(des, jis_buffer, strlen(jis_buffer)) == -1 && 
 			(!get_int_var(NO_FAIL_DISCONNECT_VAR)))
 		    {
 			server_list[server].save_channels = 1;
