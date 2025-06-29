PORTNAME=	moonlight-embedded-devel
DISTVERSION=	2.7.4
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	https://github.com/armin-25689/moonlight-embedded/releases/download/v${DISTVERSION}/

MAINTAINER=	lisp_25689@163.com
COMMENT=	Command-line moonlight implementation with keyboard-grabbing support
WWW=		https://github.com/moonlight-stream/moonlight-embedded

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		${LOCALBASE}/share/wayland-protocols/stable/xdg-shell/xdg-shell.xml:graphics/wayland-protocols
LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
		libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl \
		libepoll-shim.so:devel/libepoll-shim \
		libevdev.so:devel/libevdev \
		libexpat.so:textproc/expat2 \
		libopus.so:audio/opus \
		libudev.so:devel/libudev-devd \
		libuuid.so:misc/libuuid \
		libva.so:multimedia/libva \
		libdrm.so:graphics/libdrm \
		libwayland-client.so:graphics/wayland

USES=		cmake gl localbase:ldflags perl5 pkgconfig sdl ssl tar:xz xorg
USE_LDCONFIG=	yes
USE_GL=		egl gbm glesv2
USE_PERL5=	build
USE_SDL=	sdl2
USE_XORG=	x11

NO_WRKSUBDIR=	yes
CFLAGS+=	-DHAS_SOCKLEN_T=1 -I${LOCALBASE}/include/libepoll-shim
LDFLAGS+=	-lepoll-shim
CMAKE_ARGS=	-DCMAKE_INSTALL_SYSCONFDIR=${PREFIX}/etc/moonlight

CONFLICTS_INSTALL=	moonlight-embedded

PLIST_FILES=	bin/moonlight \
		"@sample etc/moonlight/moonlight.conf.sample" \
		share/man/man1/moonlight.1.gz \
		share/moonlight/gamecontrollerdb.txt

OPTIONS_DEFAULT=	OSS
CEC_DESC=	Enable HDMI-CEC(TV controller) feature by using libcec.so
OSS_DESC=	Open Sound System support for embedded(not SDL) platform
PULSE_DESC=	PulseAudio sound server support for embedded(not SDL) platform
OPTIONS_GROUP=	OTHERS
OPTIONS_GROUP_OTHERS=	CEC
OPTIONS_SINGLE=	SOUND
OPTIONS_SINGLE_SOUND=	OSS PULSE
CEC_CMAKE_BOOL=	ENABLE_CEC
CEC_LIB_DEPENDS=	libcec.so:multimedia/libcec \
			libp8-platform.so:devel/p8-platform
OSS_CMAKE_ON=	-DENABLE_PULSE:BOOL=false
PULSE_CMAKE_BOOL=	ENABLE_PULSE
PULSE_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

post-extract:
	@${REINPLACE_CMD} -e 's@/usr/local@${PREFIX}@' \
		${WRKSRC}/docs/README.pod
	@${REINPLACE_CMD} -e 's@/usr/local@${PREFIX}@' \
		${WRKSRC}/src/config.c

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/moonlight/moonlight.conf \
		${STAGEDIR}${PREFIX}/etc/moonlight/moonlight.conf.sample

.include <bsd.port.mk>
