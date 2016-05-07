# Created by: hrkfrd@googlemail.com
# $FreeBSD$

PORTNAME=	mpdas
PORTVERSION=	0.4.1
CATEGORIES=	audio
MASTER_SITES=	http://50hz.ws/mpdas/

MAINTAINER=	henrik@affekt.org
COMMENT=	MPD AudioScrobbler written in C++ supporting the latest protocol

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libmpdclient.so:audio/libmpdclient

USES=		pkgconfig

USE_RC_SUBR=	mpdas

SUB_FILES=	pkg-message

PLIST_FILES=	bin/mpdas \
		man/man1/mpdas.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpdas ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mpdas.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
