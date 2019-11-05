# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xmlink
PORTVERSION=	5.5.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/games/xpuzzles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Missing Link puzzle for X Window System

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		imake xorg
USE_XORG=	x11 xext xt sm ice

PLIST_FILES=	bin/xmlink \
		man/man1/xmlink.1.gz \
		lib/X11/app-defaults/Mlink

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmlink ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Mlink.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/Mlink
	${INSTALL_MAN} ${WRKSRC}/xmlink.man ${STAGEDIR}${MANPREFIX}/man/man1/xmlink.1

.include <bsd.port.mk>
