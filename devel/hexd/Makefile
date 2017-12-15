# $FreeBSD$

PORTNAME=	hexd
PORTVERSION=	g20170531
CATEGORIES=	devel

MAINTAINER=	mail@dbalan.in
COMMENT=	Colourful, human-friendly hexdump tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	FireyFly
GH_TAGNAME=	934a506

PLIST_FILES=	bin/hexd \
		man/man1/hexd.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hexd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hexd.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
