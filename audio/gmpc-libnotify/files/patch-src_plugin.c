--- src/plugin.c.orig	2011-08-15 20:17:11.000000000 +0200
+++ src/plugin.c	2011-08-15 20:18:35.000000000 +0200
@@ -149,16 +149,13 @@ static void libnotify_song_changed(MpdOb
 		if(not == NULL)
 		{
 			//            notify_notification_close(not, NULL);
-			not = notify_notification_new(summary, buffer,NULL, NULL);
+			not = notify_notification_new(summary, buffer,NULL);
 		}
 		else{
 			notify_notification_update(not, summary, buffer, NULL);
 		}
 		notify_notification_set_urgency(not, NOTIFY_URGENCY_LOW);
 
-		if(cfg_get_single_value_as_int_with_default(config, "libnotify-plugin", "attach-to-tray", TRUE))
-			notify_notification_attach_to_status_icon(not, tray_icon2_gsi);
-
 		g_free(summary);
 		/* Add the song to the widget */
 		g_object_set_data_full(G_OBJECT(not), "mpd-song", mpd_songDup(song),  (GDestroyNotify)mpd_freeSong);
