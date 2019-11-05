# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xskat
PORTVERSION=	4.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.xskat.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Play the card game Skat

LICENSE=	unknown
LICENSE_NAME=	xskat license clause
LICENSE_FILE=	${WRKSRC}/README
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		xorg
USE_XORG=	x11
PLIST_FILES=	bin/xskat \
		man/man1/xskat.1.gz \
		man/man1/xskat-de.1.gz

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lX11

post-patch:
	${MV} ${WRKSRC}/xskat.man ${WRKSRC}/xskat.1
	${MV} ${WRKSRC}/xskat-de.man ${WRKSRC}/xskat-de.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xskat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xskat.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/xskat-de.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
