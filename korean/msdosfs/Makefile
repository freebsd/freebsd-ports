# Ports collection makefile for:  msdosfs for Korean
# Date created:		24 Mar 2001
# Whom:			cjh
#
# $FreeBSD$
#
# based on japanese/msdosfs
#

PORTNAME=	msdosfs
PORTVERSION=	${LAST_UPDATED}
CATEGORIES=	korean
MASTER_SITES=	http://www.kr.freebsd.org/~cjh/freebsd/msdosfs-ko/ \
		ftp://ftp.kr.freebsd.org/pub/users/cjh/FreeBSD/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=     trevor
DISTNAME=	${PORTNAME}-ko-20000710
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mount_msdos-20000701.tar.gz

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Mount a Microsoft FAT Korean file system

WRKSRC=		${WRKDIR}/${DISTNAME}/msdosfs.ko

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 410001 && ${OSVERSION} < 500000
LAST_UPDATED=	20001027
PATCHDIR=	${MASTERDIR}/patches.4
.elif ${OSVERSION} >= 500016 && ${OSVERSION} < 501109
# runs only after 9th Feb 2001 world
LAST_UPDATED=	20010209
PATCHDIR=	${MASTERDIR}/patches.5
NO_PACKAGE=	"to avoid crashing a machine when try to install incorrect version"
.elif ${OSVERSION} >= 501109
LAST_UPDATED=	20010209
IGNORE=		is included in the base system. See mount_msdosfs(8)
.else
LAST_UPDATED=	20001022
IGNORE=		is not supported on this version of FreeBSD
.endif

post-extract:
	cd ${WRKDIR}/mount ; co RCS/*,v
	cd ${WRKDIR}/mount_msdos ; co RCS/*,v
	${LN} -s ${WRKSRC} ${WRKSRC}/msdosfs
	${LN} -s ${WRKSRC}/msdosfsmount.h ${WRKDIR}/mount_msdos

pre-build:
	@if [ ! -d /sys -o ! -d /usr/src/sys ]; then \
		${ECHO} "****************************************" ; \
		${ECHO} " You need to extract kernel source tree" ; \
		${ECHO} " before you build this package..." ; \
		${ECHO} "****************************************" ; \
		${FALSE} ; \
	fi

post-build:
	cd ${WRKDIR}/mount_msdos && ${MAKE}
	${SED} -e "s,@@PREFIX@@,${PREFIX}," ${FILESDIR}/ko-msdosfs.sh \
		> ${WRKDIR}/ko-msdosfs.sh

do-install:
	${MKDIR} ${PREFIX}/lib/ko-msdosfs
	${INSTALL_PROGRAM} ${WRKDIR}/mount_msdos/mount_komsdos ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/msdos_ko.ko ${PREFIX}/lib/ko-msdosfs
	${INSTALL_SCRIPT} ${WRKDIR}/ko-msdosfs.sh ${PREFIX}/etc/rc.d

.include <bsd.port.post.mk>
