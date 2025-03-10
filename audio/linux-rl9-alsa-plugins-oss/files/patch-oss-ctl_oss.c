--- oss/ctl_oss.c.orig	2018-04-03 07:01:38 UTC
+++ oss/ctl_oss.c
@@ -362,7 +362,9 @@ SND_CTL_PLUGIN_DEFINE_FUNC(oss)
 {
 	snd_config_iterator_t it, next;
 	const char *device = "/dev/mixer";
+#ifndef FREEBSD_OSS
 	struct mixer_info mixinfo;
+#endif
 	int i, err, val;
 	snd_ctl_oss_t *oss;
 	
@@ -399,19 +401,29 @@ SND_CTL_PLUGIN_DEFINE_FUNC(oss)
 		goto error;
 	}
 
+#ifndef FREEBSD_OSS
 	if (ioctl(oss->fd, SOUND_MIXER_INFO, &mixinfo) < 0) {
 		err = -errno;
 		SNDERR("Cannot get mixer info for device %s", device);
 		goto error;
 	}
+#endif
 
 	oss->ext.version = SND_CTL_EXT_VERSION;
 	oss->ext.card_idx = 0; /* FIXME */
+#ifdef FREEBSD_OSS
+	strncpy(oss->ext.id, "fbsd", sizeof(oss->ext.id) - 1);
+	strcpy(oss->ext.driver, "FreeBSD/OSS plugin");
+	strncpy(oss->ext.name, "FreeBSD/OSS", sizeof(oss->ext.name) - 1);
+	strncpy(oss->ext.longname, "FreeBSD/OSS", sizeof(oss->ext.longname) - 1);
+	strncpy(oss->ext.mixername, "FreeBSD/OSS", sizeof(oss->ext.mixername) - 1);
+#else
 	strncpy(oss->ext.id, mixinfo.id, sizeof(oss->ext.id) - 1);
 	strcpy(oss->ext.driver, "OSS-Emulation");
 	strncpy(oss->ext.name, mixinfo.name, sizeof(oss->ext.name) - 1);
 	strncpy(oss->ext.longname, mixinfo.name, sizeof(oss->ext.longname) - 1);
 	strncpy(oss->ext.mixername, mixinfo.name, sizeof(oss->ext.mixername) - 1);
+#endif
 	oss->ext.poll_fd = -1;
 	oss->ext.callback = &oss_ext_callback;
 	oss->ext.private_data = oss;
