--- irc_channel.c.orig	2015-07-20 20:09:00 UTC
+++ irc_channel.c
@@ -444,7 +444,7 @@ void irc_channel_auto_joins(irc_t *irc, 
 			   can only auto-join them if their account is online. */
 			char *acc_s;
 
-			if (!aj || (ic->flags & IRC_CHANNEL_JOINED)) {
+			if (!aj && !(ic->flags & IRC_CHANNEL_JOINED)) {
 				/* Only continue if this one's marked as auto_join
 				   or if we're in it already. (Possible if the
 				   client auto-rejoined it before identyfing.) */
