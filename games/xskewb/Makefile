# New ports collection makefile for:	xskewb
# Date created:				25 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xskewb
PORTVERSION=	5.5.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Skewb puzzle (similar to Rubik's Cube) for X Window

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_IMAKE=	yes
MAN1=		xskewb.1
MANCOMPRESSED=	no
XFREE86_HTML_MAN=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xskewb ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Skewb.ad ${PREFIX}/lib/X11/app-defaults/Skewb
	${INSTALL_MAN} ${WRKSRC}/xskewb.man ${MANPREFIX}/man/man1/xskewb.1

.include <bsd.port.mk>
