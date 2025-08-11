# Support for GStreamer-related libraries and plugins
#
# Feature:		gstreamer
# Usage:
#   USES=		gstreamer[:version][,arg,...]
#   USE_GSTREAMER=	[list of components]
#
# Valid ARGS:		<version>, _internal
#
# version:		1 -- default (this may be omitted since there is
#			currently only one supported version)
# _internal:		Only intended for use by multimedia/gstreamer1 to
#			define specific variables so as not depend on itself
#
# MAINTAINER: multimedia@FreeBSD.org

.if ! defined(_INCLUDE_USES_GSTREAMER_MK)
_INCLUDE_USES_GSTREAMER_MK=	YES

#== Argument handling

# Preparations to support multiple gstreamer versions
_GST_VER_SUPPORTED=	1
_GST_VER_DEFAULT=	1
_GST_VER=		#
.  for ver in ${_GST_VER_SUPPORTED:O:u}
.    if ${gstreamer_ARGS:M${ver}}
.      if empty(_GST_VER)
_GST_VER=	${ver}
.      else
IGNORE=	Incorrect USES=gstreamer:${gstreamer_ARGS} - multiple versions defined
.      endif
.    endif
.  endfor

.  if empty(_GST_VER)
_GST_VER=	${_GST_VER_DEFAULT}
.  endif

#== Component setup

# When modifying _GST1_VERSION, run `make -C ${PORTSDIR}/multimedia/gstreamer1 makesum-all`
# to update the distinfo files for the entire suite.
_GST1_VERSION=		1.26.5
_GST1_LIB_VER=		1.0
_GST1_SOVERSION=	0.${_GST1_VERSION:R:E}${${_GST1_VERSION:E} > 9:?:0}${_GST1_VERSION:E}.0

_GST1_CATEGORIES=	audio comms devel ftp graphics multimedia net security \
			sysutils textproc www x11 x11-toolkits
_GST1_PLUGINS_audio= 	a52dec alsa amrnb amrwbdec bs2b cdparanoia chromaprint faac \
			faad fdkaac flac flite gme gsm jack ladspa lame lv2 modplug \
			mpg123 ogg openmpt opus pulse shout2 sidplay \
			sndfile sndio soundtouch speex taglib twolame vorbis \
			wavpack webrtcdsp
_GST1_PLUGINS_comms=	spandsp
_GST1_PLUGINS_devel=	soup
_GST1_PLUGINS_ftp=	curl
_GST1_PLUGINS_graphics=	aalib cairo gdkpixbuf gl jpeg kms libcaca libvisual \
			opencv openexr openjpeg png rsvg vulkan webp zbar
_GST1_PLUGINS_multimedia=	aom assrender bad dash dts dv dvdread \
			editing-services good hls libav libde265 \
			mpeg2dec mpeg2enc mplex mm msdk openh264 resindvd \
			rtsp-server rust smoothstreaming theora ttml ugly \
			v4l2 vaapi vpx webrtc x264 x265
_GST1_PLUGINS_net=	sctp srtp
_GST1_PLUGINS_security=	dtls
_GST1_PLUGINS_sysutils=	cdio
_GST1_PLUGINS_textproc=	zxing
_GST1_PLUGINS_www=	neon srt
_GST1_PLUGINS_x11=	x ximagesrc
_GST1_PLUGINS_x11-toolkits=	gtk pango qt5 qt6

# == Unversioned information

# Gather all available plugins for the chosen version
_GST_PLUGINS_BASE=	bad core good ugly libgstreamer plugins
_GST_PLUGINS_VER:=	${_GST${_GST_VER}_CATEGORIES:S/^/\${_GST${_GST_VER}_PLUGINS_/:S/$/}/}

_GST_VERSION=		${_GST${_GST_VER}_VERSION}
_GST_LIB_VER=		${_GST${_GST_VER}_LIB_VER}
_GST_SOVERSION=		${_GST${_GST_VER}_SOVERSION}

# List of all available components
_USE_GSTREAMER_ALL=	${_GST_PLUGINS_BASE} \
			${_GST_PLUGINS_VER}

#==  Dependency setup

#==== Top-level components

gst-plugins_PORT=	multimedia/gstreamer${_GST_VER}-plugins
gst-plugins_IMPL=	# empty
gst-plugins_SUFFIX=	#

gst-bad_PORT=		multimedia/gstreamer${_GST_VER}-plugins-bad
gst-bad_IMPL=		#

gst-core_PORT=		multimedia/gstreamer${_GST_VER}-plugins-core
gst-core_IMPL=		#
gst-core_GST1_VERSION=	${_GST1_VERSION:R}
gst-core_VERSION=	${gst-core_GST${_GST_VER}_VERSION}

gst-good_PORT=		multimedia/gstreamer${_GST_VER}-plugins-good
gst-good_IMPL=		#

gst-ugly_PORT=		multimedia/gstreamer${_GST_VER}-plugins-ugly
gst-ugly_IMPL=		#

gst-libgstreamer_LIB=	libgstreamer${_GST${_GST_VER}_LIB_VER:D-${_GST${_GST_VER}_LIB_VER}}.so
gst-libgstreamer_PORT=	multimedia/gstreamer${_GST_VER}

#==== audio plugins section

gst-a52dec_PORT=	audio/gstreamer${_GST_VER}-plugins-a52dec
gst-a52dec_IMPL=	ugly

gst-alsa_PORT=		audio/gstreamer${_GST_VER}-plugins-alsa
gst-alsa_IMPL=		#

gst-amrnb_PORT=		audio/gstreamer${_GST_VER}-plugins-amrnb
gst-amrnb_IMPL=		ugly

gst-amrwbdec_PORT=	audio/gstreamer${_GST_VER}-plugins-amrwbdec
gst-amrwbdec_IMPL=	ugly

gst-bs2b_PORT=		audio/gstreamer${_GST_VER}-plugins-bs2b
gst-bs2b_IMPL=		bad

gst-cdparanoia_PORT=	audio/gstreamer${_GST_VER}-plugins-cdparanoia
gst-cdparanoia_IMPL=	#

gst-chromaprint_PORT=	audio/gstreamer${_GST_VER}-plugins-chromaprint
gst-chromeprint_IMPL=	bad

gst-faac_PORT=		audio/gstreamer${_GST_VER}-plugins-faac
gst-faac_IMPL=		bad

gst-faad_PORT=		audio/gstreamer${_GST_VER}-plugins-faad
gst-faad_IMPL=		bad

gst-fdkaac_PORT=	audio/gstreamer${_GST_VER}-plugins-fdkaac
gst-fdkaac_IMPL=	bad

gst-flac_PORT=		audio/gstreamer${_GST_VER}-plugins-flac
gst-flac_IMPL=		good

gst-flite_PORT=		audio/gstreamer${_GST_VER}-plugins-flite
gst-flite_IMPL=		bad

gst-gme_PORT=		audio/gstreamer${_GST_VER}-plugins-gme
gst-gme_IMPL=		bad

gst-gsm_PORT=		audio/gstreamer${_GST_VER}-plugins-gsm
gst-gsm_IMPL=		bad

gst-jack_PORT=		audio/gstreamer${_GST_VER}-plugins-jack
gst-jack_IMPL=		good

gst-ladspa_PORT=	audio/gstreamer${_GST_VER}-plugins-ladspa
gst-ladspa_IMPL=	bad

gst-lame_PORT=		audio/gstreamer${_GST_VER}-plugins-lame
gst-lame_IMPL=		ugly

gst-lv2_PORT=		audio/gstreamer${_GST_VER}-plugins-lv2
gst-lv2_IMPL=		bad

gst-modplug_PORT=	audio/gstreamer${_GST_VER}-plugins-modplug
gst-modplug_IMPL=	bad

gst-mpg123_PORT=	audio/gstreamer${_GST_VER}-plugins-mpg123
gst-mpg123_IMPL=	ugly

gst-ogg_PORT=		audio/gstreamer${_GST_VER}-plugins-ogg
gst-ogg_IMPL=		#

gst-openmpt_PORT=	audio/gstreamer${_GST_VER}-plugins-openmpt
gst-openmpt_IMPL=	bad

gst-opus_PORT=		audio/gstreamer${_GST_VER}-plugins-opus
gst-opus_IMPL=		#

gst-pulse_PORT=		audio/gstreamer${_GST_VER}-plugins-pulse
gst-pulse_IMPL=		good

gst-shout2_PORT=	audio/gstreamer${_GST_VER}-plugins-shout2
gst-shout2_IMPL=	good

gst-sidplay_PORT=	audio/gstreamer${_GST_VER}-plugins-sidplay
gst-sidplay_IMPL=	ugly

gst-sndfile_PORT=	audio/gstreamer${_GST_VER}-plugins-sndfile
gst-sndfile_IMPL=	bad

gst-sndio_PORT=		audio/gstreamer${_GST_VER}-plugins-sndio
gst-sndio_IMPL=		#
gst-sndio_GST1_VERSION=	1.24.0
gst-sndio_VERSION=	${gst-sndio_GST${_GST_VER}_VERSION}

gst-soundtouch_PORT=	audio/gstreamer${_GST_VER}-plugins-soundtouch
gst-soundtouch_IMPL=	bad

gst-speex_PORT=		audio/gstreamer${_GST_VER}-plugins-speex
gst-speex_IMPL=		good

gst-taglib_PORT=	audio/gstreamer${_GST_VER}-plugins-taglib
gst-taglib_IMPL=	good

gst-twolame_PORT=	audio/gstreamer${_GST_VER}-plugins-twolame
gst-twolame_IMPL=	ugly

gst-vorbis_PORT=	audio/gstreamer${_GST_VER}-plugins-vorbis
gst-vorbis_IMPL=	#

gst-wavpack_PORT=	audio/gstreamer${_GST_VER}-plugins-wavpack
gst-wavpack_IMPL=	good

gst-webrtcdsp_PORT=	audio/gstreamer${_GST_VER}-plugins-webrtcdsp
gst-webrtcdsp_IMPL=	bad

#==== comms plugin section

gst-spandsp_PORT=	comms/gstreamer${_GST_VER}-plugins-spandsp
gst-spandsp_IMPL=	bad

#==== devel plugin section

gst-soup_PORT=		devel/gstreamer${_GST_VER}-plugins-soup
gst-soup_IMPL=		good

#==== ftp plugin section

gst-curl_PORT=		ftp/gstreamer${_GST_VER}-plugins-curl
gst-curl_IMPL=		bad

#==== graphics plugin section

gst-aalib_PORT=		graphics/gstreamer${_GST_VER}-plugins-aalib
gst-aalib_IMPL=		good

gst-cairo_PORT=		graphics/gstreamer${_GST_VER}-plugins-cairo
gst-cairo_IMPL=		good

gst-gdkpixbuf_PORT=	graphics/gstreamer${_GST_VER}-plugins-gdkpixbuf
gst-gdkpixbuf_IMPL=	good

gst-gl_PORT=		graphics/gstreamer${_GST_VER}-plugins-gl
gst-gl_IMPL=		bad

gst-jpeg_PORT=		graphics/gstreamer${_GST_VER}-plugins-jpeg
gst-jpeg_IMPL=		good

gst-kms_PORT=		graphics/gstreamer${_GST_VER}-plugins-kms
gst-kms_IMPL=		bad

gst-libcaca_PORT=	graphics/gstreamer${_GST_VER}-plugins-libcaca
gst-libcaca_IMPL=	good

gst-libvisual_PORT=	graphics/gstreamer${_GST_VER}-plugins-libvisual
gst-libvisual_IMPL=	#

gst-opencv_PORT=	graphics/gstreamer${_GST_VER}-plugins-opencv
gst-opencv_IMPL=	bad

gst-openexr_PORT=	graphics/gstreamer${_GST_VER}-plugins-openexr
gst-openexr_IMPL=	bad

gst-openjpeg_PORT=	graphics/gstreamer${_GST_VER}-plugins-openjpeg
gst-openjpeg_IMPL=	bad

gst-png_PORT=		graphics/gstreamer${_GST_VER}-plugins-png
gst-png_IMPL=		good

gst-rsvg_PORT=		graphics/gstreamer${_GST_VER}-plugins-rsvg
gst-rsvg_IMPL=		bad

gst-vulkan_PORT=	graphics/gstreamer${_GST_VER}-plugins-vulkan
gst-vulkan_IMPL=	bad

gst-webp_PORT=		graphics/gstreamer${_GST_VER}-plugins-webp
gst-webp_IMPL=		bad

gst-zbar_PORT=		graphics/gstreamer${_GST_VER}-plugins-zbar
gst-zbar_IMPL=		bad

#==== multimedia plugins section

gst-aom_PORT=		multimedia/gstreamer${_GST_VER}-plugins-aom
gst-aom_IMPL=		bad

gst-assrender_PORT=	multimedia/gstreamer${_GST_VER}-plugins-assrender
gst-assrender_IMPL=	bad

gst-dash_PORT=		multimedia/gstreamer${_GST_VER}-plugins-dash
gst-dash_IMPL=		bad

gst-dvdread_PORT=	multimedia/gstreamer${_GST_VER}-plugins-dvdread
gst-dvdread_IMPL=	ugly

gst-dts_PORT=		multimedia/gstreamer${_GST_VER}-plugins-dts
gst-dts_IMPL=		bad

gst-dv_PORT=		multimedia/gstreamer${_GST_VER}-plugins-dv
gst-dv_IMPL=		good

gst-editing-services_PORT=	multimedia/gstreamer${_GST_VER}-editing-services
gst-editing-services_SUFFIX=	#
gst-editing-services_IMPL=	#

gst-hls_PORT=		multimedia/gstreamer${_GST_VER}-plugins-hls
gst-hls_IMPL=		bad

gst-libav_PORT=		multimedia/gstreamer${_GST_VER}-libav
gst-libav_SUFFIX=	#
gst-libav_IMPL=		#

gst-libde265_PORT=	multimedia/gstreamer${_GST_VER}-plugins-libde265
gst-libde265_IMPL=	bad

gst-mm_PORT=		multimedia/gstreamermm
gst-mm_PREFIX=		gstreamer
gst-mm_SUFFIX=		#
gst-mm_IMPL=		#
gst-mm_GST1_VERSION=	1.10.0
gst-mm_VERSION=		${gst-mm_GST${_GST_VER}_VERSION}

gst-mpeg2dec_PORT=	multimedia/gstreamer${_GST_VER}-plugins-mpeg2dec
gst-mpeg2dec_IMPL=	ugly

gst-mpeg2enc_PORT=	multimedia/gstreamer${_GST_VER}-plugins-mpeg2enc
gst-mpeg2enc_IMPL=	bad

gst-mplex_PORT=		multimedia/gstreamer${_GST_VER}-plugins-mplex
gst-mplex_IMPL=		bad

gst-msdk_PORT=		multimedia/gstreamer${_GST_VER}-plugins-msdk
gst-msdk_IMPL=		bad

gst-openh264_PORT=	multimedia/gstreamer${_GST_VER}-plugins-openh264
gst-openh264_IMPL=	bad

gst-resindvd_PORT=	multimedia/gstreamer${_GST_VER}-plugins-resindvd
gst-resindvd_IMPL=	bad

gst-rtsp-server_PORT=	multimedia/gstreamer${_GST_VER}-rtsp-server
gst-rtsp-server_SUFFIX=	#
gst-rtsp-server_IMPL=	#

gst-rust_PORT=		multimedia/gstreamer${_GST_VER}-plugins-rust
gst-rust_IMPL=		#
gst-rust_GST1_VERSION=	0.14.0
gst-rust_VERSION=	${gst-rust_GST${_GST_VER}_VERSION}

gst-smoothstreaming_PORT=	multimedia/gstreamer${_GST_VER}-plugins-smoothstreaming
gst-smoothstreaming_IMPL=	bad

gst-theora_PORT=	multimedia/gstreamer${_GST_VER}-plugins-theora
gst-theora_IMPL=	#

gst-ttml_PORT=		multimedia/gstreamer${_GST_VER}-plugins-ttml
gst-ttml_IMPL=		bad

gst-v4l2_PORT=		multimedia/gstreamer${_GST_VER}-plugins-v4l2
gst-v4l2_IMPL=		good

gst-vaapi_PORT=		multimedia/gstreamer${_GST_VER}-vaapi
gst-vaapi_SUFFIX=	#
gst-vaapi_IMPL=		#

gst-vpx_PORT=		multimedia/gstreamer${_GST_VER}-plugins-vpx
gst-vpx_IMPL=		good

gst-webrtc_PORT=	multimedia/gstreamer${_GST_VER}-plugins-webrtc
gst-webrtc_IMPL=	bad

gst-x264_PORT=		multimedia/gstreamer${_GST_VER}-plugins-x264
gst-x264_IMPL=		ugly

gst-x265_PORT=		multimedia/gstreamer${_GST_VER}-plugins-x265
gst-x265_IMPL=		bad

#==== net plugins section

gst-sctp_PORT=		net/gstreamer${_GST_VER}-plugins-sctp
gst-sctp_IMPL=		bad

gst-srtp_PORT=		net/gstreamer${_GST_VER}-plugins-srtp
gst-srtp_IMPL=		bad

#==== security plugins section

gst-dtls_PORT=		security/gstreamer${_GST_VER}-plugins-dtls
gst-dtls_IMPL=		bad

#==== sysutils plugins section

gst-cdio_PORT=		sysutils/gstreamer${_GST_VER}-plugins-cdio
gst-cdio_IMPL=		ugly

#==== textproc plugins section

gst-zxing_PORT=		textproc/gstreamer${_GST_VER}-plugins-zxing
gst-zxing_IMPL=		bad

#==== www plugins section

gst-neon_PORT=		www/gstreamer${_GST_VER}-plugins-neon
gst-neon_IMPL=		bad

gst-srt_PORT=		www/gstreamer${_GST_VER}-plugins-srt
gst-srt_IMPL=		bad

#==== x11 plugins section

gst-x_PORT=		x11/gstreamer${_GST_VER}-plugins-x
gst-x_IMPL=		#

gst-ximagesrc_PORT=	x11/gstreamer${_GST_VER}-plugins-ximagesrc
gst-ximagesrc_IMPL=	good

#==== x11-toolkits plugins section

gst-gtk_PORT=		x11-toolkits/gstreamer${_GST_VER}-plugins-gtk
gst-gtk_IMPL=		bad

gst-pango_PORT=		x11-toolkits/gstreamer${_GST_VER}-plugins-pango
gst-pango_IMPL=		#

gst-qt5_PORT=		x11-toolkits/gstreamer${_GST_VER}-plugins-qt5
gst-qt5_IMPL=		good

gst-qt6_PORT=		x11-toolkits/gstreamer${_GST_VER}-plugins-qt6
gst-qt6_IMPL=		good

#== Dependency creation

.  if empty(gstreamer_ARGS:M_internal)
_GST_BR_DEPENDS=	#
_GST_LIB_DEPENDS=	#

USE_GSTREAMER?=		#
# everything wants this
USE_GSTREAMER+=		libgstreamer
.    if ${PORTDIRNAME} != gstreamer${_GST_VER}-plugins
USE_GSTREAMER+=		plugins
.    endif

# Gather all Impl values
_GST_IMPL_LIST:=	${USE_GSTREAMER:S/^/\${gst-/:S/$/_IMPL}/}

# Combine the wanted copmonents and the required implementations
_USE_GSTREAMER=		${USE_GSTREAMER} \
			${_GST_IMPL_LIST}

.    for component in ${_USE_GSTREAMER:O:u}
# Fill in the common default component values
gst-${component}_VERSION?=	${_GST_VERSION}
gst-${component}_NAME?=		${component}
gst-${component}_PREFIX?=	gstreamer${_GST_VER}-
gst-${component}_SUFFIX?=	plugins-
gst-${component}_PKG?=		${gst-${component}_PREFIX}${gst-${component}_SUFFIX}${gst-${component}_NAME}

.      if empty(_USE_GSTREAMER_ALL:M${component})
IGNORE=	unknown gstreamer component '${component}' for gstreamer:${_GST_VER}
.      endif
.      if !empty(gst-${component}_LIB)
_GST_LIB_DEPENDS+=	${gst-${component}_LIB}:${gst-${component}_PORT}
.      else
_GST_BR_DEPENDS+=	${gst-${component}_PKG}>=${gst-${component}_VERSION}:${gst-${component}_PORT}
.      endif
.    endfor

LIB_DEPENDS+=	${_GST_LIB_DEPENDS:O:u}
BUILD_DEPENDS+=	${_GST_BR_DEPENDS:O:u}
RUN_DEPENDS+=	${_GST_BR_DEPENDS:O:u}

.  endif
.endif
