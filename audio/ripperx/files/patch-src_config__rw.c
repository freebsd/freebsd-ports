--- src/config_rw.c.orig	2008-01-25 09:53:50 UTC
+++ src/config_rw.c
@@ -87,9 +87,9 @@ static struct {
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
