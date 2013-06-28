# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xpyraminx
PORTVERSION=	5.5.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pyraminx puzzle for X Window System

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		imake
USE_XORG=	x11 xext xt sm ice
MAN1=		xpyraminx.1
MANCOMPRESSED=	no
XFREE86_HTML_MAN=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xpyraminx ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Pyraminx.ad ${PREFIX}/lib/X11/app-defaults/Pyraminx
	${INSTALL_MAN} ${WRKSRC}/xpyraminx.man ${MANPREFIX}/man/man1/xpyraminx.1

.include <bsd.port.mk>
