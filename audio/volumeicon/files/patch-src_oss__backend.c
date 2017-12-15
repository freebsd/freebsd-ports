--- src/oss_backend.c.orig	2015-03-02 22:54:36 UTC
+++ src/oss_backend.c
@@ -22,7 +22,7 @@
 //##############################################################################
 
 #include OSS_HEADER
-#include <stropts.h>
+#include <sys/soundcard.h>
 #include <fcntl.h>
 #include <assert.h>
 #include <stdlib.h>
@@ -30,12 +30,16 @@
 
 #include "oss_backend.h"
 
+#define	MIXT_MONOSLIDER16	19
+#define	MIXT_STEREOSLIDER16	20
+#define	MIXT_MUTE		21
+
 //##############################################################################
 // Static variables
 //##############################################################################
 static char * m_channel = NULL;
 static GList * m_channel_names = NULL;
-static int m_actual_maxvalue = 0;
+//static int m_actual_maxvalue = 0;
 static int m_mixer_fd = -1;
 static oss_mixext m_ext;
 
@@ -44,6 +48,7 @@ static oss_mixext m_ext;
 //##############################################################################
 static int get_raw_value()
 {
+#if 0
 	assert(m_mixer_fd != -1);
 
 	oss_mixer_value vr;
@@ -51,7 +56,7 @@ static int get_raw_value()
 	vr.ctrl = m_ext.ctrl;
 	vr.timestamp = m_ext.timestamp;
 
-	int result = ioctl(m_mixer_fd, SNDCTL_MIX_READ, &vr);
+	int result = ioctl(m_mixer_fd, SOUND_MIXER_READ_VOLUME, &vr);
 	if(result == -1)
 		return 0;
 
@@ -78,6 +83,7 @@ static int get_raw_value()
 			return short_value->lower;
 	}
 
+#endif
 	return 0;
 }
 
@@ -97,9 +103,20 @@ const GList * oss_get_channel_names()
 int oss_get_volume()
 {
 	assert(m_mixer_fd != -1);
+#if 0
 	if(m_actual_maxvalue == 0)
 		return 0;
 	return 100 * get_raw_value() / m_actual_maxvalue;
+#endif
+
+	int current_volume;
+	if (ioctl(m_mixer_fd, SOUND_MIXER_READ_VOLUME, &current_volume) == -1) {
+                perror("Cannot read volume!");
+                exit(EXIT_FAILURE);
+        }
+
+        /* Only the left channel is returned */
+        return current_volume & 0x7f;
 }
 
 gboolean oss_get_mute()
@@ -108,6 +125,7 @@ gboolean oss_get_mute()
 
 	gboolean mute = FALSE;
 
+#if 0
 	// Save current control;
 	int parent = m_ext.parent;
 	int control = m_ext.ctrl;
@@ -132,6 +150,7 @@ gboolean oss_get_mute()
 	// Restore to previous control
 	m_ext.ctrl = control;
 	ioctl(m_mixer_fd, SNDCTL_MIX_EXTINFO, &m_ext);
+#endif
 
 	return mute;
 }
@@ -148,12 +167,13 @@ void oss_setup(const gchar * card, const
 	char * devmixer;
 	if((devmixer=getenv("OSS_MIXERDEV")) == NULL)
 		devmixer = "/dev/mixer";
-	if((m_mixer_fd = open(devmixer, O_RDWR, 0)) == -1)
+	if((m_mixer_fd = open(devmixer, O_RDWR)) == -1)
 	{
 		perror(devmixer);
 		exit(1);
 	}
 
+#if 0
 	// Check that there is at least one mixer
 	int nmix;
 	ioctl(m_mixer_fd, SNDCTL_MIX_NRMIX, &nmix);
@@ -163,6 +183,7 @@ void oss_setup(const gchar * card, const
 		exit(EXIT_FAILURE);
 	}
 
+
 	m_ext.dev=0;
 	m_ext.ctrl = 0;
 	while(ioctl(m_mixer_fd, SNDCTL_MIX_EXTINFO, &m_ext) >= 0)
@@ -175,6 +196,7 @@ void oss_setup(const gchar * card, const
 		}
 		m_ext.ctrl++;
 	}
+#endif
 
 	// Setup channel using the provided channelname
 	if(channel != NULL)
@@ -195,6 +217,7 @@ void oss_set_channel(const gchar * chann
 	g_free(m_channel);
 	m_channel = g_strdup(channel);
 
+#if 0
 	// Find channel and then return
 	m_ext.dev=0;
 	m_ext.ctrl = 0;
@@ -207,6 +230,7 @@ void oss_set_channel(const gchar * chann
 		}
 		m_ext.ctrl++;
 	}
+#endif
 }
 
 void oss_set_mute(gboolean mute)
@@ -219,6 +243,7 @@ void oss_set_mute(gboolean mute)
 
 	// Check for mute in this group
 	m_ext.ctrl = 0;
+#if 0
 	while(ioctl(m_mixer_fd, SNDCTL_MIX_EXTINFO, &m_ext) >= 0)
 	{
 		if(m_ext.parent == parent && m_ext.type == MIXT_MUTE)
@@ -239,6 +264,7 @@ void oss_set_mute(gboolean mute)
 	m_ext.ctrl = control;
 	ioctl(m_mixer_fd, SNDCTL_MIX_EXTINFO, &m_ext);
 
+#endif
 	// If no mute control was found, revert to setting the volume to zero
 	if(!mute_found && mute)
 	{
@@ -251,6 +277,7 @@ void oss_set_volume(int volume)
 	assert(m_mixer_fd != -1);
 	volume = (volume < 0 ? 0 : (volume > 100 ? 100 : volume));
 
+#if 0
 	oss_mixer_value vr;
 	vr.dev = m_ext.dev;
 	vr.ctrl = m_ext.ctrl;
@@ -286,9 +313,24 @@ void oss_set_volume(int volume)
 		default:
 			return;
 	}
-
-	ioctl(m_mixer_fd, SNDCTL_MIX_WRITE, &vr);
-
+#endif
+	volume = (volume << 8) | volume;
+	if(ioctl(m_mixer_fd, SOUND_MIXER_WRITE_VOLUME, &volume) == -1) {
+		perror("Mixer write failed");
+		exit(EXIT_FAILURE);
+	}
+#if 0
 	if(volume == 100)
 		m_actual_maxvalue = get_raw_value();
+#endif
+}
+
+const gchar * oss_get_device()
+{
+	return NULL;
+}
+
+const GList * oss_get_device_names()
+{
+	return NULL;
 }
