--- src/fe-common/irc/fe-irc-messages.c.orig	Sat Oct 20 14:45:59 2007
+++ src/fe-common/irc/fe-irc-messages.c	Sat Oct 20 14:46:21 2007
@@ -44,7 +44,7 @@ static const char *skip_target(IRC_SERVER_REC *server,
 	const char *val, *chars;
 
 	/* Quick check */
-	if (server->prefix[(int)(unsigned char)*target] == 0)
+	if (server == NULL || server->prefix[(int)(unsigned char)*target] == 0)
 		return target;
 
 	/* Hack: for bahamut 1.4 which sends neither STATUSMSG nor
