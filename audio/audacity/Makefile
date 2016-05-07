# Created by: Marc van Woerkom <3d@FreeBSD.org>
# $FreeBSD$

PORTNAME=	audacity
PORTVERSION=	2.1.2
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	https://github.com/audacity/audacity/archive/
DISTNAME=	Audacity-${PORTVERSION}

MAINTAINER=	xxjack12xx@gmail.com
COMMENT=	GUI editor for digital audio waveforms

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	autogen:devel/autogen \
		bash:shells/bash \
		cmake:devel/cmake
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libsndfile.so:audio/libsndfile

BROKEN_powerpc64=	Does not build

WRKSRC=		${WRKDIR}/${PORTNAME}-Audacity-${PORTVERSION}

GNU_CONFIGURE=	yes
USES=		autoreconf compiler:c++11-lib cpe desktop-file-utils gettext-tools gmake iconv libtool pkgconfig shared-mime-info shebangfix dos2unix
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
NLS_CONFIGURE_WITH=	libintl-prefix="${LOCALBASE}"
OPTIONS_SUB=	yes
USE_WX=		3.0+
WX_COMPS=	wx
INSTALLS_ICONS=	yes
PORTDOCS=	README.txt
DOS2UNIX_GLOB=	Makefile.* *.c* *.h
SHEBANG_FILES=	lib-src/lv2/build

OPTIONS_DEFINE=	NLS DEBUG DOCS ALSA DYNLOAD FFMPEG FLAC ID3TAG LADSPA LAME LV2 \
		MAD SBSMS SOUNDTOUCH TWOLAME VAMP VORBIS VST
OPTIONS_DEFAULT=	FLAC ID3TAG LADSPA MAD \
			SBSMS SOUNDTOUCH TWOLAME VAMP VORBIS VST

OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFAULT_amd64=	SSE
OPTIONS_DEFAULT_i386=	${MACHINE_CPU:tu:MSSE}

DEBUG_DESC=	Enable debug support
DYNLOAD_DESC=	Enable dynamic loading of lame and FFmpeg
LAME_DESC=	Use lame for import and export support
LV2_DESC=	Add LV2 plug-in support
MAD_DESC=	Use libmad for mp2/3 decoding support
MIDI_DESC=	Use portSMF for Midi support
SBSMS_DESC=	Use libsbsms for pitch and tempo changing
SOUNDTOUCH_DESC=	Use libSoundTouch for pitch and tempo changing
TAGLIB_DESC=	Use TagLib for metadata support
TWOLAME_DESC=	Use libtwolame for MP2 export support
VAMP_DESC=	Vamp plug-in support
VST_DESC=	VST plug-in support

CONFIGURE_ENV+=	WX_CONFIG="${WX_CONFIG}"

CONFIGURE_ARGS+=	--enable-unicode \
			${ICONV_CONFIGURE_ARG} \
			--with-lib-preference="local" \
			--with-expat=system \
			--with-libsndfile=system \
			--with-libsoxr \
			--with-portaudio \
			--with-midi \
			--with-widgetextra \
			--with-portmixer=yes

CONFIGURE_SHELL?=	${LOCALBASE}/bin/bash

DEBUG_CONFIGURE_WITH=	debug

DOCS_BUILD_DEPENDS=	docbook-to-man:textproc/docbook-to-man \
			docbook2man:textproc/docbook-utils

ALSA_CONFIGURE_OFF=	--disable-alsa
ALSA_CONFIGURE_WITH=	alsa
ALSA_CFLAGS=		-I${LOCALBASE}/include
ALSA_CXXFLAGS=		-I${LOCALBASE}/include
ALSA_LDFLAGS=		-L${LOCALBASE}/lib
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib

DYNLOAD_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libavcodec.pc:multimedia/ffmpeg
DYNLOAD_BUILD_DEPENDS=	${LOCALBASE}/include/lame/lame.h:audio/lame
DYNLOAD_CONFIGURE_ENABLE=	dynamic-loading
DYNLOAD_CPPFLAGS=		-I${LOCALBASE}/include	# for audio/lame using
DYNLOAD_LDFLAGS=		-L${LOCALBASE}/lib	# for audio/lame using

FFMPEG_CONFIGURE_WITH=	ffmpeg=system
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

FLAC_CONFIGURE_WITH=	libflac=system
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac

ID3TAG_CONFIGURE_WITH=	libid3tag=system
ID3TAG_LIB_DEPENDS=	libid3tag.so:audio/libid3tag

JACK_LIB_DEPENDS=	libjack.so:audio/jack

LADSPA_CONFIGURE_ENABLE=	ladspa
LADSPA_RUN_DEPENDS=	listplugins:audio/ladspa

MAD_CONFIGURE_WITH=	libmad=system
MAD_LIB_DEPENDS=	libmad.so:audio/libmad

LAME_CONFIGURE_ON=	--with-lame=system
LAME_CONFIGURE_OFF=	--with-lame	# --without-lame is broken
LAME_CPPFLAGS=		-I${LOCALBASE}/include
LAME_LDFLAGS=		-L${LOCALBASE}/lib
LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame

LV2_CONFIGURE_WITH=	lv2

SBSMS_CONFIGURE_WITH=	sbsms

SOUNDTOUCH_CONFIGURE_WITH=	soundtouch=system
SOUNDTOUCH_LIB_DEPENDS=	libSoundTouch.so:audio/soundtouch

SSE_CONFIGURE_ENABLE=	sse

TWOLAME_CONFIGURE_WITH=	libtwolame=system
TWOLAME_LIB_DEPENDS=	libtwolame.so:audio/twolame

VAMP_CONFIGURE_WITH=	libvamp=system
VAMP_LIB_DEPENDS=	libvamp-hostsdk.so:audio/vamp-plugin-sdk

VORBIS_CONFIGURE_WITH=	libvorbis=system
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis

VST_CONFIGURE_ENABLE=	vst

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-std=c++11
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
