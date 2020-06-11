# $FreeBSD$

PORTNAME=	vkquake
DISTVERSION=	1.03.0
CATEGORIES=	games

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Quake 1 port using Vulkan instead of OpenGL, based on QuakeSpasm

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:devel/vulkan-headers
LIB_DEPENDS=	libX11-xcb.so:x11/libX11 \
		libvulkan.so:graphics/vulkan-loader

WRKSRC_SUBDIR=	Quake

USES=		desktop-file-utils gmake gnome pkgconfig sdl
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	Novum
GH_PROJECT=	vkQuake

INSTALLS_ICONS=	yes

MAKE_ENV=	prefix=${PREFIX} bindir=${PREFIX}/bin VULKAN_SDK=${LOCALBASE}
ALL_TARGET=	# empty

.include	"${.CURDIR}/../quake-data/Makefile.include"

CFLAGS+=	-DDATADIR='\"${Q1DIR}\"'

OPTIONS_DEFINE=			USERDIRS WAVE FLAC MP3 VORBIS # OPUS
OPTIONS_RADIO=			MODPLAYER
OPTIONS_RADIO_MODPLAYER=	MIKMOD XMP MODPLUG
OPTIONS_DEFAULT=		USERDIRS WAVE FLAC VORBIS MODPLUG # OPUS MODPLUG

USERDIRS_DESC=	Enable support for loading game files from user directories (~/.vkquake)
WAVE_DESC=	Enable support for Wave music
FLAC_DESC=	Enable support for FLAC music
MP3_DESC=	Enable support for MP3 music
VORBIS_DESC=	Enable support for Ogg Vorbis music
# OPUS_DESC=	Enable support for Opus music
MIKMOD_DESC=	Enable support for tracker module music using MikMod
XMP_DESC=	Enable support for tracker module music using XMP
MODPLUG_DESC=	Enable support for tracker module music using ModPlug

USERDIRS_MAKE_ARGS=	DO_USERDIRS=1
USERDIRS_MAKE_ARGS_OFF=	DO_USERDIRS=0

WAVE_MAKE_ARGS=		USE_CODEC_WAVE=1
WAVE_MAKE_ARGS_OFF=	USE_CODEC_WAVE=0

FLAC_MAKE_ARGS=		USE_CODEC_FLAC=1
FLAC_MAKE_ARGS_OFF=	USE_CODEC_FLAC=0
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac

MP3_MAKE_ARGS=		USE_CODEC_MP3=1 MP3LIB=mpg123
MP3_MAKE_ARGS_OFF=	USE_CODEC_MP3=0
MP3_LIB_DEPENDS=	libmpg123.so:audio/mpg123

VORBIS_MAKE_ARGS=	USE_CODEC_VORBIS=1 VORBISLIB=vorbis
VORBIS_MAKE_ARGS_OFF=	USE_CODEC_VORBIS=0
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libvorbisfile.so:audio/libvorbis \
			libogg.so:audio/libogg

# XXX: crashes on start
# OPUS_MAKE_ARGS=		USE_CODEC_OPUS=1
# OPUS_MAKE_ARGS_OFF=	USE_CODEC_OPUS=0
# OPUS_LIB_DEPENDS=	libopus.so:audio/opus \
# 			libopusfile.so:audio/opusfile

MIKMOD_MAKE_ARGS=	USE_CODEC_MIKMOD=1
MIKMOD_MAKE_ARGS_OFF=	USE_CODEC_MIKMOD=0
MIKMOD_LIB_DEPENDS=	libmikmod.so:audio/libmikmod

XMP_MAKE_ARGS=		USE_CODEC_XMP=1
XMP_MAKE_ARGS_OFF=	USE_CODEC_XMP=0
XMP_LIB_DEPENDS=	libxmp.so:audio/xmp

MODPLUG_MAKE_ARGS=	USE_CODEC_MODPLUG=1
MODPLUG_MAKE_ARGS_OFF=	USE_CODEC_MODPLUG=0
MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug

post-install:
	${MKDIR} ${STAGEDIR}${Q1DIR}
	${INSTALL_DATA} ${WRKSRC}/vkquake.pak ${STAGEDIR}${Q1DIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps
	${INSTALL_DATA} ${FILESDIR}/vkquake.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/vkquake.png
	${INSTALL_DATA} ${FILESDIR}/vkquake.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
