--- src/plugins/wavetbl_fluidsynth.c.orig	Fri Jun 25 18:02:19 2004
+++ src/plugins/wavetbl_fluidsynth.c	Fri Jun 25 18:03:08 2004
@@ -154,7 +154,7 @@
   { "fluidsynth", "audio_type", G_TOKEN_STRING, {""}},
   { NULL, "audio_device", G_TOKEN_STRING, {""}},
   { NULL, "audio_bufsize", G_TOKEN_INT, {GINT_TO_POINTER (64)}},
-  { NULL, "audio_bufcount", G_TOKEN_INT, {GINT_TO_POINTER (3)}},
+  { NULL, "audio_bufcount", G_TOKEN_INT, {GINT_TO_POINTER (16)}},
   { NULL, "midi_type", G_TOKEN_STRING, {""}},
   { NULL, "midi_device", G_TOKEN_STRING, {""}},
   { NULL, "master_gain", G_TOKEN_FLOAT, {v_float:0.0}},
