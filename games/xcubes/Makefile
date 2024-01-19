PORTNAME=	xcubes
PORTVERSION=	5.5.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/games/xpuzzles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cube puzzle for X11
WWW=		http://www.tux.org/~bagleyd/puzzles.html

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		imake xorg
USE_XORG=	x11 xext xt sm ice

PLIST_FILES=	bin/xcubes \
		share/man/man1/xcubes.1.gz \
		lib/X11/app-defaults/Cubes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xcubes ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Cubes.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/Cubes
	${INSTALL_MAN} ${WRKSRC}/xcubes.man ${STAGEDIR}${PREFIX}/share/man/man1/xcubes.1

.include <bsd.port.mk>
