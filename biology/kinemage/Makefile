# New ports collection Makefile for: kinemage
# Version required:     4.2
# Date created:         Dec 4 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $Id: Makefile,v 1.4 1998/11/13 15:27:42 billf Exp $
#

DISTNAME=	MAGE_4_2.LINUX
PKGNAME=	kinemage-4.2
CATEGORIES=     biology
MASTER_SITES=	ftp://kinemage.biochem.duke.edu/LINUXprograms/
EXTRACT_SUFX=	.Z

MAINTAINER=     frankch@waru.life.nthu.edu.tw

BUILD_DEPENDS=	/compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_lib
RUN_DEPENDS=	/compat/linux/lib/libc.so.5:${PORTSDIR}/emulators/linux_lib

NO_WRKSUBDIR=	YES
NO_BUILD=	YES

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
STRIP=
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}
	@/usr/bin/uncompress ${WRKDIR}/${DISTFILES}

do-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/MAGE_4_2.LINUX ${PREFIX}/bin/kinemage

.include <bsd.port.post.mk>
