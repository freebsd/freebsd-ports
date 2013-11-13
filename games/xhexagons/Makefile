# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xhexagons
PORTVERSION=	5.5.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hexagons puzzle (similar to Fifteen Puzzle) for X Window System

WRKSRC=		${WRKDIR}/xhexagons
USES=		imake
USE_XORG=	x11 xext xt sm ice

PLIST_FILES=	bin/xhexagons \
		man/man1/xhexagons.1.gz \
		lib/X11/app-defaults/Hexagons

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xhexagons ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Hexagons.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/Hexagons
	${INSTALL_MAN} ${WRKSRC}/xhexagons.man ${STAGEDIR}${PREFIX}/man/man1/xhexagons.1

.include <bsd.port.mk>
