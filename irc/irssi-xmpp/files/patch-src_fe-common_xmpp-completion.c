Fix module loading:

    Irssi: Error loading module xmpp/fe:
    /usr/local/lib/irssi/modules/libfe_xmpp.so: Undefined symbol
    "glist_find_string"

--- src/fe-common/xmpp-completion.c.orig	2022-08-02 10:48:55 UTC
+++ src/fe-common/xmpp-completion.c
@@ -287,7 +287,7 @@ get_channels(XMPP_SERVER_REC *server, const char *word
 		    chat_type, XMPP_PROTOCOL_NAME)
 		    || *channel_setup->name != '#')
 		    && g_ascii_strncasecmp(channel_setup->name, word, len) == 0
-		    && glist_find_string(list, channel_setup->name) == NULL)
+		    && i_list_find_string(list, channel_setup->name) == NULL)
 			list = g_list_append(list,
 			    g_strdup(channel_setup->name));
 	}
