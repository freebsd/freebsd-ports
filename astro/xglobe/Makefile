# New ports collection makefile for:   xglobe
# Version required:    0.2
# Date created:        20 January 1998
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $Id$
#

DISTNAME=	xglobe-0.2
CATEGORIES=	astro
MASTER_SITES=	http://www.uni-karlsruhe.de/~uddn/xglobe/

MAINTAINER=	kkennawa@physics.adelaide.edu.au

USE_QT=		yes
USE_X_PREFIX=   yes
USE_GMAKE=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/xglobe/
	@${INSTALL_PROGRAM} ${WRKSRC}/xglobe ${PREFIX}/bin/
	@${INSTALL_DATA} ${WRKSRC}/map.bmp ${PREFIX}/share/xglobe/
	@${INSTALL_DATA} ${WRKSRC}/xglobe-markers ${PREFIX}/share/xglobe/

.include <bsd.port.mk>
