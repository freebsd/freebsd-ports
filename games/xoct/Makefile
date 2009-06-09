# New ports collection makefile for:	xoct
# Date created:				28 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xoct
PORTVERSION=	5.5.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Oct puzzle for X Window System

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_IMAKE=	yes
USE_XORG=	x11 xext xt sm ice
MAN1=		xoct.1
MANCOMPRESSED=	no
XFREE86_HTML_MAN=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xoct ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Oct.ad ${PREFIX}/lib/X11/app-defaults/Oct
	${INSTALL_MAN} ${WRKSRC}/xoct.man ${MANPREFIX}/man/man1/xoct.1

.include <bsd.port.mk>
