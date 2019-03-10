# Created by: Marc van Woerkom <3d@FreeBSD.org>
# $FreeBSD$

PORTNAME=	audacity
PORTVERSION=	2.3.1
DISTVERSIONPREFIX=	Audacity-
CATEGORIES=	audio

MAINTAINER=	xxjack12xx@gmail.com
COMMENT=	GUI editor for digital audio waveforms

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_aarch64=		fails to configure: checking whether C++ compiler accepts -msse... no
BROKEN_powerpc64=	fails to build

BUILD_DEPENDS=	autogen:devel/autogen \
		bash:shells/bash \
		cmake:devel/cmake
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libexpat.so:textproc/expat2 \
		libportaudio.so:audio/portaudio \
		libsoxr.so:audio/libsoxr \
		libsndfile.so:audio/libsndfile

USES=		autoreconf compiler:c++11-lib cpe desktop-file-utils dos2unix \
		gettext-tools gmake gnome iconv libtool localbase pkgconfig \
		shared-mime-info shebangfix
GNU_CONFIGURE=	yes
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
NLS_CONFIGURE_WITH=	libintl-prefix="${LOCALBASE}"
OPTIONS_SUB=	yes
USE_WX=		3.1+
WX_COMPS=	wx
INSTALLS_ICONS=	yes
PORTDOCS=	README.txt
DOS2UNIX_GLOB=	Makefile.* *.c* *.h
SHEBANG_FILES=	lib-src/lv2/build
USE_GITHUB=	yes

OPTIONS_DEFINE=	DEBUG DOCS DYNLOAD FFMPEG FLAC ID3TAG LADSPA LAME LV2 MAD \
		MOD_NYQ_BENCH MOD_SCRIPT_PIPE NLS SBSMS SOUNDTOUCH STATIC_WX \
		TWOLAME VAMP VORBIS VST
OPTIONS_DEFAULT=	FLAC ID3TAG LADSPA MAD \
			SBSMS SOUNDTOUCH TWOLAME VAMP VORBIS VST

OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFAULT_amd64=	SSE
OPTIONS_DEFAULT_i386=	${MACHINE_CPU:tu:MSSE}

DYNLOAD_DESC=	Enable dynamic loading of lame and FFmpeg
LAME_DESC=	Use lame for import and export support
LV2_DESC=	Add LV2 plug-in support
MAD_DESC=	Use libmad for mp2/3 decoding support
MOD_SCRIPT_PIPE_DESC=	mod-script-pipe scripting support
MOD_NYQ_BENCH_DESC=	Enable Nyquist Workbench
SBSMS_DESC=	Use libsbsms for pitch and tempo changing
SOUNDTOUCH_DESC=	Use libSoundTouch for pitch and tempo changing
STATIC_WX_DESC=	Link wx statically
TAGLIB_DESC=	Use TagLib for metadata support
TWOLAME_DESC=	Use libtwolame for MP2 export support
VAMP_DESC=	Vamp plug-in support
VST_DESC=	VST plug-in support

CONFIGURE_ENV+=	WX_CONFIG="${WX_CONFIG}"

CONFIGURE_ARGS+=	--disable-option-checking \
			--enable-unicode \
			${ICONV_CONFIGURE_ARG} \
			--with-lib-preference="local" \
			--with-expat=system \
			--with-libsndfile=system \
			--with-libsoxr=system \
			--with-midi \
			--with-portaudio=system \
			--with-portmixer=yes \
			--with-widgetextra

CONFIGURE_SHELL?=	${LOCALBASE}/bin/bash

DEBUG_CONFIGURE_WITH=	debug

DOCS_BUILD_DEPENDS=	docbook-to-man:textproc/docbook-to-man \
			docbook2man:textproc/docbook-utils

DYNLOAD_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libavcodec.pc:multimedia/ffmpeg \
			${LOCALBASE}/include/lame/lame.h:audio/lame
DYNLOAD_CONFIGURE_ENABLE=	dynamic-loading
DYNLOAD_CPPFLAGS=		-I${LOCALBASE}/include	# for audio/lame
DYNLOAD_LDFLAGS=		-L${LOCALBASE}/lib	# for audio/lame

FFMPEG_CONFIGURE_WITH=	ffmpeg=system
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

FLAC_CONFIGURE_WITH=	libflac=system
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac

ID3TAG_CONFIGURE_WITH=	libid3tag=system
ID3TAG_LIB_DEPENDS=	libid3tag.so:audio/libid3tag

JACK_LIB_DEPENDS=	libjack.so:audio/jack

LADSPA_CONFIGURE_ENABLE=	ladspa
LADSPA_RUN_DEPENDS=	listplugins:audio/ladspa

LAME_CONFIGURE_ON=	--with-lame=system
LAME_CONFIGURE_OFF=	--with-lame	# --without-lame is broken
LAME_CPPFLAGS=		-I${LOCALBASE}/include
LAME_LDFLAGS=		-L${LOCALBASE}/lib
LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame

LV2_CONFIGURE_WITH=	lv2=system
LV2_LIB_DEPENDS=	liblilv-0.so:audio/lilv \
			libsuil-0.so:audio/suil

MAD_CONFIGURE_WITH=	libmad=system
MAD_LIB_DEPENDS=	libmad.so:audio/libmad

MOD_SCRIPT_PIPE_CONFIGURE_WITH=	mod-script-pipe
MOD_SCRIPT_PIPE_USES=	python:3.6+
MOD_NYQ_BENCH_CONFIGURE_WITH=	mod-nyq-bench
MOD_NYQ_BENCH_USES=	python:3.6+

SBSMS_CONFIGURE_WITH=	sbsms

SOUNDTOUCH_CONFIGURE_WITH=	soundtouch=system
SOUNDTOUCH_LIB_DEPENDS=	libSoundTouch.so:audio/soundtouch

SSE_CONFIGURE_ENABLE=	sse

STATIC_WX_ENABLE=	static-wx

TWOLAME_CONFIGURE_WITH=	libtwolame=system
TWOLAME_LIB_DEPENDS=	libtwolame.so:audio/twolame

VAMP_CONFIGURE_WITH=	libvamp=system
VAMP_LIB_DEPENDS=	libvamp-hostsdk.so:audio/vamp-plugin-sdk

VORBIS_CONFIGURE_WITH=	libvorbis=system
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libogg.so:audio/libogg

VST_CONFIGURE_ENABLE=	vst

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${RM} ${STAGEDIR}${DOCSDIR}/LICENSE.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
