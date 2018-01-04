--- src/oss3_backend.c.orig	2017-12-18 17:23:45.225185000 +0100
+++ src/oss3_backend.c	2017-12-18 17:23:57.906175000 +0100
@@ -0,0 +1,185 @@
+//
+// Copyright (c) 2011 Maato <maato@softwarebakery.com>
+// Copyright (c) 2017 Dmitri Goutnik <dg@syrec.org>
+// All rights reserved.
+//
+// Redistribution and use in source and binary forms, with or without
+// modification, are permitted provided that the following conditions
+// are met:
+// 1. Redistributions of source code must retain the above copyright
+//    notice, this list of conditions and the following disclaimer
+//    in this position and unchanged.
+// 2. Redistributions in binary form must reproduce the above copyright
+//    notice, this list of conditions and the following disclaimer in the
+//    documentation and/or other materials provided with the distribution.
+//
+// THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR
+// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
+// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
+// IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,
+// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
+// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
+// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
+// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
+// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
+// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
+//
+
+#include OSS_HEADER
+#include <sys/soundcard.h>
+#include <fcntl.h>
+#include <assert.h>
+#include <stdlib.h>
+#include <stdio.h>
+#include <glib.h>
+
+#include "oss_backend.h"
+
+static const char *channel_labels[SOUND_MIXER_NRDEVICES] = SOUND_DEVICE_NAMES;
+static int m_mixer_fd = -1;
+static GList *m_channel_names = NULL;
+static char *m_channel;
+static int m_channel_dev = 0;
+static char *m_device = NULL;
+static GList *m_device_names = NULL;
+
+void
+oss_setup(const gchar *card, const gchar *channel, void (*volume_changed) (int, gboolean))
+{
+	// Make sure (for now) that the setup function only gets called once
+	static int oss_setup_called = 0;
+	assert(oss_setup_called == 0);
+	oss_setup_called++;
+
+	g_list_free_full(m_channel_names, g_free);
+	m_channel_names = NULL;
+	g_list_free_full(m_device_names, g_free);
+	m_device_names = NULL;
+
+	g_free(m_device);
+	m_device = g_strdup(card);
+	m_device_names = g_list_append(m_device_names, g_strdup(m_device));
+
+	// Get ahold of the mixer device
+	char *devmixer;
+	if ((devmixer = getenv("OSS_MIXERDEV")) == NULL)
+		devmixer = "/dev/mixer";
+	if ((m_mixer_fd = open(devmixer, O_RDWR)) == -1) {
+		perror("Cannot open mixer");
+		exit(EXIT_FAILURE);
+	}
+
+	// Query mixer devices
+	int devmask = 0;
+	if (ioctl(m_mixer_fd, SOUND_MIXER_READ_DEVMASK, &devmask) == -1) {
+		perror("Cannot query devices");
+		exit(EXIT_FAILURE);
+	}
+
+	// Pupulate channel list
+	for (int i = 0; i < SOUND_MIXER_NRDEVICES; i++) {
+		if (!((1 << i) & devmask))
+			continue;
+		m_channel_names = g_list_append(m_channel_names, g_strdup(channel_labels[i]));
+	}
+
+	// Setup channel using the provided channel name
+	if (channel != NULL)
+		oss_set_channel(channel);
+	else if (channel == NULL && m_channel_names != NULL)
+		oss_set_channel((const gchar *)m_channel_names->data);
+}
+
+const gchar *
+oss_get_channel()
+{
+	return m_channel;
+}
+
+void
+oss_set_channel(const gchar *channel)
+{
+	assert(channel != NULL);
+	assert(m_mixer_fd != -1);
+
+	if (g_strcmp0(channel, m_channel) == 0)
+		return;
+
+	// Find channel dev index
+	int i;
+	for (i = 0; i < SOUND_MIXER_NRDEVICES; i++)
+		if (g_strcmp0(channel, channel_labels[i]) == 0)
+			break;
+
+	if (i < SOUND_MIXER_NRDEVICES) {
+		g_free(m_channel);
+		m_channel = g_strdup(channel);
+		m_channel_dev = i;
+	}
+}
+
+const gchar *
+oss_get_device()
+{
+	return m_device;
+}
+
+const GList *
+oss_get_channel_names()
+{
+	return m_channel_names;
+}
+
+const GList *
+oss_get_device_names()
+{
+	return m_device_names;
+}
+
+int
+oss_get_volume()
+{
+	assert(m_mixer_fd != -1);
+
+	int current_volume;
+	if (ioctl(m_mixer_fd, MIXER_READ(m_channel_dev), &current_volume) == -1) {
+		perror("Cannot read volume");
+		exit(EXIT_FAILURE);
+	}
+
+	// Only the left channel is returned
+	return current_volume & 0x7f;
+}
+
+void
+oss_set_volume(int volume)
+{
+	assert(m_mixer_fd != -1);
+	volume = (volume < 0 ? 0 : (volume > 100 ? 100 : volume));
+
+	volume = (volume << 8) | volume;
+	if (ioctl(m_mixer_fd, MIXER_WRITE(m_channel_dev), &volume) == -1) {
+		perror("Cannot write volume");
+		exit(EXIT_FAILURE);
+	}
+}
+
+gboolean
+oss_get_mute()
+{
+	assert(m_mixer_fd != -1);
+
+	// TODO: see if there's a way to return real mute state
+	return oss_get_volume() == 0;
+}
+
+void
+oss_set_mute(gboolean mute)
+{
+	assert(m_mixer_fd != -1);
+
+	// TODO: see if there's a way to toggle real mute
+	if (mute) {
+		oss_set_volume(0);
+	}
+}
