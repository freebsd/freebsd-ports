# New ports collection makefile for:    zh-big5fs
# Date created:         Oct 13, 2000
# Whom:                 keith@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		big5fs
PORTVERSION=		2.2
CATEGORIES=		chinese
MASTER_SITES=		ftp://freebsd.csie.ntu.edu.tw/pub/users/rafan/

MAINTAINER=		keith@FreeBSD.org

NO_PACKAGE=		"Different versions definitely cause crash"

SYSDIR=			/usr/src/sys
KMODDIR=		${PREFIX}/modules
PLIST_SUB=		MSDOSFSKO=${MSDOSFSKO}

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500027
WITHOUT_NTFS=		yes
MSDOSFSDIR=		${SYSDIR}/fs/msdosfs
MSDOSFSKO=		msdosfs.ko
MSDOSFSKODIR=		${SYSDIR}/modules/msdosfs
.elif ${OSVERSION} > 500018 && ${OSVERSION} < 500027
MSDOSFSDIR=		${SYSDIR}/fs/msdosfs
MSDOSFSKO=		msdosfs.ko
MSDOSFSKODIR=		${SYSDIR}/modules/msdosfs
NTFSDIR=		${SYSDIR}/fs/ntfs
NTFSPATCH=		ntfs_big5.diff.440000
.elif ${OSVERSION} <= 500018 && ${OSVERSION} < 440001
MSDOSFSDIR=		${SYSDIR}/msdosfs
MSDOSFSKO=		msdos.ko
MSDOSFSKODIR=		${SYSDIR}/modules/msdos
NTFSDIR=		${SYSDIR}/ntfs
NTFSPATCH=		ntfs_big5.diff.440000
.else
MSDOSFSDIR=		${SYSDIR}/msdosfs
MSDOSFSKO=		msdos.ko
MSDOSFSKODIR=		${SYSDIR}/modules/msdos
NTFSDIR=		${SYSDIR}/ntfs
NTFSPATCH=		ntfs_big5.diff.440001
.endif

.if defined(WITHOUT_NTFS)
PLIST_SUB+=             NTFSKMOD="@comment "
.else
PLIST_SUB+=             NTFSKMOD=""
.endif

.if defined(WITHOUT_NTFS)
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "NTFS big5 patch is broken on this version."
	@${ECHO_MSG} "I will NOT build and install NTFS big5fs."
	@${ECHO_MSG}
.endif

pre-extract:
	@if [ ! -d /sys -o ! -d /usr/src/sys ]; then \
		${ECHO} "****************************************" ; \
		${ECHO} " You need to extract kernel source tree" ; \
		${ECHO} " before you build this package..." ; \
		${ECHO} "****************************************" ; \
		${FALSE} ; \
	fi

do-extract:
	@${MKDIR} ${WRKDIR}/msdos ${WRKDIR}/cd9660
	@${CP} -R ${MSDOSFSDIR}/*.[ch] ${WRKDIR}/msdos
	@${CP} ${MSDOSFSKODIR}/Makefile ${WRKDIR}/msdos/Makefile.orig
	@${CP} -R ${SYSDIR}/isofs/cd9660/*.[ch] ${WRKDIR}/cd9660
	@${CP} ${SYSDIR}/modules/cd9660/Makefile ${WRKDIR}/cd9660/Makefile.orig
.if !defined(WITHOUT_NTFS)
		@${MKDIR} ${WRKDIR}/ntfs
		@${CP} -R ${NTFSDIR}/*.[ch] ${WRKDIR}/ntfs
		@${CP} ${SYSDIR}/modules/ntfs/Makefile ${WRKDIR}/ntfs/Makefile.orig
.endif
	@(cd ${WRKDIR}; ${TAR} xzf ${DISTDIR}/${DISTFILES} )
	@${SED} -e 's,@@PREFIX@@,${PREFIX},' ${FILESDIR}/big5fs.sh > ${WRKDIR}/big5fs.sh

do-patch:
	@${SED} -e "/^\.PATH/d" ${WRKDIR}/msdos/Makefile.orig > ${WRKDIR}/msdos/Makefile
	@(cd ${WRKDIR}/msdos; ${PATCH} --quiet < ${WRKDIR}/msdos_big5.diff )
	@${SED} -e "/^\.PATH/d" ${WRKDIR}/cd9660/Makefile.orig > ${WRKDIR}/cd9660/Makefile
	@(cd ${WRKDIR}/cd9660; ${PATCH} --quiet < ${WRKDIR}/cd9660_big5.diff )
.if !defined(WITHOUT_NTFS)
	@${SED} -e "/^\.PATH/d" ${WRKDIR}/ntfs/Makefile.orig > ${WRKDIR}/ntfs/Makefile
	@(cd ${WRKDIR}/ntfs; ${PATCH} --quiet < ${WRKDIR}/${NTFSPATCH} )
.endif

do-build:
	@(cd ${WRKDIR}/msdos; make all)
	@(cd ${WRKDIR}/cd9660; make all)
.if !defined(WITHOUT_NTFS)
	@(cd ${WRKDIR}/ntfs; make all)
.endif

pre-install:
	@${MKDIR} ${KMODDIR}

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/big5fs.sh ${PREFIX}/etc/rc.d
	@${INSTALL_SCRIPT} ${WRKDIR}/msdos/${MSDOSFSKO} ${KMODDIR}/${MSDOSFSKO}
	@${INSTALL_SCRIPT} ${WRKDIR}/cd9660/cd9660.ko ${KMODDIR}/cd9660.ko
.if !defined(WITHOUT_NTFS)
	@${INSTALL_SCRIPT} ${WRKDIR}/ntfs/ntfs.ko ${KMODDIR}/ntfs.ko
.endif

.include <bsd.port.post.mk>
