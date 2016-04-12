# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	RetroArch
PORTVERSION=	1.2.2
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	yuri@rawbw.com
COMMENT=	Cross-platform entertainment system based on libretro API

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon \
		libdrm.so:graphics/libdrm

OPTIONS_DEFINE=	FFMPEG OSS JACK PULSEAUDIO ALSA SDL OPENGL OPENAL NETPLAY PYTHON V4L FREETYPE FBO
OPTIONS_DEFAULT=FFMPEG OSS PULSEAUDIO SDL OPENGL OPENAL NETPLAY PYTHON V4L FREETYPE FBO
FFMPEG_DESC=	On-the-fly recording of gameplay with libavcodec
NETPLAY_DESC=	Peer-to-peer netplay
PYTHON_DESC=	Script support in shaders
FBO_DESC=	OpenGL render-to-texture

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_ENABLE=ffmpeg
OSS_CONFIGURE_ENABLE=	oss
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=	jack
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa
SDL_USE=		SDL=sdl2 image2
SDL_CONFIGURE_ON=	--disable-sdl --enable-sdl2
SDL_CONFIGURE_OFF=	--disable-sdl --disable-sdl2
OPENGL_USE=		GL=gl,gbm
OPENGL_CONFIGURE_ENABLE=opengl
OPENAL_USES=		openal:soft
OPENAL_CONFIGURE_ENABLE=al
NETPLAY_CONFIGURE_ENABLE=	netplay
PYTHON_CONFIGURE_ENABLE=python
PYTHON_USES=		python:3
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
V4L_CONFIGURE_ENABLE=	v4l2
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_CONFIGURE_ENABLE=	freetype
FBO_CONFIGURE_ENABLE=	fbo

CFLAGS+=	-pthread
LDFLAGS+=	-pthread
CONFIGURE_ARGS+=--enable-threads

USE_GITHUB=	yes
GH_ACCOUNT=	libretro

SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--global-config-dir=${LOCALBASE}/etc
USES=		compiler:c++11-lib gmake pkgconfig
USE_XORG=	x11 xext xinerama xv xxf86vm

MAN1PAGES=	retroarch-cg2glsl.1 retroarch-joyconfig.1 retroarch.1

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/camera/drivers/video4linux2.c \
		${WRKSRC}/deps/zlib/zutil.h \
		${WRKSRC}/gfx/drivers/*.c \
		${WRKSRC}/libretro-common/formats/png/rpng_decode.c \
		${WRKSRC}/libretro-common/libco/armeabi.c \
		${WRKSRC}/logger/netlogger/psl1ght_logger.c \
		${WRKSRC}/wii/mem2_manager.c
	@${REINPLACE_CMD} -e 's|<asm/types.h>|<sys/types.h>|' \
		${WRKSRC}/camera/drivers/video4linux2.c
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/qb/config.libs.sh

post-install:
	if [ -n "${STRIP}" ]; then \
	        ${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/retroarch; \
	        ${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/retroarch-joyconfig; \
	fi
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/man/man1/retroarch.1
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/man/man1/retroarch-cg2glsl.1
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/man/man1/retroarch-joyconfig.1
	${RM} -rf ${STAGEDIR}${PREFIX}/share/man
	@${REINPLACE_CMD} -e 's|# libretro_directory =|libretro_directory = "${PREFIX}/libexec/libretro"|' \
		${STAGEDIR}${PREFIX}/etc/retroarch.cfg

.include <bsd.port.mk>
