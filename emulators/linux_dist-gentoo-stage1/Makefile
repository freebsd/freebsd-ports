# New ports collection makefile for:	linux_base-gentoo-stage1
# Date created:				2003-10-12
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	linux_base-gentoo-stage1
PORTVERSION=	1.4
CATEGORIES=	emulators linux
MASTER_SITES=	${MASTER_SITE_GENTOO}
USE_BZIP2=	y
.include <bsd.port.pre.mk>
BROKEN=		incorrect packing list
PORTARCH=${MACHINE_ARCH:S/64//}
.if (${PORTARCH} == "alpha")
MASTER_SITE_SUBDIR=	experimental/alpha/stages
DISTNAME=	stage1-alpha-20030721
.endif
.if (${PORTARCH} == "amd")
BROKEN=		"Linux emulation is not available on x86-64"
IGNORE=		${BROKEN}
MASTER_SITE_SUBDIR=	experimental/amd64/stages
DISTNAME=	stage1-amd64-20040124
.endif
.if (${PORTARCH} == "ia")
MASTER_SITE_SUBDIR=	experimental/ia64
DISTNAME=		stage1-ia64-20030912
.endif
.if (${PORTARCH} == "i386")
MASTER_SITE_SUBDIR=	releases/x86/${PORTVERSION}/stages/x86
DISTNAME=	stage1-x86-20030910
.endif
.if (${PORTARCH} == "sparc")
MASTER_SITE_SUBDIR=	experimental/sparc/stages/sparc64
DISTNAME=	stage1-sparc64-20031011
.endif
DIST_SUBDIR=	gentoo-linux
EXTRACT_ONLY=

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Files from Gentoo distribution, for Linux compatibility

MD5_FILE=	${MASTERDIR}/distinfo.${MACHINE_ARCH}
NO_BUILD=	y
ONLY_FOR_ARCHS=	alpha amd64 ia64 i386 sparc64
PLIST=		${WRKDIR}/pkg-plist
PREFIX=		${LINUXBASE}
RESTRICTED=	"binaries licensed under GNU GPL without accompanying source"
CONFLICTS=cle_base-* linux_base-6* linux_base-7* linux_base-8* linux_base-debia*

pre-install:
	${ECHO_CMD} etc/resolv.conf > ${PLIST}
	${TAR} tyf ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | ${CUT} -c3-100 \
		> ${WRKDIR}/list.txt
	cd ${WRKDIR} && ${GREP} -v '/$$' ${WRKDIR}/list.txt >> ${PLIST}
	${GREP} '/$$' ${WRKDIR}/list.txt | ${SED} -e "s:^:@dirrm :g" >> ${PLIST}
	${RM} ${WRKDIR}/list.txt
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	- ${MKDIR} ${PREFIX}
	${TAR} -C ${PREFIX} -xypSf ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}
	- ${CP} -p /etc/resolv.conf ${PREFIX}/etc/
	${RM} ${PREFIX}/dev/null ${PREFIX}/dev/stdout
	mknod ${PREFIX}/dev/null c 2 2
	mknod ${PREFIX}/dev/stdout c 22 1
	brandelf -t Linux ${PREFIX}/sbin/ldconfig ${PREFIX}/sbin/sln
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
