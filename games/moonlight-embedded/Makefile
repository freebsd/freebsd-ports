PORTNAME=	moonlight-embedded
DISTVERSION=	2.7.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	https://github.com/moonlight-stream/moonlight-embedded/releases/download/v${DISTVERSION}/

MAINTAINER=	lisp_25689@163.com
COMMENT=	Gamestream client
WWW=		https://github.com/moonlight-stream/moonlight-embedded

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
		libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl \
		libepoll-shim.so:devel/libepoll-shim \
		libevdev.so:devel/libevdev \
		libexpat.so:textproc/expat2 \
		libopus.so:audio/opus \
		libudev.so:devel/libudev-devd \
		libuuid.so:misc/libuuid

USES=		cmake localbase:ldflags perl5 pkgconfig sdl ssl tar:xz
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_SDL=	sdl2

NO_WRKSUBDIR=	yes
CFLAGS+=	-DHAS_SOCKLEN_T=1 -I${LOCALBASE}/include/libepoll-shim/
LDFLAGS+=	-lepoll-shim
CONFLICTS_INSTALL=	moonlight-embedded-devel

PLIST_FILES=	bin/moonlight \
		"@sample etc/moonlight.conf.sample" \
		share/man/man1/moonlight.1.gz \
		share/moonlight/gamecontrollerdb.txt

OPTIONS_DEFAULT=	OSS X11
OSS_DESC=	Open Sound System support for embedded(not SDL) platform
PULSE_DESC=	PulseAudio sound server support for embedded(not SDL) platform
CEC_DESC=	Enable HDMI-CEC(TV controller) feature by using libcec.so
X11_DESC=	Enable x11 and x11_vaapi platform using xorg
OPTIONS_SINGLE=	SOUND
OPTIONS_SINGLE_SOUND=	OSS PULSE
OPTIONS_GROUP=	DISPLAY OTHERS
OPTIONS_GROUP_OTHERS=	CEC
OPTIONS_GROUP_DISPLAY=	X11
OSS_CMAKE_ON=	-DENABLE_PULSE:BOOL=false
PULSE_CMAKE_BOOL=	ENABLE_PULSE
PULSE_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
CEC_CMAKE_BOOL=	ENABLE_CEC
CEC_LIB_DEPENDS=	libcec.so:multimedia/libcec \
			libp8-platform.so:devel/p8-platform
X11_USES=	xorg gl
X11_USE=	xorg=x11 gl=egl,glesv2
X11_CMAKE_BOOL=	ENABLE_X11
X11_LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau \
			libva.so:multimedia/libva

post-extract:
	@${REINPLACE_CMD} -e 's|/etc/moonlight/|${PREFIX}/etc/moonlight/|g' \
		${WRKSRC}/docs/README.pod
	@${REINPLACE_CMD} -e 's@/usr/local@${PREFIX}@' \
		-e 's@/etc@${PREFIX}/etc@' \
		${WRKSRC}/src/config.c

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/moonlight.conf \
		${STAGEDIR}${PREFIX}/etc/moonlight.conf.sample

.include <bsd.port.mk>
