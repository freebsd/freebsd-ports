PORTNAME=	moonlight-embedded
DISTVERSION=	2.6.2
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
		libuuid.so:misc/e2fsprogs-libuuid \
		libvdpau.so:multimedia/libvdpau \
		libva.so:multimedia/libva

USES=		cmake gl localbase:ldflags perl5 pkgconfig sdl ssl tar:xz xorg
USE_LDCONFIG=	yes
USE_GL=		egl glesv2
USE_PERL5=	build
USE_SDL=	sdl2
USE_XORG=	x11

NO_WRKSUBDIR=	yes
CFLAGS+=	-DHAS_SOCKLEN_T=1 -I${LOCALBASE}/include/libepoll-shim/
LDFLAGS+=	-lepoll-shim
CMAKE_OFF=	ENABLE_CEC ENABLE_PULSE
CMAKE_ON=	ENET_NO_INSTALL

PLIST_FILES=	bin/moonlight \
		"@sample etc/moonlight.conf.sample" \
		share/man/man1/moonlight.1.gz \
		share/moonlight/gamecontrollerdb.txt

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
