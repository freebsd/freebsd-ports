# New ports collection Makefile for: kinemage
# Date created:         Dec 4 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $FreeBSD$
#

PORTNAME=	kinemage
PORTVERSION=	4.2
CATEGORIES=     biology linux
MASTER_SITES=	ftp://kinemage.biochem.duke.edu/LINUXprograms/ \
		ftp://ftp.ebi.ac.uk/pub/databases/pdb/pub/xternal_software/kinemage/LINUX/ \
		ftp://ftp.pdb.bnl.gov/pub/xternal_software/kinemage/LINUX/
DISTNAME=	MAGE_4_2.LINUX
EXTRACT_SUFX=	.Z

MAINTAINER=     frankch@waru.life.nthu.edu.tw

BUILD_DEPENDS=	/compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_base
RUN_DEPENDS=	/compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base

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
