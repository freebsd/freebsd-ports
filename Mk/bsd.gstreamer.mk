#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# bsd.gstreamer.mk - Support for gstreamer-plugins-based ports.
#
# Created by: Michael Johnson <ahze@FreeBSD.org>
# Date:		4 Oct 2004
#
# $FreeBSD$
#    $MCom: ports/Mk/bsd.gstreamer.mk,v 1.38 2006/10/10 20:22:01 mezz Exp $

.if !defined(_POSTMKINCLUDED) && !defined(Gstreamer_Pre_Include)

Gstreamer_Include_MAINTAINER=	multimedia@FreeBSD.org
Gstreamer_Pre_Include=		bsd.gstreamer.mk

.endif

# Ports can use the following:
#
#  For Gstreamer 0.10:
# USE_GSTREAMER=	lame faac ffmpeg
#
# If you want to use USE_GSTREAMER after <bsd.port.pre.mk>
# you must follow one of the examples listed below
#
#	WANT_GSTREAMER=	yes
#	.include <bsd.port.pre.mk>
#	.if defined(WITH_VORBIS)
#	USE_GSTREAMER+=	vorbis
#	.endif
#
# or
#       USE_GSTREAMER=	yes
#       .include <bsd.port.pre.mk>
#       .if defined(WITH_FAAD)
#       USE_GSTREAMER+=	faad
#       .endif
#
#
#	USE_GSTREAMER=yes will always add a dependency to
#		gstreamer-plugins
#

# "Normal" dependencies and variables
#

GSTREAMER_PORT=		${PORTSDIR}/multimedia/gstreamer-plugins
_GST_LIB_BASE=		${LOCALBASE}/lib/gstreamer-${GST_VERSION}
GST_VERSION=		0.10
GST_MINOR_VERSION=	.0
GST_SHLIB_VERSION=	1
#
# These are the current supported gstreamer-plugins modules
#
_USE_GSTREAMER10_ALL=	a52dec aalib annodex bad bz2 cairo cdaudio cdparanoia dts \
			dv dvd esound faac faad ffmpeg flac gconf gnomevfs \
			gnonlin good gsm hal ivorbis jack jpeg ladspa lame \
			libcaca libmms libpng libvisual mp3 mpeg2enc mpeg2dec \
			musepack nas neon ogg pango pulse python sdl shout2 sidplay \
			sndfile spc speex swfdec theora ugly vorbis wavpack x264 xvid

# other plugins
OTHER_GSTREAMER_PLUGINS+=	core yes ${_USE_GSTREAMER10_ALL} fluendo-mp3 mad

_USE_GSTREAMER_ALL+=	${OTHER_GSTREAMER_PLUGINS}

core_DEPENDS=	multimedia/gstreamer-plugins-core

yes_DEPENDS=	multimedia/gstreamer-plugins
yes_NAME=	gstreamer-plugins
yes_GST_PREFIX=	# empty

cdio_DEPENDS=	sysutils/gstreamer-plugins-cdio

gconf_DEPENDS=	devel/gstreamer-plugins-gconf

# Audio Plugins Section
a52dec_DEPENDS=	audio/gstreamer-plugins-a52dec

artsd_DEPENDS=	audio/gstreamer-plugins-artsd

audiofile_DEPENDS=	audio/gstreamer-plugins-audiofile

cdaudio_DEPENDS=	audio/gstreamer-plugins-cdaudio

cdparanoia_DEPENDS=	audio/gstreamer-plugins-cdparanoia

esound_DEPENDS=	audio/gstreamer-plugins-esound

faac_DEPENDS=	audio/gstreamer-plugins-faac

faad_DEPENDS=	audio/gstreamer-plugins-faad

flac_DEPENDS=	audio/gstreamer-plugins-flac

fluendo-mp3_DEPENDS=	audio/gstreamer-plugins-fluendo-mp3

gsm_DEPENDS=	audio/gstreamer-plugins-gsm

ivorbis_DEPENDS=	audio/gstreamer-plugins-ivorbis

hal_DEPENDS=	sysutils/gstreamer-plugins-hal

jack_DEPENDS=	audio/gstreamer-plugins-jack

ladspa_DEPENDS=	audio/gstreamer-plugins-ladspa

lame_DEPENDS=	audio/gstreamer-plugins-lame

mad_DEPENDS=	audio/gstreamer-plugins-mad

mikmod_DEPENDS=	audio/gstreamer-plugins-mikmod

mp3_DEPENDS=	audio/gstreamer-plugins-mp3

musepack_DEPENDS=	audio/gstreamer-plugins-musepack

musicbrainz_DEPENDS=	audio/gstreamer-plugins-musicbrainz

nas_DEPENDS=	audio/gstreamer-plugins-nas

neon_DEPENDS=	www/gstreamer-plugins-neon

ogg_DEPENDS=	audio/gstreamer-plugins-ogg

polyp_DEPENDS=	audio/gstreamer-plugins-polyp

pulse_DEPENDS=	audio/gstreamer-plugins-pulse
pulse_GST_VERSION=	0.9.3

shout_DEPENDS=	audio/gstreamer-plugins-shout

shout2_DEPENDS=	audio/gstreamer-plugins-shout2

sidplay_DEPENDS=	audio/gstreamer-plugins-sidplay

smoothwave_DEPENDS=	audio/gstreamer-plugins-smoothwave

sndfile_DEPENDS=	audio/gstreamer-plugins-sndfile

spc_DEPENDS=	audio/gstreamer-plugins-spc

speex_DEPENDS=	audio/gstreamer-plugins-speex

vorbis_DEPENDS=	audio/gstreamer-plugins-vorbis

wavpack_DEPENDS=	audio/gstreamer-plugins-wavpack

# Devel Plugins Section
gnomevfs_DEPENDS=	devel/gstreamer-plugins-gnomevfs

sdl_DEPENDS=	devel/gstreamer-plugins-sdl

# Graphics Plugins Section
aalib_DEPENDS=	graphics/gstreamer-plugins-aalib

annodex_DEPENDS=	multimedia/gstreamer-plugins-annodex

cairo_DEPENDS=	graphics/gstreamer-plugins-cairo

gdkpixbuf_DEPENDS=	graphics/gstreamer-plugins-gdkpixbuf

hermes_DEPENDS=	graphics/gstreamer-plugins-hermes

jpeg_DEPENDS=	graphics/gstreamer-plugins-jpeg

libcaca_DEPENDS=	graphics/gstreamer-plugins-libcaca

libmng_DEPENDS=	graphics/gstreamer-plugins-libmng

libpng_DEPENDS=	graphics/gstreamer-plugins-libpng

libvisual_DEPENDS=	graphics/gstreamer-plugins-libvisual

swfdec_DEPENDS=	graphics/gstreamer-plugins-swfdec

# Multimedia Plugins Section
bad_DEPENDS=	multimedia/gstreamer-plugins-bad

bz2_DEPENDS=	multimedia/gstreamer-plugins-bz2

ffmpeg_DEPENDS=	multimedia/gstreamer-ffmpeg
ffmpeg_GST_PREFIX=	gstreamer-
ffmpeg_GST_SUFX=	# empty
ffmpeg_GST_VERSION=	0.10.0

dts_DEPENDS=	multimedia/gstreamer-plugins-dts

dv_DEPENDS=	multimedia/gstreamer-plugins-dv

dvd_DEPENDS=	multimedia/gstreamer-plugins-dvd

good_DEPENDS=	multimedia/gstreamer-plugins-good

gnonlin_DEPENDS=	multimedia/gstreamer-plugins-gnonlin

libfame_DEPENDS=	multimedia/gstreamer-plugins-libfame

mpeg2dec_DEPENDS=	multimedia/gstreamer-plugins-mpeg2dec

mpeg2enc_DEPENDS=	multimedia/gstreamer-plugins-mpeg2enc

mplex_DEPENDS=	multimedia/gstreamer-plugins-mplex

# XXX: This is a quick solution for ports with USE_GSTREAMER=python
#      but without USE_PYTHON.
PYTHON_PKGNAMEPREFIX?=	py*-

python_DEPENDS=	multimedia/py-gstreamer
python_NAME=	gstreamer
python_GST_PREFIX=      ${PYTHON_PKGNAMEPREFIX}
python_GST_SUFX=        # empty
python_GST_VERSION=     0.10.4

theora_DEPENDS=	multimedia/gstreamer-plugins-theora

ugly_DEPENDS=	multimedia/gstreamer-plugins-ugly

x264_DEPENDS=	multimedia/gstreamer-plugins-x264

xvid_DEPENDS=	multimedia/gstreamer-plugins-xvid

# Net Plugins Section

libmms_DEPENDS=	net/gstreamer-plugins-libmms

# X11-Toolkits Plugins Section
pango_DEPENDS=	x11-toolkits/gstreamer-plugins-pango

.if defined(_POSTMKINCLUDED) && !defined(Gstreamer_Post_Include)
Gstreamer_Post_Include=	bsd.gstreamer.mk

.for ext in ${USE_GSTREAMER}
${ext}_GST_PREFIX?=	gstreamer-plugins-
${ext}_GST_VERSION?=	${GST_VERSION}${GST_MINOR_VERSION}
${ext}_NAME?=		${ext}
. if ${_USE_GSTREAMER_ALL:M${ext}}!= "" && exists(${PORTSDIR}/${${ext}_DEPENDS})
BUILD_DEPENDS+=	${${ext}_GST_PREFIX}${${ext}_NAME}>=${${ext}_GST_VERSION}:${PORTSDIR}/${${ext}_DEPENDS}
RUN_DEPENDS+=	${${ext}_GST_PREFIX}${${ext}_NAME}>=${${ext}_GST_VERSION}:${PORTSDIR}/${${ext}_DEPENDS}
. else
IGNORE=	cannot install: unknown gstreamer-plugin -- ${ext}
. endif
.endfor

# The End
.endif
