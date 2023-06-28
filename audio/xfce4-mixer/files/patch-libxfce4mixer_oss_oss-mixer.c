--- libxfce4mixer/oss/oss-mixer.c.orig	2022-11-29 19:59:39 UTC
+++ libxfce4mixer/oss/oss-mixer.c
@@ -80,7 +80,8 @@ gst_mixer_oss_get_mixer_flags (GstMixer *mixer)
 }
 
 
-static void gst_mixer_oss_set_volume (GstMixer *mixer, GstMixerTrack *track, gint *volumes)
+static void
+gst_mixer_oss_set_volume (GstMixer *mixer, GstMixerTrack *track, gint num_channels, gint *volumes)
 {
   int vol;
   int l = volumes[0], r = volumes[1];
