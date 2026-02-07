PORTNAME=	moonlight-embedded
DISTVERSION=	2.7.1
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

CFLAGS+=	-DHAS_SOCKLEN_T=1 -I${LOCALBASE}/include/libepoll-shim/
LDFLAGS+=	-lepoll-shim

CONFLICTS_INSTALL=	moonlight-embedded-devel

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/moonlight \
		"@sample etc/moonlight.conf.sample" \
		share/man/man1/moonlight.1.gz \
		share/moonlight/gamecontrollerdb.txt

OPTIONS_DEFAULT=	OSS X11
OPTIONS_GROUP=		DISPLAY OTHERS
OPTIONS_GROUP_DISPLAY=	X11
OPTIONS_GROUP_OTHERS=	CEC
OPTIONS_SINGLE=		SOUND
OPTIONS_SINGLE_SOUND=	OSS PULSE

CEC_DESC=	Enable HDMI-CEC(TV controller) feature by using libcec.so
OSS_DESC=	Open Sound System support for embedded(not SDL) platform
PULSE_DESC=	PulseAudio sound server support for embedded(not SDL) platform
X11_DESC=	Enable x11 and x11_vaapi platform using xorg

CEC_LIB_DEPENDS=	libcec.so:multimedia/libcec \
			libp8-platform.so:devel/p8-platform
CEC_CMAKE_BOOL=		ENABLE_CEC
OSS_CMAKE_ON=		-DENABLE_PULSE:BOOL=false
PULSE_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSE_CMAKE_BOOL=	ENABLE_PULSE
X11_LIB_DEPENDS=	libva.so:multimedia/libva \
			libvdpau.so:multimedia/libvdpau
X11_USES=		gl xorg
X11_USE=		GL=egl,glesv2 \
			XORG=x11
X11_CMAKE_BOOL=		ENABLE_X11

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
