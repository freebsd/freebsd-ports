# New ports collection Makefile for: kinemage
# Version required:     4.2
# Date created:         Dec 4 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $Id$
#

DISTNAME=	MAGE_4_2.LINUX
PKGNAME=	kinemage-4.2
CATEGORIES=     biology
MASTER_SITES=	ftp://suna.biochem.duke.edu/pub/LINUXprograms/
EXTRACT_SUFX=	.Z

MAINTAINER=     frankch@waru.life.nthu.edu.tw

NO_WRKSUBDIR=	YES
NO_BUILD=	YES

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}
	@/usr/bin/uncompress ${WRKDIR}/${DISTFILES}

do-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/MAGE_4_2.LINUX ${PREFIX}/bin/kinemage

.include <bsd.port.mk>
