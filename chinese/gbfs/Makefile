# New ports collection makefile for:    zh-gbfs
# Date created:         Oct 13, 2000
# Whom:                 statue@freebsd.sinica.edu.tw
#
# $FreeBSD$
#

PORTNAME=	gbfs
PORTVERSION=	1.0
CATEGORIES=	chinese
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/statue/gbfs/ \
		ftp://ftp.gnuchina.org/incoming/zhBSD/

MAINTAINER=	statue@freebsd.sinica.edu.tw

NO_PACKAGE=	"Different versions definitely cause crash"

SYSDIR=		/usr/src/sys
KMODDIR=	${PREFIX}/modules
PLIST_SUB=	MSDOSFSKO=${MSDOSFSKO}

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500027
MSDOSFSDIR=	${SYSDIR}/fs/msdosfs
MSDOSFSKO=	msdosfs.ko
MSDOSFSKODIR=	${SYSDIR}/modules/msdosfs
.elif ${OSVERSION} > 500018 && ${OSVERSION} < 500027
MSDOSFSDIR=	${SYSDIR}/fs/msdosfs
MSDOSFSKO=	msdosfs.ko
MSDOSFSKODIR=	${SYSDIR}/modules/msdosfs
.elif ${OSVERSION} <= 500018 && ${OSVERSION} < 440001
MSDOSFSDIR=	${SYSDIR}/msdosfs
MSDOSFSKO=	msdos.ko
MSDOSFSKODIR=	${SYSDIR}/modules/msdos
.else
MSDOSFSDIR=	${SYSDIR}/msdosfs
MSDOSFSKO=	msdos.ko
MSDOSFSKODIR=	${SYSDIR}/modules/msdos
.endif

pre-extract:
	@if [ ! -d /sys -o ! -d /usr/src/sys ]; then \
		${ECHO_CMD} "****************************************" ; \
		${ECHO_CMD} " You need to extract kernel source tree" ; \
		${ECHO_CMD} " before you build this package..." ; \
		${ECHO_CMD} "****************************************" ; \
		${FALSE} ; \
	fi

do-extract:
	@${MKDIR} ${WRKDIR}/msdos ${WRKDIR}/cd9660
	@${CP} -R ${MSDOSFSDIR}/*.[ch] ${WRKDIR}/msdos
	@${CP} ${MSDOSFSKODIR}/Makefile ${WRKDIR}/msdos/Makefile.ori
	@${CP} -R ${SYSDIR}/isofs/cd9660/*.[ch] ${WRKDIR}/cd9660
	@${CP} ${SYSDIR}/modules/cd9660/Makefile ${WRKDIR}/cd9660/Makefile.ori
	@(cd ${WRKDIR}; ${TAR} xzf ${DISTDIR}/${DISTFILES} )
	@${SED} -e 's,@@PREFIX@@,${PREFIX},' ${FILESDIR}/gbfs.sh > ${WRKDIR}/gbfs.sh

do-patch:
	(cd ${WRKDIR}/msdos; ${PATCH} --quiet < ${WRKDIR}/msdosfs.diff )
	@${SED} -e "/^\.PATH/d" ${WRKDIR}/msdos/Makefile.ori > ${WRKDIR}/msdos/Makefile
	(cd ${WRKDIR}/cd9660; ${PATCH} --quiet < ${WRKDIR}/cd9660.diff )
	@${SED} -e "/^\.PATH/d" ${WRKDIR}/cd9660/Makefile.ori > ${WRKDIR}/cd9660/Makefile

do-build:
	@(cd ${WRKDIR}/msdos; make all)
	@(cd ${WRKDIR}/cd9660; make all)

pre-install:
	@${MKDIR} ${KMODDIR}

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/gbfs.sh ${PREFIX}/etc/rc.d
	@${INSTALL_SCRIPT} ${WRKDIR}/msdos/${MSDOSFSKO} ${KMODDIR}/${MSDOSFSKO}
	@${INSTALL_SCRIPT} ${WRKDIR}/cd9660/cd9660.ko ${KMODDIR}/cd9660.ko

.include <bsd.port.post.mk>
