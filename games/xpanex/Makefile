# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xpanex
PORTVERSION=	5.5.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Panex puzzle for X Window System

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		imake
USE_XORG=	x11 xext xt sm ice

PLIST_FILES=	bin/xpanex \
		man/man1/xpanex.1.gz \
		lib/X11/app-defaults/Panex

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xpanex ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Panex.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/Panex
	${INSTALL_MAN} ${WRKSRC}/xpanex.man ${STAGEDIR}${MANPREFIX}/man/man1/xpanex.1

.include <bsd.port.mk>
