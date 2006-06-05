# New ports collection makefile for:	linux_base-gentoo-stage3
# Date created:				11 May 2006
# Whom:					Gabor Kovesdan
#
# $FreeBSD$

PORTNAME=	linux_base-gentoo-stage3
PORTVERSION=	2006.0
CATEGORIES=	emulators linux
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	releases/x86/${PORTVERSION}/stages

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	Files from Gentoo distribution, for Linux compatibility

RESTRICTED=	binaries licensed under GNU GPL without accompanying source

CONFLICTS=	linux_base-7* linux_base-8* linux_base-debian* \
		linux_base-rh* linux_base-suse* linux_base-fc* \
		linux_base-gentoo-stage[12]-*

DIST_SUBDIR=		gentoo-linux
NO_BUILD=		YES
NO_FILTER_SHLIBS=	YES
NO_MTREE=		YES
ONLY_FOR_ARCHS=		i386 amd64
PLIST=			${WRKDIR}/pkg-plist
PREFIX=			${LINUXBASE}
USE_BZIP2=		YES
GENTOO_OPTIMIZED?=	x86

.include <bsd.port.pre.mk>

.if (${GENTOO_OPTIMIZED} == "i586" || ${GENTOO_OPTIMIZED} == "i686")
MASTER_SITE_SUBDIR=	releases/x86/${PORTVERSION}/stages
DISTNAME=	stage3-${GENTOO_OPTIMIZED}-${PORTVERSION}
.else
MASTER_SITE_SUBDIR=	releases/x86/${PORTVERSION}/stages
DISTNAME=	stage3-x86-${PORTVERSION}
.endif

pre-fetch:
	@${ECHO_MSG} "You can select your processor class for installing optimized"
	@${ECHO_MSG} "Gentoo binaries with setting this knob"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "GENTOO_OPTIMIZED=[x86|i586|i686]."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The default is x86 for 386/486 compatibility."

do-extract:
	@${MKDIR} ${WRKSRC}
	@${TAR} --exclude=./dev --exclude=./proc -xpy -C ${WRKSRC} \
		-f ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}
	@${ECHO_CMD} etc/resolv.conf > ${PLIST}
	@${ECHO_CMD} lib/udev/devices/console >> ${PLIST}
	@${ECHO_CMD} lib/udev/devices/null >> ${PLIST}
	@${ECHO_CMD} lib/udev/devices/zero >> ${PLIST}
	@cd ${WRKSRC} && ${FIND} * -type f -o -type l >> ${PLIST} \
		&& ${FIND} * -type d | ${SORT} -r | ${SED} -e 's:^:@dirrm :' \
		>> ${PLIST}
	@${RM} -fr ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${TAR} --exclude=./dev -xpy --exclude=./proc -C ${PREFIX} \
		-f ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}
	@${FIND} ${PREFIX} \! -path "/compat/linux/proc*" -type d -exec ${CHMOD} 755 \{\} \;
	@${CP} -p /etc/resolv.conf ${PREFIX}/etc/
	@${BRANDELF} -t Linux ${PREFIX}/sbin/ldconfig ${PREFIX}/sbin/sln
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
