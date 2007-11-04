--- src/irc_server.c.orig	2007-11-04 13:13:26.000000000 +0100
+++ src/irc_server.c	2007-11-04 13:13:47.000000000 +0100
@@ -1155,7 +1155,7 @@
       
         if (!strcmp(cmsg.cmd, "ACTION")) {
           irclog_log(p, IRC_LOG_ACTION, logdest, msg.src.orig,
-                     "%s", cmsg.paramstarts[0]);
+                     "%s", (cmsg.paramstarts != NULL) ? cmsg.paramstarts[0]: "none");
 
         } else if (!strcmp(cmsg.cmd, "DCC")
                    && p->conn_class->dcc_proxy_incoming) {
