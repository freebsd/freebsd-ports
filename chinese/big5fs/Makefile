# New ports collection makefile for:    zh-big5fs
# Date created:         Oct 13, 2000
# Whom:                 keith@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		big5fs
PORTVERSION=		2.1
CATEGORIES=		chinese
MASTER_SITES=		ftp://freebsd.sinica.edu.tw/pub/keith/

MAINTAINER=		keith@FreeBSD.org

NO_PACKAGE=		"Different versions definitely cause crash"

SYSDIR=			/usr/src/sys
KMODDIR=		${PREFIX}/modules

pre-extract:
	@if [ ! -d /sys -o ! -d /usr/src/sys ]; then \
		${ECHO} "****************************************" ; \
		${ECHO} " You need to extract kernel source tree" ; \
		${ECHO} " before you build this package..." ; \
		${ECHO} "****************************************" ; \
		${FALSE} ; \
	fi

do-extract:
	@${MKDIR} ${WRKDIR}/msdos ${WRKDIR}/cd9660 ${WRKDIR}/ntfs
	@${CP} -R ${SYSDIR}/msdosfs/*.[ch] ${WRKDIR}/msdos
	@${CP} ${SYSDIR}/modules/msdos/Makefile ${WRKDIR}/msdos/Makefile.orig
	@${CP} -R ${SYSDIR}/isofs/cd9660/*.[ch] ${WRKDIR}/cd9660
	@${CP} ${SYSDIR}/modules/cd9660/Makefile ${WRKDIR}/cd9660/Makefile.orig
	@${CP} -R ${SYSDIR}/ntfs/*.[ch] ${WRKDIR}/ntfs
	@${CP} ${SYSDIR}/modules/ntfs/Makefile ${WRKDIR}/ntfs/Makefile.orig
	@(cd ${WRKDIR}; ${TAR} xzf ${DISTDIR}/${DISTFILES} )
	@${SED} -e 's,@@PREFIX@@,${PREFIX},' ${FILESDIR}/big5fs.sh > ${WRKDIR}/big5fs.sh

do-patch:
	@${SED} -e "/^\.PATH/d" ${WRKDIR}/msdos/Makefile.orig > ${WRKDIR}/msdos/Makefile
	@${SED} -e "/^\.PATH/d" ${WRKDIR}/cd9660/Makefile.orig > ${WRKDIR}/cd9660/Makefile
	@${SED} -e "/^\.PATH/d" ${WRKDIR}/ntfs/Makefile.orig > ${WRKDIR}/ntfs/Makefile
	@(cd ${WRKDIR}/msdos; ${PATCH} --quiet < ${WRKDIR}/msdos_big5.diff )
	@(cd ${WRKDIR}/cd9660; ${PATCH} --quiet < ${WRKDIR}/cd9660_big5.diff )
	@(cd ${WRKDIR}/ntfs; ${PATCH} --quiet < ${WRKDIR}/ntfs_big5.diff )

do-build:
	@(cd ${WRKDIR}/msdos; make all)
	@(cd ${WRKDIR}/cd9660; make all)
	@(cd ${WRKDIR}/ntfs; make all)

pre-install:
	@${MKDIR} ${KMODDIR}

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/big5fs.sh ${PREFIX}/etc/rc.d
	@${INSTALL_SCRIPT} ${WRKDIR}/msdos/msdos.ko ${KMODDIR}/big5msdos.ko
	@${INSTALL_SCRIPT} ${WRKDIR}/cd9660/cd9660.ko ${KMODDIR}/big5cd9660.ko
	@${INSTALL_SCRIPT} ${WRKDIR}/ntfs/ntfs.ko ${KMODDIR}/big5ntfs.ko

.include <bsd.port.mk>
