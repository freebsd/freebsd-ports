# New ports collection makefile for:	gemdropx
# Version required:			1.0b3
# Date created:				9 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=	gemdropx
PKGNAME=	gemdropx-1.0b3
CATEGORIES=	games x11
MASTER_SITES=	http://zippy.sonoma.edu/kendrick/nbs/unix/x/gemdropx/

MAINTAINER=	andy@icc.surw.chel.su

MAKEFILE=	makefile
USE_X11=	yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/gemdropx ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/gemdropx/gfx
	@ ${INSTALL_DATA} ${WRKSRC}/gfx/*.xbm ${PREFIX}/share/gemdropx/gfx
	@ ${MKDIR} ${PREFIX}/share/gemdropx/sounds
	@ ${INSTALL_DATA} ${WRKSRC}/sounds/*.au ${PREFIX}/share/gemdropx/sounds
	@ ${MKDIR} ${PREFIX}/share/doc/gemdropx
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gemdropx

.include <bsd.port.mk>
