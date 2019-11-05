# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xoct
PORTVERSION=	5.5.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/games/xpuzzles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Oct puzzle for X Window System

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		imake xorg
USE_XORG=	x11 xext xt sm ice

PLIST_FILES=	bin/xoct \
		lib/X11/app-defaults/Oct \
		man/man1/xoct.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xoct ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Oct.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/Oct
	${INSTALL_MAN} ${WRKSRC}/xoct.man ${STAGEDIR}${MANPREFIX}/man/man1/xoct.1

.include <bsd.port.mk>
