#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# bsd.gstreamer.mk - Support for gstreamer-plugins-based ports.
#
# Created by: Michael Johnson <ahze@FreeBSD.org>
# Date:		4 Oct 2004
#
# $FreeBSD$
#

.if !defined(_POSTMKINCLUDED) && !defined(Gstreamer_Pre_Include)

Gstreamer_Include_MAINTAINER=	gnome@FreeBSD.org
Gstreamer_Pre_Include=		bsd.gstreamer.mk

.endif

# Ports can use the following:
#
# USE_GSTREAMER=	dvd lame flac
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
_GST_LIB_BASE=		${X11BASE}/lib/gstreamer-${GST_VERSION}
GST_VERSION=		0.8
GST_SHLIB_VERSION=	1

#
# These are the current supported gstreamer-plugins modules
#
_USE_GSTREAMER_ALL=	a52dec aalib artsd audiofile cairo cdaudio cdparanoia \
			dirac dts dv dvd esound faac faad ffmpeg flac \
			gdkpixbuf gnomevfs gsm hermes ivorbis jack jpeg \
			jpeg-mmx ladspa lame libcaca libfame libmng libpng \
			libvisual mad mikmod mpeg2dec mpeg2enc mplex musepack \
			musicbrainz nas sdl shout shout2 sidplay smoothwave \
			sndfile speex theora ogg pango polypaudio swfdec \
			vorbis xine xvid

# other plugins
OTHER_GSTREAMER_PLUGINS+=	core yes
_USE_GSTREAMER_ALL+=	${OTHER_GSTREAMER_PLUGINS}

core_DEPENDS=	multimedia/gstreamer-plugins-core
core_PLIST=	.gstreamer-plugins-core
core_GST_EXT=	.keep

yes_DEPENDS=	multimedia/gstreamer-plugins
yes_PLIST=	libgstac3parse

# Audio Plugins Section
a52dec_DEPENDS=	audio/gstreamer-plugins-a52dec

artsd_DEPENDS=	audio/gstreamer-plugins-artsd
artsd_PLIST=	libgstartsdsink

audiofile_DEPENDS=	audio/gstreamer-plugins-audiofile

cdaudio_DEPENDS=	audio/gstreamer-plugins-cdaudio

cdparanoia_DEPENDS=	audio/gstreamer-plugins-cdparanoia

esound_DEPENDS=	audio/gstreamer-plugins-esound
esound_PLIST=	libgstesd

faac_DEPENDS=	audio/gstreamer-plugins-faac

faad_DEPENDS=	audio/gstreamer-plugins-faad

flac_DEPENDS=	audio/gstreamer-plugins-flac

gsm_DEPENDS=	audio/gstreamer-plugins-gsm

ivorbis_DEPENDS=	audio/gstreamer-plugins-ivorbis

jack_DEPENDS=	audio/gstreamer-plugins-jack

ladspa_DEPENDS=	audio/gstreamer-plugins-ladspa

lame_DEPENDS=	audio/gstreamer-plugins-lame

mad_DEPENDS=	audio/gstreamer-plugins-mad

mikmod_DEPENDS=	audio/gstreamer-plugins-mikmod

musepack_DEPENDS=	audio/gstreamer-plugins-musepack

musicbrainz_DEPENDS=	audio/gstreamer-plugins-musicbrainz
musicbrainz_PLIST=	libgsttrm

nas_DEPENDS=	audio/gstreamer-plugins-nas
nas_PLIST=	libgstnassink

ogg_DEPENDS=	audio/gstreamer-plugins-ogg

polypaudio_DEPENDS=	audio/gstreamer-plugins-polypaudio
polypaudio_PLIST=	libpolypaudio

shout_DEPENDS=	audio/gstreamer-plugins-shout

sidplay_DEPENDS=	audio/gstreamer-plugins-sidplay
sidplay_PLIST=	libgstsid

smoothwave_DEPENDS=	audio/gstreamer-plugins-smoothwave

sndfile_DEPENDS=	audio/gstreamer-plugins-sndfile

speex_DEPENDS=	audio/gstreamer-plugins-speex

vorbis_DEPENDS=	audio/gstreamer-plugins-vorbis


# Devel Plugins Section
gnomevfs_DEPENDS=	devel/gstreamer-plugins-gnomevfs

sdl_DEPENDS=	devel/gstreamer-plugins-sdl
sdl_PLIST=	libgstsdlvideosink

# Graphics Plugins Section
aalib_DEPENDS=	graphics/gstreamer-plugins-aalib
aalib_PLIST=	libgstaasink

cairo_DEPENDS=	graphics/gstreamer-plugins-cairo

gdkpixbuf_DEPENDS=	graphics/gstreamer-plugins-gdkpixbuf

hermes_DEPENDS=	graphics/gstreamer-plugins-hermes
hermes_PLIST=	libgsthermescolorspace

jpeg_DEPENDS=	graphics/gstreamer-plugins-jpeg

jpeg-mmx_DEPENDS=	graphics/gstreamer-plugins-jpeg-mmx
jpeg-mmx_PLIST=	libgstjpeg

libcaca_DEPENDS=	graphics/gstreamer-plugins-libcaca
libcaca_PLIST=	libgstcacasink

libmng_DEPENDS=	graphics/gstreamer-plugins-libmng
libmng_PLIST=	libgstmng

libpng_DEPENDS=	graphics/gstreamer-plugins-libpng
libpng_PLIST=	libgstpng

libvisual_DEPNDS=	graphics/gstreamer-plugins-libvisual

swfdec_DEPENDS=	graphics/gstreamer-plugins-swfdec

# Multimedia Plugins Section
dirac_DEPENDS=	multimedia/gstreamer-plugins-dirac

dts_DEPENDS=	multimedia/gstreamer-plugins-dts
dts_PLIST=	libgstdtsdec

ffmpeg_DEPENDS=	multimedia/gstreamer-ffmpeg

libcaca_PLIST=	libgstcacasink

dv_DEPENDS=	multimedia/gstreamer-plugins-dv
dv_PLIST=	libgstdv

dvd_DEPENDS=	multimedia/gstreamer-plugins-dvd
dvd_PLIST=	libgstdvdnavsrc

libfame_DEPENDS=	multimedia/gstreamer-plugins-libfame

mpeg2dec_DEPENDS=	multimedia/gstreamer-plugins-mpeg2dec

mpeg2enc_DEPENDS=	multimedia/gstreamer-plugins-mpeg2enc

mplex_DEPENDS=	multimedia/gstreamer-plugins-mplex

theora_DEPENDS=	multimedia/gstreamer-plugins-theora

xine_DEPENDS=	multimedia/gstreamer-plugins-xine

xvid_DEPENDS=	multimedia/gstreamer-plugins-xvid

# X11-Toolkits Plugins Section
pango_DEPENDS=	x11-toolkits/gstreamer-plugins-pango
pango_PLIST=	libgsttextoverlay

.if defined(_POSTMKINCLUDED) && !defined(Gstreamer_Post_Include)
Gstreamer_Post_Include=	bsd.gstreamer.mk

# defined ext_PLIST="" for each port that uses auto plist
.for ext in ${USE_GSTREAMER}
${ext}_PLIST?=
${ext}_GST_EXT?=	.so
.endfor

.for ext in ${USE_GSTREAMER}
. if ${_USE_GSTREAMER_ALL:M${ext}}!= "" && exists(${PORTSDIR}/${${ext}_DEPENDS})
.  if ${${ext}_PLIST} != ""
BUILD_DEPENDS+=	${_GST_LIB_BASE}/${${ext}_PLIST}${${ext}_GST_EXT}:${PORTSDIR}/${${ext}_DEPENDS}
RUN_DEPENDS+=	${_GST_LIB_BASE}/${${ext}_PLIST}${${ext}_GST_EXT}:${PORTSDIR}/${${ext}_DEPENDS}
.  else
BUILD_DEPENDS+= ${_GST_LIB_BASE}/libgst${ext}.so:${PORTSDIR}/${${ext}_DEPENDS}
RUN_DEPENDS+=   ${_GST_LIB_BASE}/libgst${ext}.so:${PORTSDIR}/${${ext}_DEPENDS}
.  endif
. else
BROKEN=	"Unknown gstreamer-plugin -- ${ext}"
. endif
.endfor

# The End
.endif
