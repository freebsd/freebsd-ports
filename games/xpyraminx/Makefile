# New ports collection makefile for:	xpyraminx
# Version required:			5.5.2
# Date created:				26 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	xpyraminx-5.5.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/xpyraminx
USE_IMAKE=	yes
MAN1=		xpyraminx.1
MANCOMPRESSED=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xpyraminx ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Pyraminx.ad ${PREFIX}/lib/X11/app-defaults/Pyraminx
	${INSTALL_MAN} ${WRKSRC}/xpyraminx.man ${PREFIX}/man/man1/xpyraminx.1

.include <bsd.port.mk>
