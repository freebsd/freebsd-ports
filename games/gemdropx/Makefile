# New ports collection makefile for:	gemdropx
# Version required:			1.0b3
# Date created:				9 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1998/07/27 23:24:38 asami Exp $
#

DISTNAME=	gemdropx
PKGNAME=	gemdropx-1.0b3
CATEGORIES=	games
MASTER_SITES=	http://zippy.sonoma.edu/kendrick/nbs/unix/x/gemdropx/

MAINTAINER=	andy@icc.surw.chel.su

MAKEFILE=	makefile
USE_X_PREFIX=	yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/gemdropx ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/gemdropx/gfx
	@ ${INSTALL_DATA} ${WRKSRC}/gfx/*.xbm ${PREFIX}/share/gemdropx/gfx
	@ ${MKDIR} ${PREFIX}/share/gemdropx/sounds
	@ ${INSTALL_DATA} ${WRKSRC}/sounds/*.au ${PREFIX}/share/gemdropx/sounds
	@ ${MKDIR} ${PREFIX}/share/doc/gemdropx
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gemdropx

.include <bsd.port.mk>
