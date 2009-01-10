/* Swfdec
 * Copyright © 2006 Benjamin Otte <otte@gnome.org>
 * Copyright © 2007 Eric Anholt <eric@anholt.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <sys/ioctl.h>
#include <sys/soundcard.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "swfdec_playback.h"

/** @file Implements swfdec audio playback by opening /dev/dsp per stream
 * and playing out through that.
 *
 * Allowing multiple access to /dev/dsp is not required by the OSS API spec,
 * but FreeBSD's sound system lets you, which is what this file was written
 * for.
 */

/*** DEFINITIONS ***/

struct _SwfdecPlayback {
  SwfdecPlayer *	player;
  GList *		streams;	/* all Stream objects */
  GMainContext *	context;	/* context we work in */
};

typedef struct {
  SwfdecPlayback *     	sound;		/* reference to sound object */
  SwfdecAudio *		audio;		/* the audio we play back */
  int			dsp_fd;
  int			fragsize;	/* Audio fragment size */
  GSource *		source;		/* source for writing data */
  guint			offset;		/* offset into sound */
} Stream;

/* Size of one of our audio samples, in bytes */
#define SAMPLESIZE	2
#define CHANNELS	2

/*** STREAMS ***/

static gboolean
handle_stream (GIOChannel *source, GIOCondition cond, gpointer data)
{
  Stream *stream = data;
  char *frag = malloc(stream->fragsize);

  if (frag == NULL) {
    g_printerr ("Failed to allocate fragment of size %d\n",
		stream->fragsize);
    return FALSE;
  }

  while (TRUE) {
    int ret;
    audio_buf_info spaceinfo;

    ret = ioctl(stream->dsp_fd, SNDCTL_DSP_GETOSPACE, &spaceinfo);
    if (ret == -1) {
      g_printerr ("Failed to get output buffer availability\n");
      free(frag);
      return FALSE;
    }

    if (spaceinfo.fragments == 0)
      break;

    memset (frag, 0, stream->fragsize);
    swfdec_audio_render (stream->audio, (gint16 *)frag, stream->offset,
			 stream->fragsize / SAMPLESIZE / CHANNELS);

    ret = write (stream->dsp_fd, frag, stream->fragsize);
    if (ret != stream->fragsize) {
      g_printerr ("Failed to write fragment\n");
      free(frag);
      return FALSE;
    }

    stream->offset += stream->fragsize / SAMPLESIZE / CHANNELS;
  }

  free(frag);

  return TRUE;
}

static void
swfdec_playback_stream_open (SwfdecPlayback *sound, SwfdecAudio *audio)
{
  GIOChannel *channel;
  Stream *stream;
  guint rate;
  int dsp_fd, ret, format, channels, fragsize;

  dsp_fd = open("/dev/dsp", O_WRONLY);
  if (dsp_fd == -1) {
    g_printerr ("Failed to open /dev/dsp\n");
    return;
  }

  format = AFMT_S16_LE;
  ret = ioctl(dsp_fd, SNDCTL_DSP_SETFMT, &format);
  if (ret == -1) {
    g_printerr ("Failed to set sound format\n");
    close(dsp_fd);
    return;
  }

  channels = 2;
  ret = ioctl(dsp_fd, SNDCTL_DSP_CHANNELS, &channels);
  if (ret == -1) {
    g_printerr ("Failed to set stereo\n");
    close(dsp_fd);
    return;
  }

  rate = 44100;
  ret = ioctl(dsp_fd, SNDCTL_DSP_SPEED, &rate);
  if (ret == -1) {
    g_printerr ("Failed to set rate\n");
    close(dsp_fd);
    return;
  }

  ret = ioctl(dsp_fd, SNDCTL_DSP_GETBLKSIZE, &fragsize);
  if (ret == -1) {
    g_printerr ("Failed to get fragment size\n");
    close(dsp_fd);
    return;
  }

  stream = g_new0 (Stream, 1);
  stream->sound = sound;
  stream->audio = g_object_ref (audio);
  stream->dsp_fd = dsp_fd;
  stream->fragsize = fragsize;
  sound->streams = g_list_prepend (sound->streams, stream);

  channel = g_io_channel_unix_new (stream->dsp_fd);
  stream->source = g_io_create_watch (channel, G_IO_OUT);
  g_source_set_priority (stream->source, G_PRIORITY_HIGH);
  g_source_set_callback (stream->source, (GSourceFunc) handle_stream, stream,
			 NULL);
  g_io_channel_unref (channel);
  g_source_attach (stream->source, stream->sound->context);

  return;
}

static void
swfdec_playback_stream_close (Stream *stream)
{
  close (stream->dsp_fd);
  g_source_destroy (stream->source);
  g_source_unref (stream->source);
  stream->sound->streams = g_list_remove (stream->sound->streams, stream);
  g_object_unref (stream->audio);
  g_free (stream);
}

/*** SOUND ***/

static void
advance_before (SwfdecPlayer *player, guint msecs, guint audio_samples, gpointer data)
{
  SwfdecPlayback *sound = data;
  GList *walk;

  for (walk = sound->streams; walk; walk = walk->next) {
    Stream *stream = walk->data;
    if (audio_samples >= stream->offset) {
      stream->offset = 0;
    } else {
      stream->offset -= audio_samples;
    }
  }
}

static void
audio_added (SwfdecPlayer *player, SwfdecAudio *audio, SwfdecPlayback *sound)
{
  swfdec_playback_stream_open (sound, audio);
}

static void
audio_removed (SwfdecPlayer *player, SwfdecAudio *audio, SwfdecPlayback *sound)
{
  GList *walk;

  for (walk = sound->streams; walk; walk = walk->next) {
    Stream *stream = walk->data;
    if (stream->audio == audio) {
      swfdec_playback_stream_close (stream);
      return;
    }
  }
  g_assert_not_reached ();
}

SwfdecPlayback *
swfdec_playback_open (SwfdecPlayer *player, GMainContext *context)
{
  SwfdecPlayback *sound;
  const GList *walk;

  g_return_val_if_fail (SWFDEC_IS_PLAYER (player), NULL);
  g_return_val_if_fail (context != NULL, NULL);

  sound = g_new0 (SwfdecPlayback, 1);
  sound->player = player;
  g_signal_connect (player, "advance", G_CALLBACK (advance_before), sound);
  g_signal_connect (player, "audio-added", G_CALLBACK (audio_added), sound);
  g_signal_connect (player, "audio-removed", G_CALLBACK (audio_removed), sound);
  for (walk = swfdec_player_get_audio (player); walk; walk = walk->next) {
    swfdec_playback_stream_open (sound, walk->data);
  }
  g_main_context_ref (context);
  sound->context = context;
  return sound;
}

void
swfdec_playback_close (SwfdecPlayback *sound)
{
#define REMOVE_HANDLER_FULL(obj,func,data,count) G_STMT_START {\
  if (g_signal_handlers_disconnect_by_func ((obj), \
	G_CALLBACK (func), (data)) != (count)) { \
    g_assert_not_reached (); \
  } \
} G_STMT_END
#define REMOVE_HANDLER(obj,func,data) REMOVE_HANDLER_FULL (obj, func, data, 1)

  while (sound->streams)
    swfdec_playback_stream_close (sound->streams->data);
  REMOVE_HANDLER (sound->player, advance_before, sound);
  REMOVE_HANDLER (sound->player, audio_added, sound);
  REMOVE_HANDLER (sound->player, audio_removed, sound);
  g_main_context_unref (sound->context);
  g_free (sound);
}


