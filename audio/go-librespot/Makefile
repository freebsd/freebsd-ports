PORTNAME=	go-librespot
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.3
CATEGORIES=	audio

MAINTAINER=	ale@biancalanas.net
COMMENT=	Yet another open-source Spotify Connect client, written in Go
WWW=		https://github.com/devgianlu/go-librespot

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libogg.so:audio/libogg \
		libasound.so:audio/alsa-lib \
		libvorbis.so:audio/libvorbis \
		libFLAC.so:audio/flac

USES=		go:modules pkgconfig
USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	github.com/devgianlu/go-librespot

GO_TARGET=	./cmd/daemon:${PREFIX}/bin/go-librespot
GO_BUILDFLAGS=	-ldflags "\
		-X github.com/devgianlu/go-librespot.version=${DISTVERSION} \
		-X github.com/devgianlu/go-librespot.commit=ab178ff"

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/config.yml ${STAGEDIR}${ETCDIR}/config.yml.sample

.include <bsd.port.mk>
