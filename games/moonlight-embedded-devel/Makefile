PORTNAME=	moonlight-embedded-devel
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.9
CATEGORIES=	games

MAINTAINER=	lisp_25689@163.com
COMMENT=	Command-line moonlight implementation with keyboard-grabbing support
WWW=		https://github.com/armin-25689/moonlight-embedded/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
		libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl \
		libdrm.so:graphics/libdrm \
		libevdev.so:devel/libevdev \
		libexpat.so:textproc/expat2 \
		libopus.so:audio/opus \
		libudev.so:devel/libudev-devd \
		libuuid.so:misc/libuuid \
		libva.so:multimedia/libva

USES=		cmake gl localbase:ldflags perl5 pkgconfig sdl ssl
USE_GITHUB=	yes
GH_ACCOUNT=	armin-25689
GH_PROJECT=	moonlight-embedded
GH_TUPLE=	moonlight-stream:moonlight-common-c:e41355e:moonlight_common_c/third_party/moonlight-common-c \
		cgutman:enet:aca8784:enet/third_party/moonlight-common-c/enet \
		sleepybishop:nanors:b1e3c22:nanors/third_party/moonlight-common-c/nanors \
		gabomdq:SDL_GameControllerDB:8d9fefd:SDL_GameControllerDB/third_party/SDL_GameControllerDB
USE_GL=		egl gbm glesv2
USE_PERL5=	build
USE_SDL=	sdl3

CMAKE_ARGS=	-DCMAKE_INSTALL_SYSCONFDIR=${PREFIX}/etc/moonlight

CONFLICTS_INSTALL=	moonlight-embedded

PLIST_FILES=	bin/moonlight \
		"@sample etc/moonlight/moonlight.conf.sample" \
		share/man/man1/moonlight.1.gz \
		share/moonlight/gamecontrollerdb.txt

OPTIONS_DEFAULT=	LIBYUV OSS WAYLAND X11
OPTIONS_GROUP=		DISPLAY OTHERS
OPTIONS_GROUP_DISPLAY=	WAYLAND X11
OPTIONS_GROUP_OTHERS=	CEC
OPTIONS_SINGLE=		CONVERT SOUND
OPTIONS_SINGLE_CONVERT=	LIBSWSCALE LIBYUV
OPTIONS_SINGLE_SOUND=	OSS PULSEAUDIO

CEC_DESC=		Enable HDMI-CEC(TV controller) feature by using libcec.so
LIBSWSCALE_DESC=	Convert video frame format with libswscale.h
LIBYUV_DESC=		Convert video frame format with libyuv.h

CEC_LIB_DEPENDS=	libcec.so:multimedia/libcec \
			libp8-platform.so:devel/p8-platform
CEC_CMAKE_BOOL=		ENABLE_CEC
LIBSWSCALE_CMAKE_ON=	-DENABLE_YUV:BOOL=false
LIBYUV_LIB_DEPENDS=	libyuv.so:graphics/libyuv
OSS_CMAKE_ON=		-DENABLE_PULSE:BOOL=false
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	ENABLE_PULSE
WAYLAND_BUILD_DEPENDS=	${LOCALBASE}/share/wayland-protocols/stable/xdg-shell/xdg-shell.xml:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_CMAKE_BOOL=	ENABLE_WAYLAND
X11_USES=		xorg
X11_USE=		XORG=x11
X11_CMAKE_BOOL=		ENABLE_X11

post-extract:
	@${REINPLACE_CMD} -e 's@/usr/local@${PREFIX}@' \
		${WRKSRC}/docs/README.pod \
		${WRKSRC}/src/config.c

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/moonlight/moonlight.conf \
		${STAGEDIR}${PREFIX}/etc/moonlight/moonlight.conf.sample

.include <bsd.port.mk>
