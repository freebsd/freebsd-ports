# New ports collection makefile for:	xhexagons
# Date created:				20 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xhexagons
PORTVERSION=	5.5.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hexagons puzzle (similar to Fifteen Puzzle) for X Window System

WRKSRC=		${WRKDIR}/xhexagons
USE_IMAKE=	yes
USE_XORG=	x11 xext xt sm ice
MAN1=		xhexagons.1
XFREE86_HTML_MAN=	no
NO_INSTALL_MANPAGES=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xhexagons ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Hexagons.ad ${PREFIX}/lib/X11/app-defaults/Hexagons
	${INSTALL_MAN} ${WRKSRC}/xhexagons.man ${PREFIX}/man/man1/xhexagons.1

.include <bsd.port.mk>
