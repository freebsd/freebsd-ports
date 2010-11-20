--- remote/dbus/rb-client.c.orig	2010-10-10 11:56:07.000000000 -0400
+++ remote/dbus/rb-client.c	2010-10-10 11:57:02.000000000 -0400
@@ -54,7 +54,7 @@ static gboolean previous = FALSE;
 static gboolean notify = FALSE;
 
 static gboolean play = FALSE;
-static gboolean pause = FALSE;
+static gboolean rbpause = FALSE;
 static gboolean play_pause = FALSE;
 static gboolean stop = FALSE;
 
@@ -91,7 +91,7 @@ static GOptionEntry args[] = {
 	{ "notify", 0, 0, G_OPTION_ARG_NONE, &notify, N_("Show notification of the playing song"), NULL },
 
 	{ "play", 0, 0, G_OPTION_ARG_NONE, &play, N_("Resume playback if currently paused"), NULL },
-	{ "pause", 0, 0, G_OPTION_ARG_NONE, &pause, N_("Pause playback if currently playing"), NULL },
+	{ "pause", 0, 0, G_OPTION_ARG_NONE, &rbpause, N_("Pause playback if currently playing"), NULL },
 	{ "play-pause", 0, 0, G_OPTION_ARG_NONE, &play_pause, N_("Toggle play/pause mode"), NULL },
 /*	{ "stop", 0, 0, G_OPTION_ARG_NONE, &stop, N_("Stop playback"), NULL }, */
 
@@ -608,7 +608,7 @@ main (int argc, char **argv)
 	if (next || previous ||
 	    clear_queue ||
 	    play_uri || other_stuff ||
-	    play || pause || play_pause || stop ||
+	    play || rbpause || play_pause || stop ||
 	    print_playing || print_playing_format || notify ||
 	    (set_volume > -0.01) || volume_up || volume_down || print_volume || mute || unmute || (set_rating > -0.01))
 		no_present = TRUE;
@@ -696,7 +696,7 @@ main (int argc, char **argv)
 	org_gnome_Rhythmbox_Player_get_playing (player_proxy, &is_playing, &error);
 	if (!annoy (&error)) {
 		rb_debug ("playback state: %d", is_playing);
-		if (play || pause || play_pause) {
+		if (play || rbpause || play_pause) {
 			if (is_playing != play || play_pause) {
 				rb_debug ("calling playPause to change playback state");
 				org_gnome_Rhythmbox_Player_play_pause (player_proxy, FALSE, &error);
