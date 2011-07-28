From 51eb8798c3965b49f3010db82009d36429f28514 Mon Sep 17 00:00:00 2001
From: Dan Winship <danw@gnome.org>
Date: Wed, 29 Jun 2011 14:04:06 +0000
Subject: SoupServer: fix to not allow smuggling ".." into path

When SoupServer:raw-paths was set (the default), it was possible to
sneak ".." segments into the path passed to the SoupServerHandler,
which could then end up tricking some handlers into retrieving
arbitrary files from the filesystem. Fix that.

https://bugzilla.gnome.org/show_bug.cgi?id=653258
---
diff --git a/libsoup/soup-server.c b/libsoup/soup-server.c
index d56efd1..7225337 100644
--- libsoup/soup-server.c
+++ libsoup/soup-server.c
@@ -779,6 +779,15 @@ got_headers (SoupMessage *req, SoupClientContext *client)
 
 		uri = soup_message_get_uri (req);
 		decoded_path = soup_uri_decode (uri->path);
+
+		if (strstr (decoded_path, "/../") ||
+		    g_str_has_suffix (decoded_path, "/..")) {
+			/* Introducing new ".." segments is not allowed */
+			g_free (decoded_path);
+			soup_message_set_status (req, SOUP_STATUS_BAD_REQUEST);
+			return;
+		}
+
 		soup_uri_set_path (uri, decoded_path);
 		g_free (decoded_path);
 	}
--
cgit v0.9
