PORTNAME=	moonlight-embedded
DISTVERSION=	2.5.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://github.com/irtimmer/moonlight-embedded/releases/download/v${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gamestream client
WWW=		https://github.com/irtimmer/moonlight-embedded

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
		libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl \
		libenet.so:net/enet \
		libexpat.so:textproc/expat2 \
		libevdev.so:devel/libevdev \
		libopus.so:audio/opus \
		libudev.so:devel/libudev-devd \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		cmake localbase:ldflags perl5 pkgconfig sdl ssl tar:xz
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_SDL=	sdl2

NO_WRKSUBDIR=	yes
CFLAGS+=	-DHAS_SOCKLEN_T=1 -I${LOCALBASE}/include/libepoll-shim/
LDFLAGS+=	-lepoll-shim

post-patch:
	@${REINPLACE_CMD} -e '/(ALSA)/d' \
		-e '/libpulse-simple/d' \
		-e '/libcec/d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's@SHARED@STATIC@' \
		-e 's@OpenSSL 1.0.2@OpenSSL@' -e '/^install(/d' \
		${WRKSRC}/libgamestream/CMakeLists.txt
	@${REINPLACE_CMD} -e 's@/etc/moonlight/moonlight.conf@${PREFIX}/etc/moonlight.conf@' \
		-e 's@moonligt@moonlight@g' \
		${WRKSRC}/docs/README.pod

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/moonlight.conf \
		${STAGEDIR}${PREFIX}/etc/moonlight.conf.sample

.include <bsd.port.mk>
