# New ports collection Makefile for: povchem
# Version required:     1.0
# Date created:         Mar 14 1998
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $Id$
#

DISTNAME=	povchem-1.0
CATEGORIES=     biology graphics
MASTER_SITES=   http://cherubino.med.jhmi.edu/~paul/PC_Dist/v1.00/
DISTFILES=	povchem.c \
		povchem.cfg \
		periodic.tab

MAINTAINER=     frankch@waru.life.nthu.edu.tw

NO_WRKSUBDIR=	yes

pre-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/povchem.c ${WRKSRC}
	@${CP} ${DISTDIR}/povchem.cfg ${WRKSRC}
	@${CP} ${DISTDIR}/periodic.tab ${WRKSRC}

do-extract:
	@${TOUCH} ${TOUCH_FLAGS} ${EXTRACT_COOKIE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/povchem ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/povchem.cfg ${PREFIX}/etc
	@${INSTALL_DATA} ${WRKSRC}/periodic.tab ${PREFIX}/share

.include <bsd.port.mk>
