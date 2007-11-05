--- src/irc_server.c.orig	2002-01-31 15:56:37.000000000 +0100
+++ src/irc_server.c	2007-11-05 12:35:57.000000000 +0100
@@ -700,7 +700,7 @@
               free(s);
 
               /* Was in the squelch list, so remove it and stop looking */
-              s = (l ? l->next : p->squelch_modes) = n;
+              s = *(l ? &(l->next) : &(p->squelch_modes)) = n;
               squelch = 1;
               break;
             } else {
@@ -741,7 +741,7 @@
               free(s);
 
               /* Was in the squelch list, so remove it and stop looking */
-              s = (l ? l->next : p->squelch_modes) = n;
+              s = *(l ? &(l->next) : &(p->squelch_modes)) = n;
               squelch = 1;
               break;
             } else {
@@ -1076,7 +1076,7 @@
       
         if (!strcmp(cmsg.cmd, "ACTION")) {
           if (p->conn_class->log_events & IRC_LOG_ACTION)
-            irclog_ctcp(p, msg.params[0], msg.src.orig, "%s", cmsg.orig);
+            irclog_ctcp(p, (msg.params != NULL ) ? msg.params[0]: "none", msg.src.orig, "%s", cmsg.orig);
 
         } else if (!strcmp(cmsg.cmd, "DCC")
                    && p->conn_class->dcc_proxy_incoming) {
