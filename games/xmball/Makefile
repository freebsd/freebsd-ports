# New ports collection makefile for:	xmball
# Date created:				21 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xmball
PORTVERSION=	5.5.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/xmball
USE_IMAKE=	yes
MAN1=		xmball.1
MANCOMPRESSED=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmball ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Mball.ad ${PREFIX}/lib/X11/app-defaults/Mball
	${INSTALL_MAN} ${WRKSRC}/xmball.man ${PREFIX}/man/man1/xmball.1

.include <bsd.port.mk>
