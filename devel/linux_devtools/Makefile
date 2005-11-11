# New ports collection makefile for:    linux_devtools
# Date created:         Jul 9, 1999
# Whom:                 marcel@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		linux_devtools
PORTVERSION=		8.0
PORTREVISION=		5
CATEGORIES=		devel emulators linux
MASTER_SITES=		${MASTER_SITE_REDHAT_LINUX}
MASTER_SITE_SUBDIR=	${PORTVERSION}/${LANG}/os/${ARCH}/RedHat/RPMS
DISTFILES=		glibc-devel-2.2.93-5.i386.rpm \
			compat-libstdc++-devel-7.3-2.96.110.i386.rpm \
			libstdc++-devel-3.2-7.i386.rpm \
			make-3.79.1-14.i386.rpm \
			binutils-2.13.90.0.2-2.i386.rpm \
			cpp-3.2-7.i386.rpm \
			gcc-3.2-7.i386.rpm \
			gcc-c++-3.2-7.i386.rpm \
			gcc-g77-3.2-7.i386.rpm \
			gdb-5.2.1-4.i386.rpm \
			rpm-build-4.1-1.06.i386.rpm \
			rpm-devel-4.1-1.06.i386.rpm \
			glibc-kernheaders-2.4-7.20.i386.rpm
EXTRACT_ONLY=

PATCH_SITES=		${MASTER_SITE_REDHAT_LINUX}
PATCH_SITE_SUBDIR=	updates/${PORTVERSION}/${LANG}/os/${ARCH}
PATCHFILES=		${UPDATES}

MAINTAINER=		freebsd-emulation@FreeBSD.org
COMMENT=		Packages needed for doing development in Linux mode

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm

USE_LINUX=		8
USE_LINUX_PREFIX=	yes
ONLY_FOR_ARCHS=		i386 amd64
CONFLICTS=		linux_devtools-*
DIST_SUBDIR=		rpm/${ARCH}/${PORTVERSION}
NO_BUILD=		yes

# Let's avoid hardcoding 'en' as the language.
LANG=			en

.include <bsd.port.pre.mk>

UPDATES=		XFree86-devel-4.2.1-23.i386.rpm

DBPATH=			/var/lib/rpm
RPM=			LC_ALL=C rpm
RPMFLAGS=		--root ${PREFIX} --dbpath ${DBPATH} --nodeps \
			--replacepkgs --ignoreos
RPMDIR=			${DISTDIR}/${DIST_SUBDIR}

REMOVE_DIRS=		dev tmp var/tmp
REMOVE_FILES=

.if (${ARCH} == "amd64")
ARCH=			i386
RPMFLAGS+=		--ignorearch
.endif

do-patch:
	@${DO_NADA}

do-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${MKDIR} ${PREFIX}/tmp
	@${MKDIR} ${PREFIX}/var/tmp
#
# Install all packages.
	@for R in ${DISTFILES}; do \
		${ECHO_MSG} $$R; \
		${RPM} -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
#
# Install updates
	@for R in ${PATCHFILES}; do \
		${ECHO_MSG} $$R; \
		${RPM} -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
#
# Finish
	@for D in ${REMOVE_DIRS}; do \
		${RM} -rf ${PREFIX}/$$D; \
	done
	@for F in ${REMOVE_FILES}; do \
		${RM} ${PREFIX}/$$F; \
	done

.include <bsd.port.post.mk>
