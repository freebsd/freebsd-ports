# Ports collection makefile for:  mount_jamsdos
# Date created:		3 July 2000
# Whom:			Ryuichiro IMURA <imura@af.airnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	msdosfs
PORTVERSION=	${LAST_UPDATED}
CATEGORIES=	japanese
MASTER_SITES=	http://www.linkclub.or.jp/~clover/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor
DISTNAME=	${PORTNAME}-ja-20000421
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mount_msdos-20000701.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mount a Microsoft FAT Japanese file system

WRKSRC=		${WRKDIR}/${DISTNAME}/msdosfs.ja

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
		${ECHO_MSG} "****************************************" ; \
		${ECHO_MSG} " You need to extract kernel source tree" ; \
		${ECHO_MSG} " before you build this package..." ; \
		${ECHO_MSG} "****************************************" ; \
		${FALSE} ; \
	fi

post-build:
	cd ${WRKDIR}/mount_msdos && ${MAKE}
	${SED} -e "s,@@PREFIX@@,${PREFIX}," ${FILESDIR}/ja-msdosfs.sh \
		> ${WRKDIR}/ja-msdosfs.sh

do-install:
	${MKDIR} ${PREFIX}/lib/ja-msdosfs
	${INSTALL_PROGRAM} ${WRKDIR}/mount_msdos/mount_jamsdos ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/msdos_ja.ko ${PREFIX}/lib/ja-msdosfs
	${INSTALL_SCRIPT} ${WRKDIR}/ja-msdosfs.sh ${PREFIX}/etc/rc.d

.include <bsd.port.post.mk>
