# New ports collection makefile for:	xquarto
# Version required:			1.0
# Date created:				9 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/03/13 09:32:01 tg Exp $
#

DISTNAME=	xquarto-1.0
CATEGORIES=	games
MASTER_SITES=	http://www.math.kth.se/~mjo/games/xquarto/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
MAN6=		xquarto.6

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/xquarto ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/src/xquarto.man ${PREFIX}/man/man6/xquarto.6

.include <bsd.port.mk>
