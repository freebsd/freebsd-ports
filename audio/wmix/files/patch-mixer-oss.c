--- mixer-oss.c.orig	Wed Jul 14 18:00:14 2004
+++ mixer-oss.c	Wed Jul 14 17:58:50 2004
@@ -94,7 +94,9 @@
 
 static bool get_mixer_state(void)
 {
+#if 0
     struct mixer_info m_info;
+#endif
     int dev_lr_volume, dev_left_volume, dev_right_volume;
     float left, right;
     int srcmask;
@@ -103,14 +105,16 @@
     /* to really keep track of updates */
     static MixerChannel oldmixer[SOUND_MIXER_NRDEVICES];
 
+#if 0
     ioctl(mixer_fd, SOUND_MIXER_INFO, &m_info);
 
+   
     if (m_info.modify_counter == prev_modify_counter)
 	/*
 	 * Mixer state has not changed
 	 */
 	return false;
-
+#endif
     /* Mixer state was changed by another program, so we need
      * to update. As OSS cannot tell us specifically which
      * channels changed, we read all of them in.
@@ -157,7 +161,7 @@
 	}
 	mixer[ch].is_recording = ((1 << mixer[ch].dev) & srcmask) != 0;
     }
-    prev_modify_counter = m_info.modify_counter;
+    /* prev_modify_counter = m_info.modify_counter; */
     /* check if this was due to OSS stupidity or if we really changed */
     if (!memcmp(&mixer, &oldmixer, sizeof(mixer))) {
 	memcpy(&oldmixer, &mixer, sizeof(mixer));
@@ -224,7 +228,9 @@
 void mixer_init(const char *mixer_device, bool verbose, const char * exclude[])
 {
     int devmask, srcmask, recmask, stmask;
+#if 0
     struct mixer_info m_info;
+#endif
     int count;
     int mask;
 
@@ -256,15 +262,19 @@
 	exit(EXIT_FAILURE);
     }
 
+#if 0
     if (ioctl(mixer_fd, SOUND_MIXER_INFO, &m_info) == -1) {
 	fputs("error: could not read mixer info\n", stderr);
+	perror("ioctl");
 	exit(EXIT_FAILURE);
     }
 
+    
     if (verbose) {
 	printf("%s (%s)\n", m_info.name, m_info.id);
 	puts("Supported channels:");
     }
+#endif
     for (count = 0; count < SOUND_MIXER_NRDEVICES; count++) {
 	mask = 1 << count;
 	if ((mask & devmask) && (!is_exclude((short_names[count]),exclude))) {
