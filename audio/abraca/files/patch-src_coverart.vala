--- src/coverart.vala.orig	2011-06-24 14:41:53.000000000 +0200
+++ src/coverart.vala	2011-06-24 14:42:25.000000000 +0200
@@ -412,7 +412,7 @@ namespace Abraca {
 			if (!get_track_ids (candidates, pixbuf, out ids))
 				return true;
 
-			char[] buffer;
+			uint8[] buffer;
 			if (!pixbuf.save_to_buffer (out buffer, "png"))
 				return true;
 
@@ -420,7 +420,7 @@ namespace Abraca {
 			/* TODO: Need to store ids here due to a Vala reference bug. */
 			selected_ids = ids;
 
-			client.xmms.bindata_add ((uint8[]) buffer).notifier_set (on_bindata_add);
+			client.xmms.bindata_add (buffer).notifier_set (on_bindata_add);
 
 
 			return true;
