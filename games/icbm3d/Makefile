# New ports collection makefile for:	icbm3d
# Version required:			0.3
# Date created:				20 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/03/28 15:22:36 steve Exp $
#

DISTNAME=	icbm3d.0.3
PKGNAME=	icbm3d-0.3
CATEGORIES=	games
MASTER_SITES=	http://zippy.sonoma.edu/kendrick/nbs/unix/x/icbm3d/

MAINTAINER=	andy@icc.surw.chel.su

MAKEFILE=	makefile
USE_X11=	yes
WRKSRC=		${WRKDIR}/icbm3d

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/icbm3d ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/doc/icbm3d
	@ ${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/icbm3d

.include <bsd.port.mk>
