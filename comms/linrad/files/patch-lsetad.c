--- lsetad.c.orig	2008-07-18 20:59:42.000000000 -0400
+++ lsetad.c	2008-07-18 21:02:51.000000000 -0400
@@ -1234,8 +1234,10 @@
 {
 unsigned int val;
 int ad_bytes_per_sample;
+#ifdef ALSA_PRESENT
 static snd_pcm_format_t format;
 snd_pcm_hw_params_t *hw_ad_params;
+#endif
 char ss[sizeof(DEVNAME_BASE)+2];
 int i, j, err, frag, resample;
 float t1;
@@ -1480,8 +1482,10 @@
 {
 char *buf;
 unsigned int val;
+#ifdef ALSA_PRESENT
 static snd_pcm_format_t format;
 snd_pcm_hw_params_t *hw_da_params;
+#endif
 int i, j, dir, err, frag, resample;
 char ss[sizeof(DEVNAME_BASE)+2];
 float t1;
@@ -1815,8 +1819,10 @@
 {
 int ad_bytes_per_sample;
 unsigned int val;
+#ifdef ALSA_PRESENT
 static snd_pcm_format_t format;
 snd_pcm_hw_params_t *hw_ad_params;
+#endif
 char ss[sizeof(DEVNAME_BASE)+2];
 float t1;
 int i, j, err, frag, resample;
@@ -2123,8 +2129,10 @@
 void open_rx_sndout(void)
 {
 unsigned int val;
+#ifdef ALSA_PRESENT
 static snd_pcm_format_t format;
 snd_pcm_hw_params_t *hw_da_params;
+#endif
 char ss[sizeof(DEVNAME_BASE)+2];
 int i, j, dir, err, resample;
 int old_disksave_flag, old_mode, old_chan, old_speed;
