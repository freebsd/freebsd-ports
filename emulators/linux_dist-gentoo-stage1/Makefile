# New ports collection makefile for:	linux_base-gentoo-stage1
# Date created:				2003-10-12
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	linux_base-gentoo-stage1
PORTVERSION=	2004.3
CATEGORIES=	emulators linux
MASTER_SITES=	${MASTER_SITE_GENTOO}
EXTRACT_ONLY=

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Files from Gentoo distribution, for Linux compatibility

RESTRICTED=	"binaries licensed under GNU GPL without accompanying source"

CONFLICTS=	linux_base-7* linux_base-8* linux_base-debian* \
		linux_base-rh* linux_base-suse*

BROKEN=		Incorrect pkg-plist

DIST_SUBDIR=	gentoo-linux
MD5_FILE=	${MASTERDIR}/distinfo.${ARCH}
NO_BUILD=	y
NO_FILTER_SHLIBS=y
NO_MTREE=	y
ONLY_FOR_ARCHS=	alpha amd64 ia64 i386
PLIST=		${WRKDIR}/pkg-plist
PREFIX=		${LINUXBASE}
USE_BZIP2=	y

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64")
LATEST_LINK=	${PORTNAME:C/linux_base/linux32_base/}
.endif

.if (${ARCH} == "alpha")
MASTER_SITE_SUBDIR=	releases/alpha/2004.3/stages
DISTNAME=	stage1-alpha-2004.3
.elif (${ARCH} == "i386" || ${ARCH} == "amd64" || ${ARCH} == "ia64")
MASTER_SITE_SUBDIR=	releases/x86/2004.3/stages/x86
DISTNAME=		stage1-x86-2004.3
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@${TAR} --exclude=./dev -xpy -C ${WRKSRC} \
		-f ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}
	@${ECHO_CMD} etc/resolv.conf > ${PLIST}
	@cd ${WRKSRC} && ${FIND} * -type f -o -type l >> ${PLIST} \
		&& ${FIND} * -type d | ${SORT} -r | ${SED} -e 's:^:@dirrm :' \
		>> ${PLIST}
	@${RM} -fr ${WRKSRC}

do-install:
	- ${MKDIR} ${PREFIX}
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${TAR} --exclude=./dev -xpy -C ${PREFIX} \
		-f ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}
	@${FIND} ${PREFIX} -type d -exec ${CHMOD} 755 \{\} \;
	@${CP} -p /etc/resolv.conf ${PREFIX}/etc/
	@${BRANDELF} -t Linux ${PREFIX}/sbin/ldconfig ${PREFIX}/sbin/sln
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
