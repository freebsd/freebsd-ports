#-*- tab-width: 4; -*-
# ex:ts=4
#
# bsd.gstreamer.mk - Support for gstreamer-plugins-based ports.
#
# Created by: Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/Mk/bsd.gstreamer.mk,v 1.56 2013/01/15 21:43:45 kwm Exp $

.if !defined(_POSTMKINCLUDED) && !defined(Gstreamer_Pre_Include)

Gstreamer_Include_MAINTAINER=	multimedia@FreeBSD.org
Gstreamer_Pre_Include=		bsd.gstreamer.mk

.endif

# Ports can use the following:
#
# For Gstreamer 0.10:
#   USE_GSTREAMER=	lame faac ffmpeg
#
# For Gstreamer 1.x the same rules apply but instead of 
#   USE_GSTREAMER=, USE_GSTREAMER1= is used.
#
# If you want to use USE_GSTREAMER after <bsd.port.pre.mk>
# you must follow one of the examples listed below
#
#	.include <bsd.port.options.mk>
#	.if defined(WITH_VORBIS)
#	USE_GSTREAMER=	vorbis
#	.endif
#
# or
#       USE_GSTREAMER=	yes
#       .include <bsd.port.options.mk>
#       .if defined(WITH_FAAD)
#       USE_GSTREAMER+=	faad
#       .endif
#	.include <bsd.port.pre.mk>
#
#	USE_GSTREAMER=yes will always add a dependency to
#		gstreamer-plugins
#
#	The use of WANT_GSTREAMER=yes should be discouraged.
#
# "Normal" dependencies and variables
#

GSTREAMER_PORT=		${PORTSDIR}/multimedia/gstreamer-plugins
_GST_LIB_BASE=		${LOCALBASE}/lib/gstreamer-${GST_VERSION}
GST_VERSION=		0.10
GST_MINOR_VERSION=	.0
GST_SHLIB_VERSION=	1

GSTREAMER1_PORT=	${PORTSDIR}/multimedia/gstreamer1-plugins
_GST1_LIB_BASE=		${LOCALBASE}/lib/gstreamer-${GST1_VERSION}
GST1_VERSION=		1.4
GST1_MINOR_VERSION=	.0
GST1_SHLIB_VERSION=	0
GST1_MINIMAL_VERSION=	.0

#
# missing base: alsa ivorbisdec
# missing good: -
# missing ugly: -
# missing bad: openal

# These are the current supported gstreamer-plugins modules:
# Supported plugins by both 0.10 and 1.0.
_GSTREAMER_PLUGINS= \
		a52dec aalib amrnb amrwbdec cairo cdio \
		cdparanoia dts dv faac faad flac flite \
		gdkpixbuf gl gme gnonlin gsm jack jpeg lame libcaca \
		libmms libvisual mad mpeg2dec mpeg2enc neon ogg \
		opencv opus pango pulse resindvd schroedinger \
		shout2 sidplay soundtouch soup speex taglib \
		theora twolame v4l2 vorbis wavpack x264

# plugins only in 0.10
.if defined(USE_GSTREAMER)
_GSTREAMER_PLUGINS+= \
		annodex bz2 cdaudio dvd esound ffmpeg fluendo-mp3 \
		fluendo-mpegdemux gconf gio gnomevfs hal \
		ladspa libpng mm mp3 musepack nas python qt4 \
		sdl sndfile spc vdpau vp8 xvid
.endif

# plugins only in 1.0
.if defined(USE_GSTREAMER1)
_GSTREAMER_PLUGINS+= \
		assrender bs2b chromaprint curl dtls dvdread editing-services \
		gtksink hls kate libav libde265 modplug mpg123 openh264 openjpeg \
		png rsvg rtmp spandsp vpx webp x x265 ximagesrc zbar
# vaapi?
.endif

# other plugins
_USE_GSTREAMER_ALL=	bad core good ugly yes ${_GSTREAMER_PLUGINS}

#--------------------------------------------------------------------------#

core_DEPENDS=	multimedia/gstreamer-plugins-core

yes_DEPENDS=	multimedia/gstreamer-plugins
yes_NAME=	gstreamer-plugins
yes_NAME10=	gstreamer1-plugins
yes_GST_PREFIX=	# empty

#-- audio plugins section -------------------------------------------------#

# Audio Plugins Section
a52dec_DEPENDS=	audio/gstreamer-plugins-a52dec

amrnb_DEPENDS=	audio/gstreamer-plugins-amrnb

amrwbdec_DEPENDS=	audio/gstreamer-plugins-amrwbdec

artsd_DEPENDS=	audio/gstreamer-plugins-artsd

audiofile_DEPENDS=	audio/gstreamer-plugins-audiofile

bs2b_DEPENDS=	audio/gstreamer-plugins-bs2b

cdaudio_DEPENDS=	audio/gstreamer-plugins-cdaudio

cdparanoia_DEPENDS=	audio/gstreamer-plugins-cdparanoia

chromaprint_DEPENDS=	audio/gstreamer-plugins-chromaprint

esound_DEPENDS=	audio/gstreamer-plugins-esound

faac_DEPENDS=	audio/gstreamer-plugins-faac

faad_DEPENDS=	audio/gstreamer-plugins-faad

flac_DEPENDS=	audio/gstreamer-plugins-flac

flite_DEPENDS=	audio/gstreamer-plugins-flite

fluendo-mp3_DEPENDS=	audio/gstreamer-plugins-fluendo-mp3

gme_DEPENDS=	audio/gstreamer-plugins-gme

gsm_DEPENDS=	audio/gstreamer-plugins-gsm

hal_DEPENDS=	sysutils/gstreamer-plugins-hal

jack_DEPENDS=	audio/gstreamer-plugins-jack

ladspa_DEPENDS=	audio/gstreamer-plugins-ladspa

lame_DEPENDS=	audio/gstreamer-plugins-lame

mad_DEPENDS=	audio/gstreamer-plugins-mad

mikmod_DEPENDS=	audio/gstreamer-plugins-mikmod

modplug_DEPENDS=	audio/gstreamer-plugins-modplug

mp3_DEPENDS=	audio/gstreamer-plugins-mp3

mpg123_DEPENDS=	audio/gstreamer-plugins-mpg123

musepack_DEPENDS=	audio/gstreamer-plugins-musepack

nas_DEPENDS=	audio/gstreamer-plugins-nas

neon_DEPENDS=	www/gstreamer-plugins-neon

ogg_DEPENDS=	audio/gstreamer-plugins-ogg

opus_DEPENDS=	audio/gstreamer-plugins-opus

polyp_DEPENDS=	audio/gstreamer-plugins-polyp

pulse_DEPENDS=	audio/gstreamer-plugins-pulse

shout_DEPENDS=	audio/gstreamer-plugins-shout

shout2_DEPENDS=	audio/gstreamer-plugins-shout2

sidplay_DEPENDS=	audio/gstreamer-plugins-sidplay

smoothwave_DEPENDS=	audio/gstreamer-plugins-smoothwave

sndfile_DEPENDS=	audio/gstreamer-plugins-sndfile

soundtouch_DEPENDS=	audio/gstreamer-plugins-soundtouch

spc_DEPENDS=	audio/gstreamer-plugins-spc

speex_DEPENDS=	audio/gstreamer-plugins-speex

taglib_DEPENDS=	audio/gstreamer-plugins-taglib

twolame_DEPENDS=	audio/gstreamer-plugins-twolame

vorbis_DEPENDS=	audio/gstreamer-plugins-vorbis

wavpack_DEPENDS=	audio/gstreamer-plugins-wavpack

#-- comms plugin section --------------------------------------------------#

spandsp_DEPENDS=	comms/gstreamer-plugins-spandsp

#-- devel plugin section --------------------------------------------------#

gconf_DEPENDS=	devel/gstreamer-plugins-gconf

gio_DEPENDS=	devel/gstreamer-plugins-gio

gnomevfs_DEPENDS=	devel/gstreamer-plugins-gnomevfs

sdl_DEPENDS=	devel/gstreamer-plugins-sdl

soup_DEPENDS=	devel/gstreamer-plugins-soup

#-- ftp plugin section ----------------------------------------------------#

curl_DEPENDS=	ftp/gstreamer-plugins-curl

#-- graphics plugin section -----------------------------------------------#

aalib_DEPENDS=	graphics/gstreamer-plugins-aalib

annodex_DEPENDS=	multimedia/gstreamer-plugins-annodex

assrender_DEPENDS=	multimedia/gstreamer-plugins-assrender

cairo_DEPENDS=	graphics/gstreamer-plugins-cairo

gdkpixbuf_DEPENDS=	graphics/gstreamer-plugins-gdkpixbuf

gl_DEPENDS=		graphics/gstreamer-plugins-gl

hermes_DEPENDS=	graphics/gstreamer-plugins-hermes

jpeg_DEPENDS=	graphics/gstreamer-plugins-jpeg

libcaca_DEPENDS=	graphics/gstreamer-plugins-libcaca

libmng_DEPENDS=	graphics/gstreamer-plugins-libmng

libpng_DEPENDS=	graphics/gstreamer-plugins-libpng

libvisual_DEPENDS=	graphics/gstreamer-plugins-libvisual

opencv_DEPENDS=	graphics/gstreamer-plugins-opencv

openjpeg_DEPENDS=	graphics/gstreamer-plugins-openjpeg

png_DEPENDS=	graphics/gstreamer-plugins-png

rsvg_DEPENDS=	graphics/gstreamer-plugins-rsvg

webp_DEPENDS=	graphics/gstreamer-plugins-webp

zbar_DEPENDS=	graphics/gstreamer-plugins-zbar

#-- multimedia plugins section --------------------------------------------#

bad_DEPENDS=	multimedia/gstreamer-plugins-bad

bz2_DEPENDS=	multimedia/gstreamer-plugins-bz2

dvdread_DEPENDS=	multimedia/gstreamer-plugins-dvdread

editing-services_DEPENDS=	multimedia/gstreamer-editing-services
editing-services_GST_PREFIX=	gstreamer1-
editing-services_GST_SUFX=	# empty
editing-services_GST_VERSION=	1.0.0

ffmpeg_DEPENDS=	multimedia/gstreamer-ffmpeg
ffmpeg_GST_PREFIX=	gstreamer-
ffmpeg_GST_SUFX=	# empty
ffmpeg_GST_VERSION=	0.10.0

fluendo-mpegdemux_DEPENDS=	multimedia/gstreamer-plugins-fluendo-mpegdemux

dts_DEPENDS=	multimedia/gstreamer-plugins-dts

dv_DEPENDS=	multimedia/gstreamer-plugins-dv

dvd_DEPENDS=	multimedia/gstreamer-plugins-dvd

good_DEPENDS=	multimedia/gstreamer-plugins-good

gnonlin_DEPENDS=	multimedia/gstreamer-plugins-gnonlin

hls_DEPENDS=	multimedia/gstreamer-plugins-hls

kate_DEPENDS=		multimedia/gstreamer-plugins-kate

libav_DEPENDS=		multimedia/gstreamer-libav
libav_GST_PREFIX=	gstreamer1-
libav_GST_SUFX=		# empty
libav_GST_VERSION=	1.0.0

libde265_DEPENDS=	multimedia/gstreamer-plugins-libde265

libfame_DEPENDS=	multimedia/gstreamer-plugins-libfame

mm_DEPENDS=	multimedia/gstreamermm
mm_GST_PREFIX=	gstreamer
mm_GST_SUFX=	# empty
mm_GST_VERSION=	0.9.4

mpeg2dec_DEPENDS=	multimedia/gstreamer-plugins-mpeg2dec

mpeg2enc_DEPENDS=	multimedia/gstreamer-plugins-mpeg2enc

mplex_DEPENDS=	multimedia/gstreamer-plugins-mplex

openh264_DEPENDS=	multimedia/gstreamer-plugins-openh264

qt4_DEPENDS=	multimedia/gstreamer-qt4
qt4_GST_PREFIX=	gstreamer-

rtmp_DEPENDS=	multimedia/gstreamer1-plugins-rtmp

v4l2_DEPENDS=	multimedia/gstreamer-plugins-v4l2

vaapi_DEPENDS=	multimedia/gstreamer-plugins-vaapi

vp8_DEPENDS=	multimedia/gstreamer-plugins-vp8

vpx_DEPENDS=	multimedia/gstreamer-plugins-vpx

# XXX: This is a quick solution for ports with USE_GSTREAMER=python
#      but without USE_PYTHON.
PYTHON_PKGNAMEPREFIX?=	py*-

python_DEPENDS=	multimedia/py-gstreamer
python_NAME=	gstreamer
python_GST_PREFIX=      ${PYTHON_PKGNAMEPREFIX}
python_GST_SUFX=        # empty
python_GST_VERSION=     0.10.4

resindvd_DEPENDS=	multimedia/gstreamer-plugins-resindvd

schroedinger_DEPENDS=	multimedia/gstreamer-plugins-schroedinger

theora_DEPENDS=	multimedia/gstreamer-plugins-theora

ugly_DEPENDS=	multimedia/gstreamer-plugins-ugly

vdpau_DEPENDS=	multimedia/gstreamer-plugins-vdpau

x264_DEPENDS=	multimedia/gstreamer-plugins-x264

x265_DEPENDS=	multimedia/gstreamer-plugins-x265

xvid_DEPENDS=	multimedia/gstreamer-plugins-xvid


#-- Net Plugins Section ---------------------------------------------------#

libmms_DEPENDS=	net/gstreamer-plugins-libmms

#-- security plugins section ----------------------------------------------#

dtls_DEPENDS=	security/gstreamer-plugins-dtls

#-- sysutils plugins section ----------------------------------------------#

cdio_DEPENDS=	sysutils/gstreamer-plugins-cdio

#-- x11 plugins section ---------------------------------------------------#

x_DEPENDS=	x11/gstreamer-plugins-x

ximagesrc_DEPENDS=	x11/gstreamer-plugins-ximagesrc

#-- x11-toolkits plugins section ------------------------------------------#

gtksink_DEPENDS=	x11-toolkits/gstreamer-plugins-gtksink

pango_DEPENDS=	x11-toolkits/gstreamer-plugins-pango

#--------------------------------------------------------------------------#

.if defined(_POSTMKINCLUDED) && !defined(Gstreamer_Post_Include)
Gstreamer_Post_Include=	bsd.gstreamer.mk

.if (defined (USE_GSTREAMER) && defined(USE_GSTREAMER1))
IGNORE=	USE_GSTREAMER and USE_GSTREAMER1 can't be used together
.endif

.if defined(USE_GSTREAMER)
.for ext in ${USE_GSTREAMER}
${ext}_GST_PREFIX?=	gstreamer-plugins-
${ext}_GST_VERSION?=	${GST_VERSION}${GST_MINOR_VERSION}
${ext}_NAME?=		${ext}
. if ${_USE_GSTREAMER_ALL:M${ext}}!= "" && exists(${PORTSDIR}/${${ext}_DEPENDS})
BUILD_DEPENDS+=	${${ext}_GST_PREFIX}${${ext}_NAME}>=${${ext}_GST_VERSION}:${${ext}_DEPENDS}
RUN_DEPENDS+=	${${ext}_GST_PREFIX}${${ext}_NAME}>=${${ext}_GST_VERSION}:${${ext}_DEPENDS}
. else
IGNORE=	cannot install: unknown gstreamer ${GST_VERSION} plugin -- ${ext}
. endif
.endfor
.endif

.if defined(USE_GSTREAMER1)
.for ext in ${USE_GSTREAMER1}
${ext}_GST_PREFIX?=	gstreamer1-plugins-
${ext}_GST_VERSION?=	${GST1_VERSION}${GST1_MINIMAL_VERSION}
${ext}_NAME10?=		${ext}
${ext}_GST_DEPENDS?=	${${ext}_DEPENDS:S,gstreamer-,gstreamer1-,}
. if ${_USE_GSTREAMER_ALL:M${ext}}!= "" && exists(${PORTSDIR}/${${ext}_GST_DEPENDS})
BUILD_DEPENDS+=	${${ext}_GST_PREFIX}${${ext}_NAME10}>=${${ext}_GST_VERSION}:${${ext}_GST_DEPENDS}
RUN_DEPENDS+=	${${ext}_GST_PREFIX}${${ext}_NAME10}>=${${ext}_GST_VERSION}:${${ext}_GST_DEPENDS}
. else
IGNORE=	cannot install: unknown gstreamer ${GST1_VERSION} plugin -- ${ext}
. endif
.endfor
.endif

# The End
.endif
