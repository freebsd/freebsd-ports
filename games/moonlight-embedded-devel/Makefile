PORTNAME=	moonlight-embedded-devel
DISTVERSION=	2.7.5
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
USE_GL=		egl gbm glesv2
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_SDL=	sdl2
USE_XORG=	x11

CMAKE_ARGS=	-DCMAKE_INSTALL_SYSCONFDIR=${PREFIX}/etc/moonlight

CFLAGS+=	-DHAS_SOCKLEN_T=1 -I${LOCALBASE}/include/libepoll-shim
LDFLAGS+=	-lepoll-shim

CONFLICTS_INSTALL=	moonlight-embedded

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/moonlight \
		"@sample etc/moonlight/moonlight.conf.sample" \
		share/man/man1/moonlight.1.gz \
		share/moonlight/gamecontrollerdb.txt

OPTIONS_DEFAULT=	OSS
OPTIONS_GROUP=		OTHERS
OPTIONS_GROUP_OTHERS=	CEC
OPTIONS_SINGLE=		SOUND
OPTIONS_SINGLE_SOUND=	OSS PULSE

CEC_DESC=	Enable HDMI-CEC(TV controller) feature by using libcec.so
OSS_DESC=	Open Sound System support for embedded(not SDL) platform
PULSE_DESC=	PulseAudio sound server support for embedded(not SDL) platform

CEC_LIB_DEPENDS=	libcec.so:multimedia/libcec \
			libp8-platform.so:devel/p8-platform
CEC_CMAKE_BOOL=		ENABLE_CEC
OSS_CMAKE_ON=		-DENABLE_PULSE:BOOL=false
PULSE_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSE_CMAKE_BOOL=	ENABLE_PULSE

post-extract:
	@${REINPLACE_CMD} -e 's@/usr/local@${PREFIX}@' \
		${WRKSRC}/docs/README.pod \
		${WRKSRC}/src/config.c

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/moonlight/moonlight.conf \
		${STAGEDIR}${PREFIX}/etc/moonlight/moonlight.conf.sample

.include <bsd.port.mk>
