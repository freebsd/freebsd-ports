# New ports collection makefile for:    zh-gbfs
# Date created:         Oct 13, 2000
# Whom:                 statue@freebsd.sinica.edu.tw
#
# $FreeBSD$
#

PORTNAME=	gbfs
PORTVERSION=	1.3
CATEGORIES=	chinese
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/statue/gbfs/

MAINTAINER=	statue@freebsd.sinica.edu.tw
COMMENT=	Reads GB2312 filenames on Joliet and VFAT filesystems

NO_PACKAGE=	"Different versions definitely cause crash"

SYSDIR=		/usr/src/sys
KMODDIR=	${PREFIX}/modules
PLIST_SUB=	MSDOSFSKO=${MSDOSFSKO}
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
MSDOSFSDIR=	${SYSDIR}/fs/msdosfs
MSDOSFSKO=	msdosfs.ko
MSDOSFSKODIR=	${SYSDIR}/modules/msdosfs
MSDOSFSPATCH=	msdosfs.diff.5
CD9660PATCH=	cd9660.diff.5
NTFSDIR=	${SYSDIR}/fs/ntfs
NTFSPATCH=	ntfs.diff.5
.else
MSDOSFSDIR=	${SYSDIR}/msdosfs
MSDOSFSKO=	msdos.ko
MSDOSFSKODIR=	${SYSDIR}/modules/msdos
MSDOSFSPATCH=	msdosfs.diff
CD9660PATCH=	cd9660.diff
NTFSDIR=	${SYSDIR}/ntfs
NTFSPATCH=	ntfs.diff
.endif

.if !exists (${SYSDIR})
IGNORE= "You need to extract kernel source tree before you build this package"
.endif

do-extract:
	@${MKDIR} ${WRKDIR}/msdos ${WRKDIR}/cd9660 ${WRKDIR}/ntfs
	@${CP} ${MSDOSFSDIR}/* ${MSDOSFSKODIR}/Makefile ${WRKDIR}/msdos
	@${CP} ${SYSDIR}/isofs/cd9660/* ${SYSDIR}/modules/cd9660/Makefile ${WRKDIR}/cd9660
	@${CP} ${NTFSDIR}/* ${SYSDIR}/modules/ntfs/Makefile ${WRKDIR}/ntfs
	@(cd ${WRKDIR}; ${TAR} xzf ${DISTDIR}/${DISTFILES} )
	@${REINPLACE_CMD} -e "/^\.PATH/d" ${WRKDIR}/*/Makefile

do-patch:
	@(cd ${WRKDIR}/msdos; ${PATCH} --quiet < ${WRKDIR}/${MSDOSFSPATCH} )
	@(cd ${WRKDIR}/cd9660; ${PATCH} --quiet < ${WRKDIR}/${CD9660PATCH} )
	@(cd ${WRKDIR}/ntfs; ${PATCH} --quiet < ${WRKDIR}/${NTFSPATCH} )

do-build:
	@(cd ${WRKDIR}/msdos; make all)
	@(cd ${WRKDIR}/cd9660; make all)
	@(cd ${WRKDIR}/ntfs; make all)

do-install:
	@${MKDIR} ${KMODDIR}
	@${INSTALL_SCRIPT} ${FILESDIR}/gbfs.sh ${PREFIX}/etc/rc.d
	@${INSTALL_SCRIPT} ${WRKDIR}/*/*.ko ${KMODDIR}

.include <bsd.port.post.mk>
