# New ports collection makefile for:	3dpong
# Version required:			0.3
# Date created:				10 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/04/27 03:51:02 mph Exp $
#

DISTNAME=	3dpong.0.3
PKGNAME=	3dpong-0.3
CATEGORIES=	games
MASTER_SITES=	http://zippy.sonoma.edu/kendrick/nbs/unix/x/3dpong/

MAINTAINER=	andy@icc.surw.chel.su

MAKEFILE=	makefile
USE_X11=	yes
WRKSRC=		${WRKDIR}/3dpong

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/3dpong ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/3dpong
	@ ${INSTALL_DATA} ${WRKSRC}/sounds/*.au ${PREFIX}/share/3dpong
	@ ${MKDIR} ${PREFIX}/share/doc/3dpong
	@ ${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/3dpong

.include <bsd.port.mk>
