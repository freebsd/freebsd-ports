# Created by: Yuri Victorovich <yuri@rawbw.com>

PORTNAME=	RetroArch
PORTVERSION=	1.10.3
DISTVERSIONPREFIX=	v
CATEGORIES=	games emulators

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Cross-platform entertainment system based on libretro API

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vulkan-loader>0:graphics/vulkan-loader \
		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon \
		libdrm.so:graphics/libdrm \
		libass.so:multimedia/libass \
		libfribidi.so:converters/fribidi \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	retroarch-assets<=0:games/retroarch-assets

USES=		compiler:c++11-lib cpe gmake pkgconfig python:3.6+ shebangfix ssl
CPE_VENDOR=	libretro
USE_GITHUB=	yes
GH_ACCOUNT=	libretro
SHEBANG_FILES=	libretro-common/glsym/glgen.py libretro-common/glsym/rglgen.py \
		tools/cg2glsl.py tools/vulkan_loader_generator.py

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-threads --disable-discord \
		--sysconfdir=${LOCALBASE}/etc
CONFIGURE_ENV+=	MAN_DIR=${MANPREFIX}/man
LDFLAGS_i386=	-Wl,-znotext

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:tl}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	CACA FFMPEG OSS JACK PULSEAUDIO ALSA SDL OPENGL OPENAL V4L FREETYPE WAYLAND UDEV QT X11 DOCS
OPTIONS_DEFAULT=FFMPEG OSS SDL OPENGL OPENAL V4L FREETYPE WAYLAND UDEV QT X11
FFMPEG_DESC=	On-the-fly recording of gameplay with libavcodec
WAYLAND_DESC=	Wayland display support
UDEV_DESC=	udev device hotplug support
QT_DESC=	Qt based desktop-style GUI

CACA_LIB_DEPENDS=	libcaca.so:graphics/libcaca
CACA_CONFIGURE_ENABLE=	caca
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
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
V4L_CONFIGURE_ENABLE=	v4l2
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_CONFIGURE_ENABLE=	freetype
WAYLAND_BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
			${LOCALBASE}/include/linux/kd.h:graphics/svgalib
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland
WAYLAND_CONFIGURE_ENABLE=	wayland
UDEV_LIB_DEPENDS=	libudev.so:devel/libudev-devd \
			libepoll-shim.so:devel/libepoll-shim
UDEV_CFLAGS=		-I${LOCALBASE}/include/libepoll-shim
UDEV_LDFLAGS=		-L${LOCALBASE}/lib -lepoll-shim
UDEV_CONFIGURE_ENABLE=	udev
QT_USES=		qt:5
QT_USE=			QT=core,gui,widgets,concurrent,network
QT_CONFIGURE_ENABLE=	qt
X11_USES=		xorg
X11_USE=		XORG=x11,xcb,xext,xinerama,xv,xxf86vm,xrandr
X11_CONFIGURE_ENABLE=	x11

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/camera/drivers/video4linux2.c \
		${WRKSRC}/libretro-common/libco/armeabi.c \
		${WRKSRC}/memory/wii/mem2_manager.c
	@${REINPLACE_CMD} -e 's|<asm/types.h>|<sys/types.h>|' \
		${WRKSRC}/camera/drivers/video4linux2.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/retroarch
	@${REINPLACE_CMD} \
		-e 's|# libretro_directory =|libretro_directory = "${PREFIX}/lib/libretro"|' \
		-e 's|# libretro_info_path =|libretro_info_path = "${PREFIX}/share/libretro/info"|' \
		-e 's|# assets_directory =|assets_directory = "${PREFIX}/share/libretro/assets"|' \
		-e 's|# video_shader_dir =|video_shader_dir = "${PREFIX}/share/libretro/shaders"|' \
		-e 's|# video_filter_dir =|video_filter_dir = "${PREFIX}/lib/retroarch/filters/video"|' \
		-e 's|# audio_filter_dir =|audio_filter_dir = "${PREFIX}/lib/retroarch/filters/audio"|' \
		-e 's|# joypad_autoconfig_dir =|joypad_autoconfig_dir = "${PREFIX}/share/retroarch/autoconfig"|' \
		-e 's|# menu_show_core_updater = true|menu_show_core_updater = false|' \
		${STAGEDIR}${PREFIX}/etc/retroarch.cfg

.include <bsd.port.mk>
