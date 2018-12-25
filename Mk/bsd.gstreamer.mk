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

# These are the current supported gstreamer-plugins modules:
# Supported plugins by both 0.10 and 1.0.
_GSTREAMER_PLUGINS= \
		a52dec \
		aalib \
		amrnb \
		amrwbdec \
		cairo \
		cdio \
		cdparanoia \
		dts \
		dv \
		faac \
		faad \
		flac \
		flite \
		gdkpixbuf \
		gl \
		gme \
		gnonlin \
		gsm \
		jack \
		jpeg \
		ladspa \
		lame \
		libcaca \
		libmms \
		libvisual \
		mpeg2dec \
		mpeg2enc \
		musepack \
		neon \
		ogg \
		opencv \
		opus \
		pango \
		pulse \
		resindvd \
		shout2 \
		sndfile \
		sndio \
		sidplay \
		soundtouch \
		soup \
		spc \
		speex \
		taglib \
		theora \
		twolame \
		v4l2 \
		vorbis \
		wavpack \
		x264

# plugins only in 0.10
.if defined(USE_GSTREAMER)
_GSTREAMER_PLUGINS+= \
		annodex \
		bz2 \
		cdaudio \
		dvd \
		esound \
		ffmpeg \
		fluendo-mp3 \
		fluendo-mpegdemux \
		gconf \
		gio \
		gnomevfs \
		hal \
		libpng \
		mad \
		mm \
		mp3 \
		nas \
		python \
		qt4 \
		schroedinger \
		sdl \
		vdpau \
		vp8 \
		xvid
.endif # USE_GSTREAMER

# plugins only in 1.0
.if defined(USE_GSTREAMER1)
_GSTREAMER_PLUGINS+= \
		aom \
		assrender \
		bs2b \
		chromaprint \
		curl \
		dash \
		dtls \
		dvdread \
		editing-services \
		gtk \
		hls \
		kate \
		kms \
		libav \
		libde265 \
		lv2 \
		modplug \
		mpg123 \
		mplex \
		openexr \
		openh264 \
		openjpeg \
		openmpt \
		png \
		rsvg \
		rtmp \
		smoothstreaming \
		spandsp \
		srtp \
		ttml \
		vpx \
		vulkan \
		webp \
		webrtcdsp \
		x \
		x265 \
		ximagesrc \
		zbar
# vaapi
.endif # USE_GSTREAMER1

# other plugins
_USE_GSTREAMER_ALL=	bad core good ugly yes ${_GSTREAMER_PLUGINS}

#--------------------------------------------------------------------------#

core_DEPENDS=	multimedia/gstreamer-plugins-core
core_IMPL=	#

yes_DEPENDS=	multimedia/gstreamer-plugins
yes_NAME=	gstreamer-plugins
yes_NAME10=	gstreamer1-plugins
yes_GST_PREFIX=	# empty
yes_IMPL=	# empty

# XXX check if IMPL is correct for both 0.10 and 1.0

#-- audio plugins section -------------------------------------------------#

# Audio Plugins Section
a52dec_DEPENDS=	audio/gstreamer-plugins-a52dec
a52dec_IMPL=	ugly

amrnb_DEPENDS=	audio/gstreamer-plugins-amrnb
amrnb_IMPL=	ugly

amrwbdec_DEPENDS=	audio/gstreamer-plugins-amrwbdec
amrwbdec_IMPL=		ugly

bs2b_DEPENDS=	audio/gstreamer-plugins-bs2b
bs2b_IMPL=	bad

cdaudio_DEPENDS=	audio/gstreamer-plugins-cdaudio
cdaudio_IMPL=		bad

cdparanoia_DEPENDS=	audio/gstreamer-plugins-cdparanoia
cdparanoia_IMPL=	#

chromaprint_DEPENDS=	audio/gstreamer-plugins-chromaprint
chromeprint_IMPL=	bad

esound_DEPENDS=	audio/gstreamer-plugins-esound
esound_IMPL=	good

faac_DEPENDS=	audio/gstreamer-plugins-faac
faac_IMPL=	bad

faad_DEPENDS=	audio/gstreamer-plugins-faad
faad_IMPL=	bad

flac_DEPENDS=	audio/gstreamer-plugins-flac
flac_IMPL=	good

flite_DEPENDS=	audio/gstreamer-plugins-flite
flite_IMPL=	bad

fluendo-mp3_DEPENDS=	audio/gstreamer-plugins-fluendo-mp3
fluendo_IMPL=		#

gme_DEPENDS=	audio/gstreamer-plugins-gme
gme_IMPL=	bad

gsm_DEPENDS=	audio/gstreamer-plugins-gsm
gsm_IMPL=	bad

hal_DEPENDS=	sysutils/gstreamer-plugins-hal
hal_IMPL=	good

jack_DEPENDS=	audio/gstreamer-plugins-jack
jack_IMPL=	good

ladspa_DEPENDS=	audio/gstreamer-plugins-ladspa
ladspa_IMPL=	bad

lame_DEPENDS=	audio/gstreamer-plugins-lame
lame_IMPL=	ugly

lv2_DEPENDS=	audio/gstreamer-plugins-lv2
lv2_IMPL=	bad

mad_DEPENDS=	audio/gstreamer-plugins-mad
mad_IMPL=	ugly

modplug_DEPENDS=	audio/gstreamer-plugins-modplug
modplug_IMPL=		bad

mp3_DEPENDS=	audio/gstreamer-plugins-mp3
mp3_IMPL=	#

mpg123_DEPENDS=	audio/gstreamer-plugins-mpg123
mpg123_IMPL=	ugly

musepack_DEPENDS=	audio/gstreamer-plugins-musepack
musepack_IMPL=		bad

nas_DEPENDS=	audio/gstreamer-plugins-nas
nas_IMPL=	bad

neon_DEPENDS=	www/gstreamer-plugins-neon
neon_IMPL=	bad

ogg_DEPENDS=	audio/gstreamer-plugins-ogg
ogg_IMPL=	#

opus_DEPENDS=	audio/gstreamer-plugins-opus
opus_IMPL=	#

pulse_DEPENDS=	audio/gstreamer-plugins-pulse
pulse_IMPL=	good

shout2_DEPENDS=	audio/gstreamer-plugins-shout2
shout2_IMPL=	good

sidplay_DEPENDS=	audio/gstreamer-plugins-sidplay
sidplay_IMPL=		ugly

sndio_DEPENDS=	audio/gstreamer-plugins-sndio
sndio_IMPL=	#

sndfile_DEPENDS=	audio/gstreamer-plugins-sndfile
sndfile_IMPL=		bad

soundtouch_DEPENDS=	audio/gstreamer-plugins-soundtouch
soundtouch_IMPL=	bad

spc_DEPENDS=	audio/gstreamer-plugins-spc
spc_IMPL=	bad

speex_DEPENDS=	audio/gstreamer-plugins-speex
speex_IMPL=	good

taglib_DEPENDS=	audio/gstreamer-plugins-taglib
taglib_IMPL=	good

twolame_DEPENDS=	audio/gstreamer-plugins-twolame
twolame_IMPL=		ugly

vorbis_DEPENDS=	audio/gstreamer-plugins-vorbis
vorbis_IMPL=	#

wavpack_DEPENDS=	audio/gstreamer-plugins-wavpack
wavpack_IMPL=		good

webrtcdsp_DEPENDS=	audio/gstreamer-plugins-webrtcdsp
webrtcdsp_IMPL=		bad

#-- comms plugin section --------------------------------------------------#

spandsp_DEPENDS=	comms/gstreamer-plugins-spandsp
spandsp_IMPL=		bad

#-- devel plugin section --------------------------------------------------#

gconf_DEPENDS=	devel/gstreamer-plugins-gconf
gconf_IMPL=	good

gio_DEPENDS=	devel/gstreamer-plugins-gio
gio_IMPL=	#

gnomevfs_DEPENDS=	devel/gstreamer-plugins-gnomevfs
gnomevfs_IMPL=		#

sdl_DEPENDS=	devel/gstreamer-plugins-sdl
sdl_IMPL=	bad

soup_DEPENDS=	devel/gstreamer-plugins-soup
soup_IMPL=	good

#-- ftp plugin section ----------------------------------------------------#

curl_DEPENDS=	ftp/gstreamer-plugins-curl
curl_IMPL=	bad

#-- graphics plugin section -----------------------------------------------#

aalib_DEPENDS=	graphics/gstreamer-plugins-aalib
aalib_IMPL=	good

annodex_DEPENDS=	multimedia/gstreamer-plugins-annodex
annodex_IMPL=		good

aom_DEPENDS=	multimedia/gstreamer-plugins-aom
aom_IMPL=	bad

assrender_DEPENDS=	multimedia/gstreamer-plugins-assrender
assrender_IMPL=		bad

cairo_DEPENDS=	graphics/gstreamer-plugins-cairo
cairo_IMPL=	good

gdkpixbuf_DEPENDS=	graphics/gstreamer-plugins-gdkpixbuf
gdkpixbuf_IMPL=		good

gl_DEPENDS=	graphics/gstreamer-plugins-gl
gl_IMPL=	bad

jpeg_DEPENDS=	graphics/gstreamer-plugins-jpeg
jpeg_IMPL=	good

kms_DEPENDS=	graphics/gstreamer-plugins-kms
kms_IMPL=	bad

libcaca_DEPENDS=	graphics/gstreamer-plugins-libcaca
libcaca_IMPL=		good

libpng_DEPENDS=	graphics/gstreamer-plugins-libpng
libpng_IMPL=	good

libvisual_DEPENDS=	graphics/gstreamer-plugins-libvisual
libvisual_IMPL=		#

opencv_DEPENDS=	graphics/gstreamer-plugins-opencv
opencv_IMPL=	bad

openexr_DEPENDS=	graphics/gstreamer-plugins-openexr
openexr_IMPL=		bad

openjpeg_DEPENDS=	graphics/gstreamer-plugins-openjpeg
openjpeg_IMPL=		bad

openmpt_DEPENDS=	audio/gstreamer-plugins-openmpt
openmpt_IMPL=		bad

png_DEPENDS=	graphics/gstreamer-plugins-png
png_IMPL=	good

rsvg_DEPENDS=	graphics/gstreamer-plugins-rsvg
rsvg_IMPL=	bad

webp_DEPENDS=	graphics/gstreamer-plugins-webp
webp_IMPL=	bad

zbar_DEPENDS=	graphics/gstreamer-plugins-zbar
zbar_IMPL=	bad

#-- multimedia plugins section --------------------------------------------#

bad_DEPENDS=	multimedia/gstreamer-plugins-bad
bad_IMPL=	#

bz2_DEPENDS=	multimedia/gstreamer-plugins-bz2
bz2_IMPL=	bad

dash_DEPENDS=	multimedia/gstreamer-plugins-dash
dash_IMPL=	bad

dvdread_DEPENDS=	multimedia/gstreamer-plugins-dvdread
dvdread_IMPL=		ugly

editing-services_DEPENDS=	multimedia/gstreamer-editing-services
editing-services_GST_PREFIX=	gstreamer1-
editing-services_GST_SUFX=	# empty
editing-services_GST_VERSION=	1.0.0
editing-services_IMPL=		#

ffmpeg_DEPENDS=	multimedia/gstreamer-ffmpeg
ffmpeg_GST_PREFIX=	gstreamer-
ffmpeg_GST_SUFX=	# empty
ffmpeg_GST_VERSION=	0.10.0
ffmpeg_IMPL=		#

fluendo-mpegdemux_DEPENDS=	multimedia/gstreamer-plugins-fluendo-mpegdemux
fluendo-mpegdemux_IMPL=		#

dts_DEPENDS=	multimedia/gstreamer-plugins-dts
dts_IMPL=	bad

dv_DEPENDS=	multimedia/gstreamer-plugins-dv
dv_IMPL=	good

dvd_DEPENDS=	multimedia/gstreamer-plugins-dvd
dvd_IMPL=	ugly

good_DEPENDS=	multimedia/gstreamer-plugins-good
good_IMPL=	#

gnonlin_DEPENDS=	multimedia/gstreamer-plugins-gnonlin
gnonlin_IMPL=		good

hls_DEPENDS=	multimedia/gstreamer-plugins-hls
hls_IMPL=	bad

kate_DEPENDS=		multimedia/gstreamer-plugins-kate
kate_IMPL=		bad

libav_DEPENDS=		multimedia/gstreamer-libav
libav_GST_PREFIX=	gstreamer1-
libav_GST_SUFX=		# empty
libav_GST_VERSION=	1.0.0
libav_IMPL=		#

libde265_DEPENDS=	multimedia/gstreamer-plugins-libde265
libde265_IMPL=		bad

mm_DEPENDS=	multimedia/gstreamermm
mm_GST_PREFIX=	gstreamer
mm_GST_SUFX=	# empty
mm_GST_VERSION=	0.9.4
mm_IMPL=	#

mpeg2dec_DEPENDS=	multimedia/gstreamer-plugins-mpeg2dec
mpeg2dec_IMPL=		ugly

mpeg2enc_DEPENDS=	multimedia/gstreamer-plugins-mpeg2enc
mpeg2enc_IMPL=		bad

mplex_DEPENDS=	multimedia/gstreamer-plugins-mplex
mplex_IMPL=	bad

openh264_DEPENDS=	multimedia/gstreamer-plugins-openh264
openh264_IMPL=		bad

qt4_DEPENDS=	multimedia/gstreamer-qt4
qt4_GST_PREFIX=	gstreamer-
qt4_IMPL=	#

rtmp_DEPENDS=	multimedia/gstreamer-plugins-rtmp
rtmp_IMPL=	bad

smoothstreaming_DEPENDS=	multimedia/gstreamer-plugins-smoothstreaming
smoothstreaming_IMPL=		bad

ttml_DEPENDS=	multimedia/gstreamer-plugins-ttml
ttml_IMPL=	bad

v4l2_DEPENDS=	multimedia/gstreamer-plugins-v4l2
v4l2_IMPL=	good

# hmmm
vaapi_DEPENDS=	multimedia/gstreamer-vaapi
vaapi_IMPL=	bad

vp8_DEPENDS=	multimedia/gstreamer-plugins-vp8
vp8_IMPL=	bad

vpx_DEPENDS=	multimedia/gstreamer-plugins-vpx
vpx_IMPL=	good

vulkan_DEPENDS=	graphics/gstreamer-plugins-vulkan
vulkan_IMPL=	bad

# XXX: This is a quick solution for ports with USE_GSTREAMER=python
#      but without USE_PYTHON.
PYTHON_PKGNAMEPREFIX?=	py*-

python_DEPENDS=	multimedia/py-gstreamer
python_NAME=	gstreamer
python_GST_PREFIX=      ${PYTHON_PKGNAMEPREFIX}
python_GST_SUFX=        # empty
python_GST_VERSION=     0.10.4
python_IMPL=		#

resindvd_DEPENDS=	multimedia/gstreamer-plugins-resindvd
resindvd_IMPL=		bad

schroedinger_DEPENDS=	multimedia/gstreamer-plugins-schroedinger
schroedinger_IMPL=	bad

theora_DEPENDS=	multimedia/gstreamer-plugins-theora
theora_IMPL=	#

ugly_DEPENDS=	multimedia/gstreamer-plugins-ugly
ugly_IMPL=	#

vdpau_DEPENDS=	multimedia/gstreamer-plugins-vdpau
vdpau_IMPL=	bad

x264_DEPENDS=	multimedia/gstreamer-plugins-x264
x264_IMPL=	ugly

x265_DEPENDS=	multimedia/gstreamer-plugins-x265
x265_IMPL=	bad

xvid_DEPENDS=	multimedia/gstreamer-plugins-xvid
xvid_IMPL=	bad


#-- Net Plugins Section ---------------------------------------------------#

libmms_DEPENDS=	net/gstreamer-plugins-libmms
libmms_IMPL=	bad

srtp_DEPENDS=	net/gstreamer-plugins-srtp
srtp_IMPL=	bad

#-- security plugins section ----------------------------------------------#

dtls_DEPENDS=	security/gstreamer-plugins-dtls
dtls_IMPL=	bad

#-- sysutils plugins section ----------------------------------------------#

cdio_DEPENDS=	sysutils/gstreamer-plugins-cdio
cdio_IMPL=	ugly

#-- x11 plugins section ---------------------------------------------------#

x_DEPENDS=	x11/gstreamer-plugins-x
x_IMPL=		#

ximagesrc_DEPENDS=	x11/gstreamer-plugins-ximagesrc
ximagesrc_IMPL=		good

#-- x11-toolkits plugins section ------------------------------------------#

gtk_DEPENDS=	x11-toolkits/gstreamer-plugins-gtk
gtk_IMPL=	bad

pango_DEPENDS=	x11-toolkits/gstreamer-plugins-pango
pango_IMPL=	#

#--------------------------------------------------------------------------#

.if defined(_POSTMKINCLUDED) && !defined(Gstreamer_Post_Include)
Gstreamer_Post_Include=	bsd.gstreamer.mk

.if (defined (USE_GSTREAMER) && defined(USE_GSTREAMER1))
IGNORE=	USE_GSTREAMER and USE_GSTREAMER1 can't be used together
.endif

_GST_IMPL_LIST:=	#

.if defined(USE_GSTREAMER)
# update this with the gst 1.0 version below
. for ext in ${USE_GSTREAMER}
${ext}_GST_PREFIX?=	gstreamer-plugins-
${ext}_GST_VERSION?=	${GST_VERSION}${GST_MINOR_VERSION}
${ext}_NAME?=		${ext}
.  if ${_USE_GSTREAMER_ALL:M${ext}}!= "" && exists(${PORTSDIR}/${${ext}_DEPENDS})
_GST_BUILD_DEPENDS+=	${${ext}_GST_PREFIX}${${ext}_NAME}>=${${ext}_GST_VERSION}:${${ext}_DEPENDS}
_GST_RUN_DEPENDS+=	${${ext}_GST_PREFIX}${${ext}_NAME}>=${${ext}_GST_VERSION}:${${ext}_DEPENDS}
_GST_GST_IMPL_LIST+=	${${ext}_IMPL}
.  else
IGNORE=	cannot install: unknown gstreamer ${GST_VERSION} plugin -- ${ext}
.  endif
. endfor

# everything wants this
_GST_BUILD_DEPENDS+= gstreamer-plugins>=0:multimedia/gstreamer-plugins
_GST_LIB_DEPENDS+=   libgstreamer-0.10.so:multimedia/gstreamer
_GST_RUN_DEPENDS+=   gstreamer-plugins>=0:multimedia/gstreamer-plugins

. for plugin in ${_GST_IMPL_LIST:O:u}
_GST_BUILD_DEPENDS+=	gstreamer-plugins-${plugin}>=0:multimedia/gstreamer-plugins-${plugin}
_GST_RUN_DEPENDS+=	gstreamer-plugins-${plugin}>=0:multimedia/gstreamer-plugins-${plugin}
. endfor

BUILD_DEPENDS+= ${_GST_BUILD_DEPENDS:O:u}
LIB_DEPENDS+=   ${_GST_LIB_DEPENDS:O:u}
RUN_DEPENDS+=   ${_GST_RUN_DEPENDS:O:u}
.endif

.if defined(USE_GSTREAMER1)
. for ext in ${USE_GSTREAMER1}
${ext}_GST_PREFIX?=	gstreamer1-plugins-
${ext}_GST_VERSION?=	${GST1_VERSION}
${ext}_NAME10?=		${ext}
${ext}_GST_DEPENDS?=	${${ext}_DEPENDS:S,gstreamer-,gstreamer1-,}
.  if ${_USE_GSTREAMER_ALL:M${ext}}!= "" && exists(${PORTSDIR}/${${ext}_GST_DEPENDS})
_GST_BUILD_DEPENDS+=	${${ext}_GST_PREFIX}${${ext}_NAME10}>=${${ext}_GST_VERSION}:${${ext}_GST_DEPENDS}
_GST_RUN_DEPENDS+=	${${ext}_GST_PREFIX}${${ext}_NAME10}>=${${ext}_GST_VERSION}:${${ext}_GST_DEPENDS}
.   if defined(${ext}1_IMPL)
_GST_IMPL_LIST+=	${${ext}1_IMPL}
.   else
_GST_IMPL_LIST+=	${${ext}_IMPL}
.   endif
.  else
IGNORE=	cannot install: unknown gstreamer ${GST1_VERSION} plugin -- ${ext}
.  endif
. endfor

# everything wants this
_GST_BUILD_DEPENDS+=	gstreamer1-plugins>=${GST1_VERSION}:multimedia/gstreamer1-plugins
_GST_LIB_DEPENDS+=	libgstreamer-1.0.so:multimedia/gstreamer1
_GST_RUN_DEPENDS+=	gstreamer1-plugins>=${GST1_VERSION}:multimedia/gstreamer1-plugins

. for plugin in ${_GST_IMPL_LIST:O:u}
_GST_BUILD_DEPENDS+=	gstreamer1-plugins-${plugin}>=${GST1_VERSION}:multimedia/gstreamer1-plugins-${plugin}
_GST_RUN_DEPENDS+=	gstreamer1-plugins-${plugin}>=${GST1_VERSION}:multimedia/gstreamer1-plugins-${plugin}
. endfor

BUILD_DEPENDS+=	${_GST_BUILD_DEPENDS:O:u}
LIB_DEPENDS+=	${_GST_LIB_DEPENDS:O:u}
RUN_DEPENDS+=	${_GST_RUN_DEPENDS:O:u}
.endif

# The End
.endif
