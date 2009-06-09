# New ports collection makefile for:	xmlink
# Date created:				19 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xmlink
PORTVERSION=	5.5.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Missing Link puzzle for X Window System

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_IMAKE=	yes
USE_XORG=	x11 xext xt sm ice
MAN1=		xmlink.1
MANCOMPRESSED=	no
XFREE86_HTML_MAN=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmlink ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Mlink.ad ${PREFIX}/lib/X11/app-defaults/Mlink
	${INSTALL_MAN} ${WRKSRC}/xmlink.man ${MANPREFIX}/man/man1/xmlink.1

.include <bsd.port.mk>
