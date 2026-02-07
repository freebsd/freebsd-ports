PORTNAME=	xrubik
PORTVERSION=	5.5.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/games/xpuzzles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X-based rubik's cube(tm)
WWW=		http://www.tux.org/~bagleyd/puzzles.html

WRKSRC=		${WRKDIR}/xrubik
USES=		imake xorg
USE_XORG=	xt sm ice xext x11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrubik ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/Rubik.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/Rubik
	${INSTALL_MAN} ${WRKSRC}/xrubik.man ${STAGEDIR}${PREFIX}/share/man/man1/xrubik.1

.include <bsd.port.mk>
