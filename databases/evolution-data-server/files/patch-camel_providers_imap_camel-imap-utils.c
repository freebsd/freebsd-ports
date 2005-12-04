--- camel/providers/imap/camel-imap-utils.c.orig	Tue Nov 29 03:03:43 2005
+++ camel/providers/imap/camel-imap-utils.c	Sun Dec  4 23:13:35 2005
@@ -371,7 +371,7 @@ imap_parse_list_response (CamelImapStore
 		return FALSE;
 	
 	if (folder) {
-		char *astring;
+		char *astring, *mailbox;
 		
 		/* get the folder name */
 		word = imap_next_word (word);
@@ -380,8 +380,6 @@ imap_parse_list_response (CamelImapStore
 			return FALSE;
 
 		*folder = astring;
-
-		char *mailbox;
 
 		mailbox = imap_mailbox_decode (astring, strlen (astring));
 		g_free (astring);
