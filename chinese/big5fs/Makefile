# New ports collection makefile for:    zh-big5fs
# Date created:         Oct 13, 2000
# Whom:                 keith@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	big5fs
PORTVERSION=	2.3
CATEGORIES=	chinese
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/statue/big5fs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reads Big5 filenames on Joliet, VFAT and NTFS filesystems

NO_PACKAGE=	"Different versions definitely cause crash"

SYSDIR=		/usr/src/sys
KMODDIR=	${PREFIX}/modules
PLIST_SUB=	MSDOSFSKO=${MSDOSFSKO}
NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000 && ${OSVERSION} < 501109
MSDOSFSDIR=	${SYSDIR}/fs/msdosfs
MSDOSFSKO=	msdosfs.ko
MSDOSFSKODIR=	${SYSDIR}/modules/msdosfs
NTFSDIR=	${SYSDIR}/fs/ntfs
NTFSPATCH=	ntfs_big5.diff.5
.elif ${OSVERSION} >= 501109
IGNORE=		is obsolete. See mount_cd9660(8), mount_msdosfs(8) or mount_ntfs(8)
.else
MSDOSFSDIR=	${SYSDIR}/msdosfs
MSDOSFSKO=	msdos.ko
MSDOSFSKODIR=	${SYSDIR}/modules/msdos
NTFSDIR=	${SYSDIR}/ntfs
NTFSPATCH=	ntfs_big5.diff.440001
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
.if ${OSVERSION} > 500041
	@${REINPLACE_CMD} -e 's/ __P(\(.*\))/\1/g' ${WRKSRC}/*.diff
.endif

do-patch:
	@(cd ${WRKSRC}/msdos; ${PATCH} --quiet < ${WRKSRC}/msdos_big5.diff )
	@(cd ${WRKSRC}/cd9660; ${PATCH} --quiet < ${WRKSRC}/cd9660_big5.diff )
	@(cd ${WRKSRC}/ntfs; ${PATCH} --quiet < ${WRKSRC}/${NTFSPATCH} )
	@${REINPLACE_CMD} -e 's,<isofs/cd9660/iso.h>,"iso.h",g' ${WRKSRC}/cd9660/*.c
	@${REINPLACE_CMD} -Ee 's,<(fs/)?ntfs/ntfs_subr.h>,"ntfs_subr.h",g' ${WRKSRC}/ntfs/*.c

do-build:
	@(cd ${WRKSRC}/msdos; make all)
	@(cd ${WRKSRC}/cd9660; make all)
	@(cd ${WRKSRC}/ntfs; make all)

do-install:
	@${MKDIR} ${KMODDIR}
	@${INSTALL_SCRIPT} ${FILESDIR}/big5fs.sh ${PREFIX}/etc/rc.d
	@${INSTALL_SCRIPT} ${WRKSRC}/*/*.ko ${KMODDIR}

.include <bsd.port.post.mk>
