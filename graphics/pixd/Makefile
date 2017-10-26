# $FreeBSD$

PORTNAME=	pixd
PORTVERSION=	g20170531
CATEGORIES=	graphics

MAINTAINER=	mail@dbalan.in
COMMENT=	Visualize binary data in terminal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	FireyFly
GH_TAGNAME=	85c1cb6

ALL_TARGET=	pixd

PLIST_FILES=	bin/pixd \
		man/man1/pixd.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pixd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pixd.1 ${STAGEDIR}${PREFIX}/man/man1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pixd

.include <bsd.port.mk>
