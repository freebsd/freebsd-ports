/*
 * Copyright (C) 2008 Jacob Meuser <jakemsr@sdf.lonestar.org>
 * Copyright (C) 2012 Alexandre Ratchov <alex@caoua.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include "gstsndio.h"

GST_DEBUG_CATEGORY (gst_sndio_debug);
#define GST_CAT_DEFAULT gst_sndio_debug

GType gst_sndiosink_get_type (void);

gboolean
plugin_init_alsa (GstPlugin * plugin)
{
  GST_DEBUG_CATEGORY_INIT (gst_sndio_debug, "sndio", 0, "sndio plugins");

  /* prefer sndiosink over pulsesink (GST_RANK_PRIMARY + 10) */
  if (!gst_element_register (plugin, "bsdaudiosink", GST_RANK_PRIMARY + 20,
          gst_sndiosink_get_type()))
    return FALSE;
  return TRUE;
}

GST_PLUGIN_DEFINE (GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    sndio,
    "sndio plugin library",
    plugin_init_alsa, VERSION, GST_LICENSE, GST_PACKAGE_NAME, GST_PACKAGE_ORIGIN)

/*
 * common code to src and sink
 */

void
gst_sndio_init (struct gstsndio *sio, GObject *obj)
{
  sio->obj = obj;
  sio->hdl = NULL;
  sio->device = g_strdup (SIO_DEVANY);
}

void
gst_sndio_finalize (struct gstsndio *sio)
{
  gst_caps_replace (&sio->cur_caps, NULL);
  g_free (sio->device);
}

GstCaps *
gst_sndio_getcaps (struct gstsndio *sio, GstCaps * filter)
{
  if (sio->cur_caps == NULL) {
    /* XXX */
    GST_LOG_OBJECT (sio->obj, "getcaps called, returning template caps");
    return NULL;
  }

  GST_LOG_OBJECT (sio->obj, "returning %" GST_PTR_FORMAT, sio->cur_caps);

  if (filter) {
    return gst_caps_intersect_full (filter,
      sio->cur_caps, GST_CAPS_INTERSECT_FIRST);
  } else {
    return gst_caps_ref (sio->cur_caps);
  }
}

static void
gst_sndio_onvol (void *arg, unsigned int vol)
{
  struct gstsndio *sio = arg;
  sio->volume = vol;
  g_object_notify (G_OBJECT (sio->obj), "mute");
  g_object_notify (G_OBJECT (sio->obj), "volume");
}

gboolean
gst_sndio_open (struct gstsndio *sio, gint mode)
{
  GValue list = G_VALUE_INIT, item = G_VALUE_INIT;
  GstStructure *s;
  GstCaps *caps;
  struct sio_enc *enc;
  struct sio_cap cap;
  char fmt[16];
  int i, chan;

  GST_DEBUG_OBJECT (sio->obj, "open");

  sio->hdl = sio_open (sio->device, mode, 0);
  if (sio->hdl == NULL) {
    GST_ELEMENT_ERROR (sio->obj, RESOURCE, OPEN_READ_WRITE,
	("Couldn't open sndio device"), (NULL));
    return FALSE;
  }
  sio->mode = mode;

  if (!sio_getcap(sio->hdl, &cap)) {
    GST_ELEMENT_ERROR (sio, RESOURCE, OPEN_WRITE,
	("Couldn't get device capabilities"), (NULL));
    sio_close(sio->hdl);
    sio->hdl = NULL;
    return FALSE;
  }
  if (cap.nconf == 0) {
    GST_ELEMENT_ERROR (sio, RESOURCE, OPEN_WRITE,
	("Device has empty capabilities"), (NULL));
    sio_close(sio->hdl);
    sio->hdl = NULL;
    return FALSE;
  }
  sio_onvol (sio->hdl, gst_sndio_onvol, sio);

  caps = gst_caps_new_empty ();
  s = gst_structure_new ("audio/x-raw", (char *)NULL, (void *)NULL);

  /*
   * scan supported rates
   */
  g_value_init (&list, GST_TYPE_LIST);
  g_value_init (&item, G_TYPE_INT);
  for (i = 0; i < SIO_NRATE; i++) {
      if ((cap.confs[0].rate & (1 << i)) == 0)
	  continue;
      g_value_set_int(&item, cap.rate[i]);
      gst_value_list_append_value (&list, &item);
  }
  gst_structure_set_value (s, "rate", &list);
  g_value_unset (&item);
  g_value_unset (&list);

  /*
   * scan supported channels
   */
  g_value_init (&list, GST_TYPE_LIST);
  g_value_init (&item, G_TYPE_INT);
  chan = (mode == SIO_PLAY) ? cap.confs[0].pchan : cap.confs[0].rchan;
  for (i = 0; i < SIO_NCHAN; i++) {
      if ((chan & (1 << i)) == 0)
	  continue;
      g_value_set_int(&item, (mode == SIO_PLAY) ? cap.pchan[i] : cap.rchan[i]);
      gst_value_list_append_value (&list, &item);
  }
  gst_structure_set_value (s, "channels", &list);
  g_value_unset (&item);
  g_value_unset (&list);

  /*
   * scan supported encodings
   */
  g_value_init (&list, GST_TYPE_LIST);
  g_value_init (&item, G_TYPE_STRING);
  for (i = 0; i < SIO_NENC; i++) {
      if ((cap.confs[0].enc & (1 << i)) == 0)
	  continue;
      enc = cap.enc + i;
      if (enc->bits % 8 != 0)
	  continue;
      if (enc->bits < enc->bps * 8 && enc->msb)
	  continue;
      if (enc->bits == enc->bps * 8) {
	  snprintf(fmt, sizeof(fmt), "%s%u%s",
		   enc->sig ? "S" : "U",
		   enc->bits,
		   enc->bps > 1 ? (enc->le ? "LE" : "BE") : "");
      } else {
	  snprintf(fmt, sizeof(fmt), "%s%u_%u%s",
		   enc->sig ? "S" : "U",
		   enc->bits,
		   enc->bps * 8,
		   enc->bps > 1 ? (enc->le ? "LE" : "BE") : "");
      }
      g_value_set_string(&item, fmt);
      gst_value_list_append_value (&list, &item);
  }
  gst_structure_set_value (s, "format", &list);
  g_value_unset (&item);
  g_value_unset (&list);

  /*
   * add the only supported layout: interleaved
   */
  g_value_init (&item, G_TYPE_STRING);
  g_value_set_string(&item, "interleaved");
  gst_structure_set_value (s, "layout", &item);
  g_value_unset (&item);

  gst_caps_append_structure (caps, s);
  sio->cur_caps = caps;
  GST_DEBUG ("caps are %s", gst_caps_to_string(caps));
  return TRUE;
}

gboolean
gst_sndio_close (struct gstsndio *sio)
{
  GST_DEBUG_OBJECT (sio->obj, "close");

  gst_caps_replace (&sio->cur_caps, NULL);
  sio_close (sio->hdl);
  sio->hdl = NULL;
  return TRUE;
}

static void
gst_sndio_cb (void *addr, int delta)
{
  struct gstsndio *sio = addr;

  delta *= sio->bpf;
  if (sio->mode == SIO_PLAY)
      sio->delay -= delta;
  else
      sio->delay += delta;
}

gboolean
gst_sndio_prepare (struct gstsndio *sio, GstAudioRingBufferSpec *spec)
{
  struct sio_par par, retpar;
  unsigned nchannels;

  GST_DEBUG_OBJECT (sio, "prepare");

  if (spec->type != GST_AUDIO_RING_BUFFER_FORMAT_TYPE_RAW) {
      GST_ELEMENT_ERROR (sio, RESOURCE, OPEN_READ_WRITE,
	("Only raw buffer format supported by sndio"), (NULL));
      return FALSE;
  }
  if (!GST_AUDIO_INFO_IS_INTEGER(&spec->info)) {
      GST_ELEMENT_ERROR (sio, RESOURCE, OPEN_READ_WRITE,
	("Only integer format supported"), (NULL));
      return FALSE;
  }
  if (GST_AUDIO_INFO_DEPTH(&spec->info) % 8) {
      GST_ELEMENT_ERROR (sio, RESOURCE, OPEN_READ_WRITE,
	("Only depths multiple of 8 are supported"), (NULL));
      return FALSE;
  }

  sio_initpar (&par);
  switch (GST_AUDIO_INFO_FORMAT (&spec->info)) {
  case GST_AUDIO_FORMAT_S8:
  case GST_AUDIO_FORMAT_U8:
  case GST_AUDIO_FORMAT_S16LE:
  case GST_AUDIO_FORMAT_S16BE:
  case GST_AUDIO_FORMAT_U16LE:
  case GST_AUDIO_FORMAT_U16BE:
  case GST_AUDIO_FORMAT_S32LE:
  case GST_AUDIO_FORMAT_S32BE:
  case GST_AUDIO_FORMAT_U32LE:
  case GST_AUDIO_FORMAT_U32BE:
  case GST_AUDIO_FORMAT_S24_32LE:
  case GST_AUDIO_FORMAT_S24_32BE:
  case GST_AUDIO_FORMAT_U24_32LE:
  case GST_AUDIO_FORMAT_U24_32BE:
  case GST_AUDIO_FORMAT_S24LE:
  case GST_AUDIO_FORMAT_S24BE:
  case GST_AUDIO_FORMAT_U24LE:
  case GST_AUDIO_FORMAT_U24BE:
      break;
  default:
      GST_ELEMENT_ERROR (sio, RESOURCE, OPEN_READ_WRITE,
	  ("Unsupported audio format"),
	  ("format = %d", GST_AUDIO_INFO_FORMAT (&spec->info)));
      return FALSE;
  }
  par.sig = GST_AUDIO_INFO_IS_SIGNED(&spec->info);
  par.bits = GST_AUDIO_INFO_WIDTH(&spec->info);
  par.bps = GST_AUDIO_INFO_DEPTH(&spec->info) / 8;
  if (par.bps > 1)
      par.le = GST_AUDIO_INFO_IS_LITTLE_ENDIAN(&spec->info);
  if (par.bits < par.bps * 8)
      par.msb = 0;
  par.rate = GST_AUDIO_INFO_RATE(&spec->info);
  if (sio->mode == SIO_PLAY)
      par.pchan = GST_AUDIO_INFO_CHANNELS(&spec->info);
  else
      par.rchan = GST_AUDIO_INFO_CHANNELS(&spec->info);
  par.round = par.rate / 1000000. * spec->latency_time;
  par.appbufsz = par.rate / 1000000. * spec->buffer_time;

  if (!sio_setpar (sio->hdl, &par)) {
      GST_ELEMENT_ERROR (sio, RESOURCE, OPEN_WRITE,
	("Unsupported audio encoding"), (NULL));
      return FALSE;
  }
  if (!sio_getpar (sio->hdl, &retpar)) {
      GST_ELEMENT_ERROR (sio, RESOURCE, OPEN_WRITE,
	("Couldn't get audio device parameters"), (NULL));
      return FALSE;
  }
#if 0
  GST_DEBUG ("format = %s, "
         "requested: sig = %d, bits = %d, bps = %d, le = %d, msb = %d, "
	 "rate = %d, pchan = %d, round = %d, appbufsz = %d; "
	 "returned: sig = %d, bits = %d, bps = %d, le = %d, msb = %d, "
	 "rate = %d, pchan = %d, round = %d, appbufsz = %d, bufsz = %d",
	 GST_AUDIO_INFO_NAME(&spec->info),
	 par.sig, par.bits, par.bps, par.le, par.msb,
	 par.rate, par.pchan, par.round, par.appbufsz,
	 retpar.sig, retpar.bits, retpar.bps, retpar.le, retpar.msb,
	 retpar.rate, retpar.pchan, retpar.round, retpar.appbufsz, retpar.bufsz);
#endif
  if (par.bits != retpar.bits ||
      par.bps != retpar.bps ||
      par.rate != retpar.rate ||
      (sio->mode == SIO_PLAY && par.pchan != retpar.pchan) ||
      (sio->mode == SIO_REC && par.rchan != retpar.rchan) ||
      (par.bps > 1 && par.le != retpar.le) ||
      (par.bits < par.bps * 8 && par.msb != retpar.msb)) {
      GST_ELEMENT_ERROR (sio, RESOURCE, OPEN_WRITE,
	("Audio device refused requested parameters"), (NULL));
      return FALSE;
  }

  nchannels = (sio->mode == SIO_PLAY) ? retpar.pchan : retpar.rchan;
  spec->segsize = retpar.round * retpar.bps * nchannels;
  spec->segtotal = retpar.bufsz / retpar.round;
  sio->bpf = retpar.bps * nchannels;
  sio->delay = 0;
  sio_onmove (sio->hdl, gst_sndio_cb, sio);

  if (!sio_start (sio->hdl)) {
    GST_ELEMENT_ERROR (sio->obj, RESOURCE, OPEN_READ_WRITE,
      ("Could not start sndio"), (NULL));
    return FALSE;
  }
  return TRUE;
}

gboolean
gst_sndio_unprepare (struct gstsndio *sio)
{
  if (sio->hdl)
    sio_stop (sio->hdl);
  return TRUE;
}

void
gst_sndio_set_property (struct gstsndio *sio, guint prop_id,
    const GValue * value, GParamSpec * pspec)
{
  switch (prop_id) {
    case PROP_DEVICE:
      g_free (sio->device);
      sio->device = g_value_dup_string (value);
      break;
    case PROP_VOLUME:
      sio_setvol (sio->hdl, g_value_get_double (value) * SIO_MAXVOL);
      break;
    case PROP_MUTE:
      if (g_value_get_boolean (value))
        sio_setvol (sio->hdl, 0);
      break;
    default:
      break;
  }
}

void
gst_sndio_get_property (struct gstsndio *sio, guint prop_id,
    GValue * value,  GParamSpec * pspec)
{
  switch (prop_id) {
    case PROP_DEVICE:
      g_value_set_string (value, sio->device);
      break;
    case PROP_VOLUME:
      g_value_set_double (value, (gdouble)sio->volume / SIO_MAXVOL);
      break;
    case PROP_MUTE:
      g_value_set_boolean (value, (sio->volume == 0));
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (sio->obj, prop_id, pspec);
  }
}
