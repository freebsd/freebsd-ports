# New ports collection Makefile for: kinemage
# Version required:     4.2
# Date created:         Dec 4 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $Id: Makefile,v 1.6 1998/12/09 22:35:04 billf Exp $
#

DISTNAME=	MAGE_4_2.LINUX
PKGNAME=	kinemage-4.2
CATEGORIES=     biology
MASTER_SITES=	ftp://kinemage.biochem.duke.edu/LINUXprograms/ \
		ftp://ftp.ebi.ac.uk/pub/databases/pdb/pub/xternal_software/kinemage/LINUX/ \
		ftp://ftp.pdb.bnl.gov/pub/xternal_software/kinemage/LINUX/
EXTRACT_SUFX=	.Z

MAINTAINER=     frankch@waru.life.nthu.edu.tw

BUILD_DEPENDS=	/compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_lib
RUN_DEPENDS=	/compat/linux/lib/libc.so.5:${PORTSDIR}/emulators/linux_lib

ONLY_FOR_ARCHS=	i386

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
