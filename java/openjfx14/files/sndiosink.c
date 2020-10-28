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

/**
 * SECTION:element-sndiosink
 * @see_also: #GstAutoAudioSink
 *
 * <refsect2>
 * <para>
 * This element outputs sound to a sound card using sndio.
 * </para>
 * <para>
 * Simple example pipeline that plays an Ogg/Vorbis file via sndio:
 * <programlisting>
 * gst-launch -v filesrc location=foo.ogg ! decodebin ! audioconvert ! audioresample ! sndiosink
 * </programlisting>
 * </para>
 * </refsect2>
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "sndiosink.h"

GST_DEBUG_CATEGORY_EXTERN (gst_sndio_debug);
#define GST_CAT_DEFAULT gst_sndio_debug

#define gst_sndiosink_parent_class parent_class

static GstStaticPadTemplate sndiosink_factory =
    GST_STATIC_PAD_TEMPLATE ("sink",
	GST_PAD_SINK,
	GST_PAD_ALWAYS,
	GST_STATIC_CAPS (GST_SNDIO_CAPS_STRING)
    );

G_DEFINE_TYPE_WITH_CODE (GstSndioSink, gst_sndiosink, GST_TYPE_AUDIO_SINK,
	G_IMPLEMENT_INTERFACE (GST_TYPE_STREAM_VOLUME, NULL));

static void gst_sndiosink_finalize (GObject * object);
static GstCaps *gst_sndiosink_getcaps (GstBaseSink * bsink,
    GstCaps * filter);
static gboolean gst_sndiosink_open (GstAudioSink * asink);
static gboolean gst_sndiosink_close (GstAudioSink * asink);
static gboolean gst_sndiosink_prepare (GstAudioSink * asink,
    GstAudioRingBufferSpec * spec);
static gboolean gst_sndiosink_unprepare (GstAudioSink * asink);
static gint gst_sndiosink_write (GstAudioSink * asink, gpointer data,
    guint length);
static guint gst_sndiosink_delay (GstAudioSink * asink);
static void gst_sndiosink_reset (GstAudioSink * asink);
static void gst_sndiosink_set_property (GObject * object, guint prop_id,
    const GValue * value, GParamSpec * pspec);
static void gst_sndiosink_get_property (GObject * object, guint prop_id,
    GValue * value, GParamSpec * pspec);

static void
gst_sndiosink_init (GstSndioSink * sink)
{
  gst_sndio_init (&sink->sndio, G_OBJECT(sink));
}

static void
gst_sndiosink_finalize (GObject * object)
{
  GstSndioSink *sink = GST_SNDIOSINK (object);

  gst_sndio_finalize (&sink->sndio);
  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static GstCaps *
gst_sndiosink_getcaps (GstBaseSink * bsink, GstCaps * filter)
{
  GstSndioSink *sink = GST_SNDIOSINK (bsink);

  return gst_sndio_getcaps (&sink->sndio, filter);
}

static gboolean
gst_sndiosink_open (GstAudioSink * asink)
{
  GstSndioSink *sink = GST_SNDIOSINK (asink);

  return gst_sndio_open (&sink->sndio, SIO_PLAY);
}

static gboolean
gst_sndiosink_close (GstAudioSink * asink)
{
  GstSndioSink *sink = GST_SNDIOSINK (asink);

  return gst_sndio_close (&sink->sndio);
}

static gboolean
gst_sndiosink_prepare (GstAudioSink * asink, GstAudioRingBufferSpec * spec)
{
  GstSndioSink *sink = GST_SNDIOSINK (asink);

  return gst_sndio_prepare (&sink->sndio, spec);
}

static gboolean
gst_sndiosink_unprepare (GstAudioSink * asink)
{
  GstSndioSink *sink = GST_SNDIOSINK (asink);

  return gst_sndio_unprepare (&sink->sndio);
}

static gint
gst_sndiosink_write (GstAudioSink * asink, gpointer data, guint length)
{
  GstSndioSink *sink = GST_SNDIOSINK (asink);
  guint done;

  if (length == 0)
    return 0;
  done = sio_write (sink->sndio.hdl, data, length);
  if (done == 0) {
      GST_ELEMENT_ERROR (sink, RESOURCE, WRITE,
	("Failed to write data to sndio"), (NULL));
      return 0;
  }
  sink->sndio.delay += done;
  return done;
}

static guint
gst_sndiosink_delay (GstAudioSink * asink)
{
  GstSndioSink *sink = GST_SNDIOSINK (asink);

  return GST_SNDIO_DELAY(&sink->sndio);
}

static void
gst_sndiosink_reset (GstAudioSink * asink)
{
}

static void
gst_sndiosink_set_property (GObject * object, guint prop_id,
    const GValue * value, GParamSpec * pspec)
{
  GstSndioSink *sink = GST_SNDIOSINK (object);

  gst_sndio_set_property (&sink->sndio, prop_id, value, pspec);
}

static void
gst_sndiosink_get_property (GObject * object, guint prop_id, GValue * value,
    GParamSpec * pspec)
{
  GstSndioSink *sink = GST_SNDIOSINK (object);

  gst_sndio_get_property (&sink->sndio, prop_id, value, pspec);
}

static void
gst_sndiosink_class_init (GstSndioSinkClass * klass)
{
  GObjectClass *gobject_class;
  GstElementClass *gstelement_class;
  GstBaseSinkClass *gstbasesink_class;
  GstAudioBaseSinkClass *gstbaseaudiosink_class;
  GstAudioSinkClass *gstaudiosink_class;

  gobject_class = (GObjectClass *) klass;
  gstelement_class = (GstElementClass *) klass;
  gstbasesink_class = (GstBaseSinkClass *) klass;
  gstbaseaudiosink_class = (GstAudioBaseSinkClass *) klass;
  gstaudiosink_class = (GstAudioSinkClass *) klass;

  parent_class = g_type_class_peek_parent (klass);

  gobject_class->finalize = gst_sndiosink_finalize;
  gobject_class->get_property = gst_sndiosink_get_property;
  gobject_class->set_property = gst_sndiosink_set_property;

  gst_element_class_set_static_metadata (gstelement_class,
      "Audio sink (sndio)", "Sink/Audio",
      "Output to a sound card via sndio",
      "Jacob Meuser <jakemsr@sdf.lonestar.org>");

  gst_element_class_add_pad_template (gstelement_class,
      gst_static_pad_template_get (&sndiosink_factory));

  gstbasesink_class->get_caps = GST_DEBUG_FUNCPTR (gst_sndiosink_getcaps);
  gstaudiosink_class->open = GST_DEBUG_FUNCPTR (gst_sndiosink_open);
  gstaudiosink_class->prepare = GST_DEBUG_FUNCPTR (gst_sndiosink_prepare);
  gstaudiosink_class->unprepare = GST_DEBUG_FUNCPTR (gst_sndiosink_unprepare);
  gstaudiosink_class->close = GST_DEBUG_FUNCPTR (gst_sndiosink_close);
  gstaudiosink_class->write = GST_DEBUG_FUNCPTR (gst_sndiosink_write);
  gstaudiosink_class->delay = GST_DEBUG_FUNCPTR (gst_sndiosink_delay);
  gstaudiosink_class->reset = GST_DEBUG_FUNCPTR (gst_sndiosink_reset);

  g_object_class_install_property (gobject_class, PROP_DEVICE,
      g_param_spec_string ("device", "Device",
          "sndio device as defined in sndio(7)",
          SIO_DEVANY, G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));
  g_object_class_install_property (gobject_class, PROP_VOLUME,
      g_param_spec_double ("volume", "Volume",
	  "Linear volume of this stream, 1.0=100%", 0.0, 1.0,
	  1.0, G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));
  g_object_class_install_property (gobject_class, PROP_MUTE,
      g_param_spec_boolean ("mute", "Mute",
	  "Mute state of this stream", FALSE,
	  G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));
}
