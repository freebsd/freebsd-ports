# $FreeBSD$

PORTNAME=	fixc
PORTVERSION=	1.0
CATEGORIES=	finance
MASTER_SITES=	http://github.com/blttll/${PORTNAME}/archive/v${PORTVERSION}.tar.gz?dummy=/
DISTFILES=	v${PORTVERSION}.tar.gz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	blttll@gmail.com
COMMENT=	Simple Financial Information eXchange (FIX) protocol console client

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

PLIST_FILES=	bin/fixc

do-build:
	cd ${WRKSRC} && \
		go build -o fixc main.go

do-install:
	 ${INSTALL_PROGRAM} ${WRKSRC}/fixc ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
