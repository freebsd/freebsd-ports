# $FreeBSD$

PORTNAME=	moonlight-embedded
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.6
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Gamestream client

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl \
		libenet.so:net/enet \
		libexpat.so:textproc/expat2 \
		libopus.so:audio/opus \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		cmake localbase:ldflags perl5 pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	irtimmer
GH_TUPLE=	irtimmer:moonlight-common-c:186cef0e3a4c104dc224f0ca413345571d79b48c:common/third_party/moonlight-common-c
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_SDL=	sdl2

CFLAGS+=	-DPREFIX="\\\"${PREFIX}\\\""

post-patch:
	@${REINPLACE_CMD} -e '/(ALSA)/d' \
		-e '/libpulse-simple/d' \
		-e '/libcec/d' \
		-e '/libevdev/d' -e 's@./src/input/evdev.c@@' \
		-e '/libudev/d' -e 's@./src/input/udev.c@@' \
		-e '/libva/d' \
		-e '/vdpau/d' \
		-e '/egl/d' \
		-e '/glesv2/d' \
		-e '/x11/d' \
		${WRKSRC}/CMakeLists.txt
	@${RM} ${WRKSRC}/src/loop.c
	@${REINPLACE_CMD} -e '/avahi-client/d' -e 's@SHARED@STATIC@' \
		-e 's@OpenSSL 1.0.2@OpenSSL@' -e '/^install(/d' \
		${WRKSRC}/libgamestream/CMakeLists.txt
	@${RM} ${WRKSRC}/libgamestream/discover.c
	@${REINPLACE_CMD} -e 's@/etc/moonlight/moonlight.conf@${PREFIX}/etc/moonlight.conf@' \
		-e 's@moonligt@moonlight@g' \
		${WRKSRC}/docs/README.pod

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/moonlight.conf \
		${STAGEDIR}${PREFIX}/etc/moonlight.conf.sample

.include <bsd.port.mk>
