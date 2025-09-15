PORTNAME=	RetroArch
DISTVERSIONPREFIX=	v
DISTVERSION=	1.21.0
CATEGORIES=	games emulators

MAINTAINER=	dmenelkir@gmail.com
COMMENT=	Cross-platform entertainment system based on libretro API
WWW=		https://github.com/libretro/RetroArch

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
		vulkan-loader>0:graphics/vulkan-loader
LIB_DEPENDS=	libass.so:multimedia/libass \
		libdrm.so:graphics/libdrm \
		libfontconfig.so:x11-fonts/fontconfig \
		libfribidi.so:converters/fribidi \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	retroarch-assets>0:games/retroarch-assets \
		libretro-core-info>0:games/libretro-core-info

USES=		compiler:c++11-lib cpe gmake pkgconfig python shebangfix ssl
CPE_VENDOR=	libretro
USE_GITHUB=	yes
GH_ACCOUNT=	libretro

SHEBANG_FILES=	libretro-common/glsym/glgen.py libretro-common/glsym/rglgen.py \
		tools/cg2glsl.py tools/vulkan_loader_generator.py

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-discord \
			--enable-threads \
			--sysconfdir=${LOCALBASE}/etc
CONFIGURE_ENV+=		MAN_DIR=${PREFIX}/share/man

LDFLAGS_i386=	-Wl,-znotext

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:tl}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=		ALSA CACA DOCS FFMPEG FREETYPE JACK OPENAL OPENGL OSS \
			PIPEWIRE PULSEAUDIO QT SDL UDEV V4L X11
OPTIONS_DEFINE_amd64=	WAYLAND # svgalib is x86 only
OPTIONS_DEFINE_i386=	WAYLAND
OPTIONS_DEFAULT=	FFMPEG FREETYPE OPENAL OPENGL OSS QT SDL UDEV V4L X11
OPTIONS_DEFAULT_amd64=	WAYLAND
OPTIONS_DEFAULT_i386=	WAYLAND

FFMPEG_DESC=	On-the-fly recording of gameplay with libavcodec
QT_DESC=	Qt based desktop-style GUI
UDEV_DESC=	udev device hotplug support
WAYLAND_DESC=	Wayland display support

ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=		alsa
CACA_LIB_DEPENDS=		libcaca.so:graphics/libcaca
CACA_CONFIGURE_ENABLE=		caca
FFMPEG_LIB_DEPENDS=		libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_ENABLE=	ffmpeg
FREETYPE_LIB_DEPENDS=		libfreetype.so:print/freetype2
FREETYPE_CONFIGURE_ENABLE=	freetype
JACK_LIB_DEPENDS=		libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=		jack
OPENAL_USES=			openal:soft
OPENAL_CONFIGURE_ENABLE=	al
OPENGL_USES=			gl
OPENGL_USE=			GL=egl,gbm,gl
OPENGL_CONFIGURE_ENABLE=	opengl
OSS_CONFIGURE_ENABLE=		oss
PIPEWIRE_LIB_DEPENDS=		libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_CONFIGURE_ENABLE=	pipewire
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse
QT_USES=			qt:6
QT_USE=				QT=base
QT_CONFIGURE_ENABLE=		qt
SDL_USES=			sdl
SDL_USE=			image2 \
				SDL=sdl2
SDL_CONFIGURE_ON=		--disable-sdl \
				--enable-sdl2
SDL_CONFIGURE_OFF=		--disable-sdl \
				--disable-sdl2
UDEV_LIB_DEPENDS=		libepoll-shim.so:devel/libepoll-shim \
				libudev.so:devel/libudev-devd
UDEV_CONFIGURE_ENABLE=		udev
UDEV_CFLAGS=			-I${LOCALBASE}/include/libepoll-shim
UDEV_LDFLAGS=			-L${LOCALBASE}/lib -lepoll-shim
V4L_BUILD_DEPENDS=		v4l_compat>0:multimedia/v4l_compat
V4L_LIB_DEPENDS=		libv4l2.so:multimedia/libv4l
V4L_CONFIGURE_ENABLE=		v4l2
WAYLAND_CATEGORIES=		wayland
WAYLAND_BUILD_DEPENDS=		${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
				${LOCALBASE}/include/linux/kd.h:graphics/svgalib
WAYLAND_LIB_DEPENDS=		libwayland-egl.so:graphics/wayland
WAYLAND_CONFIGURE_ENABLE=	wayland
X11_USES=			xorg
X11_USE=			XORG=x11,xcb,xext,xi,xinerama,xrandr,xscrnsaver,xv,xxf86vm
X11_CONFIGURE_ENABLE=		x11

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
	@${RM} ${STAGEDIR}${PREFIX}/etc/retroarch.cfg.bak
	@${MV} ${STAGEDIR}${PREFIX}/etc/retroarch.cfg ${STAGEDIR}${PREFIX}/etc/retroarch.cfg.sample

.include <bsd.port.mk>
