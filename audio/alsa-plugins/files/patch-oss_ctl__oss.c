--- oss/ctl_oss.c.orig	2022-01-29 13:06:39 UTC
+++ oss/ctl_oss.c
@@ -26,7 +26,11 @@
 #include <sys/ioctl.h>
 #include <alsa/asoundlib.h>
 #include <alsa/control_external.h>
+#ifdef __linux__
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
+#endif
 
 typedef struct snd_ctl_oss {
 	snd_ctl_ext_t ext;
@@ -52,7 +56,7 @@ static const char *const vol_devices[SOUND_MIXER_NRDEV
 	[SOUND_MIXER_CD] =	"CD Playback Volume",
 	[SOUND_MIXER_IMIX] =	"Monitor Mix Playback Volume",
 	[SOUND_MIXER_ALTPCM] =	"Headphone Playback Volume",
-	[SOUND_MIXER_RECLEV] =	"Capture Volume",
+	[SOUND_MIXER_RECLEV] =	"Master Capture Volume",
 	[SOUND_MIXER_IGAIN] =	"Capture Volume",
 	[SOUND_MIXER_OGAIN] =	"Playback Volume",
 	[SOUND_MIXER_LINE1] =	"Aux Playback Volume",
@@ -362,7 +366,9 @@ SND_CTL_PLUGIN_DEFINE_FUNC(oss)
 {
 	snd_config_iterator_t it, next;
 	const char *device = "/dev/mixer";
+#ifndef __FreeBSD__
 	struct mixer_info mixinfo;
+#endif
 	int i, err, val;
 	snd_ctl_oss_t *oss;
 	
@@ -399,19 +405,29 @@ SND_CTL_PLUGIN_DEFINE_FUNC(oss)
 		goto error;
 	}
 
+#ifndef __FreeBSD__
 	if (ioctl(oss->fd, SOUND_MIXER_INFO, &mixinfo) < 0) {
 		err = -errno;
 		SNDERR("Cannot get mixer info for device %s", device);
 		goto error;
 	}
+#endif
 
 	oss->ext.version = SND_CTL_EXT_VERSION;
 	oss->ext.card_idx = 0; /* FIXME */
+#ifdef __FreeBSD__
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
