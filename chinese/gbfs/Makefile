# New ports collection makefile for:    zh-gbfs
# Date created:         Oct 13, 2000
# Whom:                 statue@freebsd.sinica.edu.tw
#
# $FreeBSD$
#

PORTNAME=	gbfs
PORTVERSION=	1.4
CATEGORIES=	chinese
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/statue/gbfs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reads GB2312 filenames on Joliet and VFAT filesystems

NO_PACKAGE=	"Different versions definitely cause crash"

SYSDIR=		/usr/src/sys
KMODDIR=	${PREFIX}/modules
PLIST_SUB=	MSDOSFSKO=${MSDOSFSKO}
USE_REINPLACE=	yes
NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
MSDOSFSDIR=	${SYSDIR}/fs/msdosfs
MSDOSFSKO=	msdosfs.ko
MSDOSFSKODIR=	${SYSDIR}/modules/msdosfs
MSDOSFSPATCH=	msdosfs.diff.5
CD9660PATCH=	cd9660.diff.5
NTFSDIR=	${SYSDIR}/fs/ntfs
NTFSPATCH=	ntfs.diff.5
BROKEN=		"fails to patch"
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
IGNORE=	"You need to extract kernel source tree before you build this package"
.endif

do-extract:
	@${MKDIR} ${WRKSRC}/msdos ${WRKSRC}/cd9660 ${WRKSRC}/ntfs
	@${CP} -r ${MSDOSFSDIR}/* ${MSDOSFSKODIR}/Makefile ${WRKSRC}/msdos
	@${CP} -r ${SYSDIR}/isofs/cd9660/* ${SYSDIR}/modules/cd9660/Makefile ${WRKSRC}/cd9660
	@${CP} -r ${NTFSDIR}/* ${SYSDIR}/modules/ntfs/Makefile ${WRKSRC}/ntfs
	@(cd ${WRKSRC}; ${TAR} xzf ${DISTDIR}/${DISTFILES} )
	@${REINPLACE_CMD} -e "/^\.PATH/d" ${WRKSRC}/*/Makefile

do-patch:
	@(cd ${WRKSRC}/msdos; ${PATCH} --quiet < ${WRKSRC}/${MSDOSFSPATCH} )
	@(cd ${WRKSRC}/cd9660; ${PATCH} --quiet < ${WRKSRC}/${CD9660PATCH} )
	@(cd ${WRKSRC}/ntfs; ${PATCH} --quiet < ${WRKSRC}/${NTFSPATCH} )

do-build:
	@(cd ${WRKSRC}/msdos; make all)
	@(cd ${WRKSRC}/cd9660; make all)
	@(cd ${WRKSRC}/ntfs; make all)

do-install:
	@${MKDIR} ${KMODDIR}
	@${INSTALL_SCRIPT} ${FILESDIR}/gbfs.sh ${PREFIX}/etc/rc.d
	@${INSTALL_SCRIPT} ${WRKSRC}/*/*.ko ${KMODDIR}

.include <bsd.port.post.mk>
