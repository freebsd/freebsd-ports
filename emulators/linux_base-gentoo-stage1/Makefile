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
EXTRACT_ONLY=

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Files from Gentoo distribution, for Linux compatibility

RESTRICTED=	"binaries licensed under GNU GPL without accompanying source"

ONLY_FOR_ARCHS=	alpha amd64 ia64 i386

USE_BZIP2=	y

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64")
LATEST_LINK=	${PORTNAME:C/linux_base/linux32_base/}
ARCH=	i386
.endif

.if (${ARCH} == "alpha")
MASTER_SITES+=	ftp://ftp.uos.ac.kr/pub/Linux/gentoo/gentoo/experimental/alpha/stages/
MASTER_SITE_SUBDIR=	experimental/alpha/stages
DISTNAME=	stage1-alpha-20030729
.elif (${ARCH} == "i386")
MASTER_SITE_SUBDIR=	releases/x86/${PORTVERSION}/stages/x86 \
			releases/historical/x86/${PORTVERSION}/stages/x86
DISTNAME=	stage1-x86-20030910
.elif (${ARCH} == "ia64")
MASTER_SITE_SUBDIR=	releases/x86/${PORTVERSION}/stages/x86 \
			releases/historical/x86/${PORTVERSION}/stages/x86
DISTNAME=	stage1-x86-20030910
.endif

DIST_SUBDIR=	gentoo-linux
MD5_FILE=	${MASTERDIR}/distinfo.${ARCH}
PLIST=		${WRKDIR}/pkg-plist
PREFIX=		${LINUXBASE}
NO_FILTER_SHLIBS=y
CONFLICTS=	linux_base-6* linux_base-7* linux_base-8* linux_base-debian*

do-build:
	${ECHO_CMD} etc/resolv.conf > ${PLIST}
	${TAR} tyf ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | ${CUT} -c3-100 \
		> ${WRKDIR}/tarball-contents
	${GREP} -v '/$$' ${WRKDIR}/tarball-contents >> ${PLIST}
	${GREP} '/$$' ${WRKDIR}/tarball-contents | ${SED} -e "s:^:@dirrm :g" \
		| ${GREP} -v '@dirrm etc/' | ${SORT} -r >> ${PLIST}

do-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	- ${MKDIR} ${PREFIX}
	${TAR} -xpy -C ${PREFIX} -f ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}
	${CP} -p /etc/resolv.conf ${PREFIX}/etc/
	${RM} ${PREFIX}/dev/null ${PREFIX}/dev/stdout
	mknod ${PREFIX}/dev/null c 2 2
	mknod ${PREFIX}/dev/stdout c 22 1
	${BRANDELF} -t Linux ${PREFIX}/sbin/ldconfig ${PREFIX}/sbin/sln
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
