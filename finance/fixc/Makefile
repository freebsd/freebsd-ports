# $FreeBSD$

PORTNAME=	fixc
PORTVERSION=	1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	finance

MAINTAINER=	blttll@gmail.com
COMMENT=	Simple Financial Information eXchange (FIX) protocol console client

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

PLIST_FILES=	bin/fixc
USE_GITHUB=	yes
GH_ACCOUNT=	blttll

do-build:
	cd ${WRKSRC} && \
		go build -o fixc main.go

do-install:
	 ${INSTALL_PROGRAM} ${WRKSRC}/fixc ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
