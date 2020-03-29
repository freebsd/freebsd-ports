# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	RetroArch
PORTVERSION=	1.3.6
DISTVERSIONPREFIX=	v
PORTREVISION=	17
CATEGORIES=	games

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Cross-platform entertainment system based on libretro API

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon \
		libdrm.so:graphics/libdrm \
		libass.so:multimedia/libass

BROKEN_powerpc64=	fails to compile: features_cpu.c: undefined reference to __mftb

OPTIONS_DEFINE=	FFMPEG OSS JACK PULSEAUDIO ALSA SDL OPENGL OPENAL NETPLAY PYTHON V4L FREETYPE FBO
OPTIONS_DEFAULT=OSS PULSEAUDIO SDL OPENGL OPENAL NETPLAY PYTHON V4L FREETYPE FBO  # FFMPEG
FFMPEG_DESC=	On-the-fly recording of gameplay with libavcodec
NETPLAY_DESC=	Peer-to-peer netplay
PYTHON_DESC=	Script support in shaders
FBO_DESC=	OpenGL render-to-texture

FFMPEG_BROKEN=		fails to build with ffmpeg 4.0
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_ENABLE=ffmpeg
OSS_CONFIGURE_ENABLE=	oss
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=	jack
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa
SDL_USES=		sdl
SDL_USE=		SDL=sdl2 image2
SDL_CONFIGURE_ON=	--disable-sdl --enable-sdl2
SDL_CONFIGURE_OFF=	--disable-sdl --disable-sdl2
OPENGL_USES=		gl
OPENGL_USE=		GL=gl,egl,gbm
OPENGL_CONFIGURE_ENABLE=opengl
OPENAL_USES=		openal:soft
OPENAL_CONFIGURE_ENABLE=al
NETPLAY_CONFIGURE_ENABLE=	netplay
PYTHON_CONFIGURE_ENABLE=python
PYTHON_USES=		python:3.4+
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
V4L_CONFIGURE_ENABLE=	v4l2
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_CONFIGURE_ENABLE=	freetype
FBO_CONFIGURE_ENABLE=	fbo

CFLAGS+=	-pthread
LDFLAGS+=	-pthread
LDFLAGS_i386=	-Wl,-znotext
CONFIGURE_ARGS+=--enable-threads
CONFIGURE_ENV+=	MAN_DIR=${MANPREFIX}/man

USES=		compiler:c++11-lib gmake pkgconfig shebangfix xorg
USE_GITHUB=	yes
GH_ACCOUNT=	libretro
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--global-config-dir=${LOCALBASE}/etc
USE_XORG=	x11 xcb xext xinerama xv xxf86vm
SHEBANG_FILES=	libretro-common/glsym/glgen.py libretro-common/glsym/rglgen.py tools/cg2glsl.py tools/vulkan_loader_generator.py

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/camera/drivers/video4linux2.c \
		${WRKSRC}/gfx/drivers/*.c \
		${WRKSRC}/libretro-common/libco/armeabi.c \
		${WRKSRC}/memory/wii/mem2_manager.c
	@${REINPLACE_CMD} -e 's|<asm/types.h>|<sys/types.h>|' \
		${WRKSRC}/camera/drivers/video4linux2.c
	@${REINPLACE_CMD} -e '/^add_define_make DYLIB_LIB/s|$$|;\
		add_include_dirs ${LOCALBASE}/include;\
		add_library_dirs ${LOCALBASE}/lib| ; \
		/^check_lib OSS_LIB/d' \
		${WRKSRC}/qb/config.libs.sh

post-patch-PYTHON-on:
	@${REINPLACE_CMD} -e '/check_pkgconf PYTHON/s/python3/python-${PYTHON_VER}/' \
		${WRKSRC}/qb/config.libs.sh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/retroarch
	@${REINPLACE_CMD} -e 's|# libretro_directory =|libretro_directory = "${PREFIX}/libexec/libretro"|' \
		${STAGEDIR}${PREFIX}/etc/retroarch.cfg

.include <bsd.port.mk>
