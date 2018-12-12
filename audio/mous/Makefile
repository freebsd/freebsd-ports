# Created by: Yanhui Shen <shen.elf@gmail.com>
# $FreeBSD$

PORTNAME=	mous
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	shen.elf@gmail.com
COMMENT=	Simple yet powerful audio player

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to compile: mmintrin.h:47:5: use of undeclared identifier '__builtin_ia32_emms'; did you mean '__builtin_isless'?

USES=		cmake:outsource compiler:c++14-lang
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	bsdelf

CMAKE_OFF=	WITH_PLUGIN_ALSA \
		WITH_PLUGIN_COREAUDIO \
		WITH_PLUGIN_FAAC \
		WITH_PLUGIN_FAAD \
		WITH_PLUGIN_LIBAO \
		WITH_PLUGIN_WMA

OPTIONS_DEFAULT=	CLI NCURSES LIBCUE TAGLIB FDK_AAC FLAC LAME LIBCUE MAC \
			MPG123 VORBIS WAV WAVPACK OSS
OPTIONS_GROUP=	APPLICATION GENERIC_PLUGIN CODEC_PLUGIN
OPTIONS_GROUP_APPLICATION=	CLI NCURSES QT5
OPTIONS_GROUP_GENERIC_PLUGIN=	LIBCUE TAGLIB
OPTIONS_GROUP_CODEC_PLUGIN=	FDK_AAC FLAC LAME MAC MPG123 VORBIS WAV WAVPACK
OPTIONS_RADIO=	OUTPUT_PLUGIN
OPTIONS_RADIO_OUTPUT_PLUGIN=	OSS SNDIO
OPTIONS_SUB=	yes

APPLICATION_DESC=	Interface support
CLI_DESC=		Command line interface support
CODEC_PLUGIN_DESC=	Codec plugins
FDK_AAC_DESC=		FDK AAC codec support
GENERIC_PLUGIN_DESC=	Generic plugins
LIBCUE_DESC=		CUE sheet support
MAC_DESC=		Monkey's Audio codec support
OUTPUT_PLUGIN_DESC=	Output plugins
TAGLIB_DESC=		TagLib support

CLI_CMAKE_BOOL=		WITH_APP_CLI

FDK_AAC_CMAKE_BOOL=	WITH_PLUGIN_FDK_AAC
FDK_AAC_LIB_DEPENDS=	libfdk-aac.so:audio/fdk-aac \
			libmp4v2.so:multimedia/mp4v2

FLAC_CMAKE_BOOL=	WITH_PLUGIN_FLAC
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac

LAME_CMAKE_BOOL=	WITH_PLUGIN_LAME
LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame

LIBCUE_CMAKE_BOOL=	WITH_PLUGIN_LIBCUE
LIBCUE_LIB_DEPENDS=	libcue.so:textproc/libcue

MAC_CMAKE_BOOL=		WITH_PLUGIN_MAC

MPG123_CMAKE_BOOL=	WITH_PLUGIN_MPG123
MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123

NCURSES_CMAKE_BOOL=	WITH_APP_NCURSES
NCURSES_USE=		ncurses

OSS_CMAKE_BOOL=		WITH_PLUGIN_OSS

QT5_CMAKE_BOOL=		WITH_APP_QT5
QT5_USES=		qt:5
QT5_USE=		qt=buildtools,core,gui,widgets,qmake_build

SNDIO_CMAKE_BOOL=	WITH_PLUGIN_SNDIO
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio

TAGLIB_CMAKE_BOOL=	WITH_PLUGIN_TAGLIB
TAGLIB_LIB_DEPENDS=	libtag.so:audio/taglib

VORBIS_CMAKE_BOOL=	WITH_PLUGIN_OGG_VORBIS
VORBIS_LIB_DEPENDS=	libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis\
			libvorbisenc.so:audio/libvorbis\
			libvorbisfile.so:audio/libvorbis

WAV_CMAKE_BOOL=		WITH_PLUGIN_WAV

WAVPACK_CMAKE_BOOL=	WITH_PLUGIN_WAVPACK
WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack

.include <bsd.port.options.mk>

.if ${ARCH} == i386
# error: always_inline function '_mm_load_si128' requires target feature
# 'mmx', but would be inlined into function 'AdaptSSE' that is compiled
# without support for 'mmx'
post-patch:
	@${REINPLACE_CMD} '/#define ENABLE_SSE_ASSEMBLY/d' \
		${WRKSRC}/deps/MAC_SDK/Shared/All.h \
		${WRKSRC}/deps/MAC_SDK/Source/Shared/All.h
.endif

.include <bsd.port.mk>
