# New ports collection makefile for:	linux_base-gentoo-stage1
# Date created:				2003-10-12
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	linux_base-gentoo-stage1
PORTVERSION=	2006.0
PORTREVISION=	1
CATEGORIES=	emulators linux
MASTER_SITES=	${MASTER_SITE_GENTOO}
EXTRACT_ONLY=

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	Files from Gentoo distribution, for Linux compatibility

RESTRICTED=	binaries licensed under GNU GPL without accompanying source

CONFLICTS=	linux_base-7* linux_base-8* linux_base-debian* \
		linux_base-rh* linux_base-suse* linux_base-fc*

DIST_SUBDIR=		gentoo-linux
NO_BUILD=		YES
NO_FILTER_SHLIBS=	YES
NO_MTREE=		YES
ONLY_FOR_ARCHS=		alpha amd64 ia64 i386
PLIST=			${WRKDIR}/pkg-plist
PREFIX=			${LINUXBASE}
USE_BZIP2=		YES

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64")
LATEST_LINK=	${PORTNAME:C/linux_base/linux32_base/}
.endif

.if (${ARCH} == "alpha")
MASTER_SITE_SUBDIR=	releases/alpha/${PORTVERSION}/stages
DISTNAME=		stage1-alpha-${PORTVERSION}
MD5_FILE=       	${MASTERDIR}/distinfo.alpha
.else
MASTER_SITE_SUBDIR=	releases/x86/${PORTVERSION}/stages
DISTNAME=		stage1-x86-${PORTVERSION}
MD5_FILE=       	${MASTERDIR}/distinfo.i386
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@${TAR} --exclude=./dev --exclude=./proc -xpy -C ${WRKSRC} \
		-f ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}
	@${ECHO_CMD} etc/resolv.conf > ${PLIST}
	@cd ${WRKSRC} && ${FIND} * -type f -o -type l >> ${PLIST} \
		&& ${FIND} * -type d | ${SORT} -r | ${SED} -e 's:^:@dirrm :' \
		>> ${PLIST}
	@${RM} -fr ${WRKSRC}

do-install:
	- ${MKDIR} ${PREFIX}
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${TAR} --exclude=./dev -xpy --exclude=./proc -C ${PREFIX} \
		-f ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}
	@${FIND} ${PREFIX} -fstype ufs -type d -exec ${CHMOD} 755 \{\} \;
	@${CP} -p /etc/resolv.conf ${PREFIX}/etc/
	@${BRANDELF} -t Linux ${PREFIX}/sbin/ldconfig ${PREFIX}/sbin/sln
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
