# New ports collection Makefile for: povchem
# Date created:         Mar 14 1998
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $FreeBSD$
#

PORTNAME=	povchem
PORTVERSION=	1.0
CATEGORIES=     biology graphics
MASTER_SITES=   http://cherubino.med.jhmi.edu/~paul/PC_Dist/v1.00/
DISTFILES=	povchem.c \
		povchem.cfg \
		periodic.tab

MAINTAINER=     frankch@waru.life.nthu.edu.tw

NO_WRKSUBDIR=	yes
DIST_SUBDIR=	povchem

pre-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/povchem.c ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/povchem.cfg ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/periodic.tab ${WRKSRC}

do-extract:
	@${TOUCH} ${TOUCH_FLAGS} ${EXTRACT_COOKIE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/povchem ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/povchem.cfg ${PREFIX}/etc
	@${INSTALL_DATA} ${WRKSRC}/periodic.tab ${PREFIX}/share

.include <bsd.port.mk>
