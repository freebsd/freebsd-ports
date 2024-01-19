PORTNAME=	xmball
PORTVERSION=	5.5.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/games/xpuzzles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Masterball puzzle for X Window System
WWW=		http://www.tux.org/~bagleyd/puzzles.html

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		imake xorg
USE_XORG=	x11 xext xt sm ice

PLIST_FILES=	bin/xmball \
		share/man/man1/xmball.1.gz \
		lib/X11/app-defaults/Mball

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmball ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Mball.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/Mball
	${INSTALL_MAN} ${WRKSRC}/xmball.man ${STAGEDIR}${PREFIX}/share/man/man1/xmball.1

.include <bsd.port.mk>
