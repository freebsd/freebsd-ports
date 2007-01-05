--- src/config_rw.c.orig	Wed Jan  3 20:37:27 2007
+++ src/config_rw.c	Wed Jan  3 20:38:12 2007
@@ -84,9 +84,9 @@
 	{ "Encoder::Plugin", config.encoder.plugin,
 		STRING, 0, "ripperX_plugin-lame" },
 	{ "CdPlayer::Play_command", config.cd_player.play_command,
-		STRING, 0, "cdplay play %" },
+		STRING, 0, "cdcontrol play %" },
 	{ "CdPlayer::Stop_command", config.cd_player.stop_command,
-		STRING, 0, "cdplay stop" },
+		STRING, 0, "cdcontrol stop" },
 	{ "WavPlayer::Command", config.wav_player.command,
 		STRING, 0, "splay %" },
 	{ "Mp3Player::Command", config.mp3_player.command,
