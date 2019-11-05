# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xpyraminx
PORTVERSION=	5.5.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/games/xpuzzles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pyraminx puzzle for X Window System

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		imake xorg
USE_XORG=	x11 xext xt sm ice

PLIST_FILES=	bin/xpyraminx \
		lib/X11/app-defaults/Pyraminx \
		man/man1/xpyraminx.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xpyraminx ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Pyraminx.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/Pyraminx
	${INSTALL_MAN} ${WRKSRC}/xpyraminx.man ${STAGEDIR}${MANPREFIX}/man/man1/xpyraminx.1

.include <bsd.port.mk>
