--- src/config_rw.c.orig	2008-01-28 06:00:09.000000000 +0100
+++ src/config_rw.c	2008-02-21 19:01:31.000000000 +0100
@@ -87,9 +87,9 @@
 	{ "Encoder::Plugin", config.encoder.plugin,
 		STRING, 0, "ripperX_plugin-lame" },
 	{ "CdPlayer::Play_command", config.cd_player.play_command,
-		STRING, 0, "cdplay %" },
+		STRING, 0, "cdcontrol play %" },
 	{ "CdPlayer::Stop_command", config.cd_player.stop_command,
-		STRING, 0, "cdstop" },
+		STRING, 0, "cdcontrol stop" },
 	{ "WavPlayer::Command", config.wav_player.command,
 		STRING, 0, "play %" },
 	{ "Mp3Player::Command", config.mp3_player.command,
