Fixes compilation with irssi 1.4.2

--- src/core/icb-protocol.c.orig	2022-08-08 07:03:52 UTC
+++ src/core/icb-protocol.c
@@ -340,8 +340,8 @@ static void sig_server_connected(ICB_SERVER_REC *serve
                 return;
 
 	server->readtag =
-		g_input_add(net_sendbuffer_handle(server->handle),
-			    G_INPUT_READ,
+		i_input_add(net_sendbuffer_handle(server->handle),
+			    I_INPUT_READ,
 			    (GInputFunction) icb_parse_incoming, server);
 }
 
