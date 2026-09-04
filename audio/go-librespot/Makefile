PORTNAME=	go-librespot
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	audio

MAINTAINER=	ale@biancalanas.net
COMMENT=	Yet another open-source Spotify Connect client, written in Go
WWW=		https://github.com/devgianlu/go-librespot

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libFLAC.so:audio/flac \
		libmpg123.so:audio/mpg123 \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis

USES=		go:modules pkgconfig
USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	github.com/devgianlu/go-librespot

GO_TARGET=	./cmd/daemon:${PREFIX}/bin/go-librespot
GO_BUILDFLAGS=	-ldflags "-X github.com/devgianlu/go-librespot.version=${DISTVERSION}"

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/config.yml ${STAGEDIR}${ETCDIR}/config.yml.sample

.include <bsd.port.mk>
