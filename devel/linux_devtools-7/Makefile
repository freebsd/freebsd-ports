# New ports collection makefile for:    linux_devtools
# Date created:         Oct 3, 2001
# Whom:                 marcel@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		linux_devtools
PORTVERSION=		7.1
CATEGORIES=		devel emulators linux
MASTER_SITES=		${MASTER_SITE_REDHAT_LINUX}
MASTER_SITE_SUBDIR=	${PORTVERSION}/${LANG}/os/${MACHINE_ARCH}/RedHat/RPMS
DISTFILES=		${RPM_KERNEL_HEADERS} \
			${RPM_GLIBC_DEVEL} \
			${RPM_LIBSTDCXX_DEVEL} \
			${RPM_MAKE} \
			binutils-2.10.91.0.2-3.${MACHINE_ARCH}.rpm \
			${RPM_CPP} \
			${RPM_GCC} \
			${RPM_GCC_CXX} \
			${RPM_GCC_G77} \
			${RPM_GDB} \
			${RPM_X_DEVEL}
EXTRACT_ONLY=

PATCH_SITES=		${MASTER_SITE_REDHAT_LINUX}
PATCH_SITE_SUBDIR=	updates/${PORTVERSION}/${LANG}/os/${MACHINE_ARCH}
PATCHFILES=		${UPDATES}

MAINTAINER=		ports@FreeBSD.org

BUILD_DEPENDS=		rpm:${PORTSDIR}/archivers/rpm

ONLY_FOR_ARCHS=		alpha i386

USE_LINUX=		yes
DIST_SUBDIR=		rpm
PREFIX=			${LINUXBASE}
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
PLIST=			${PKGDIR}/pkg-plist.${MACHINE_ARCH}
MD5_FILE=		${MASTERDIR}/distinfo.${MACHINE_ARCH}

# Let's avoid hardcoding 'en' as the language.
LANG=			en

.include <bsd.port.pre.mk>

.if (${MACHINE_ARCH} == "i386")
RPM_CPP=
RPM_GCC=
RPM_GCC_CXX=
RPM_GCC_G77=
RPM_GDB=		gdb-5.0rh-5.i386.rpm
RPM_GLIBC_DEVEL=	glibc-devel-2.2.2-10.i386.rpm
RPM_KERNEL_HEADERS=
RPM_LIBSTDCXX_DEVEL=
RPM_MAKE=		make-3.79.1-5.i386.rpm
RPM_X_DEVEL=		XFree86-devel-4.0.3-5.i386.rpm
UPDATES=		cpp-2.96-85.i386.rpm gcc-2.96-85.i386.rpm \
			gcc-c++-2.96-85.i386.rpm gcc-g77-2.96-85.i386.rpm \
			kernel-headers-2.4.9-34.i386.rpm \
			libstdc++-devel-2.96-85.i386.rpm
.else
RPM_CPP=		cpp-2.96-87.alpha.rpm
RPM_GCC=		gcc-2.96-87.alpha.rpm
RPM_GCC_CXX=		gcc-c++-2.96-87.alpha.rpm
RPM_GCC_G77=		gcc-g77-2.96-87.alpha.rpm
RPM_GDB=		gdb-5.0rh-9.alpha.rpm
RPM_GLIBC_DEVEL=	glibc-devel-2.2.3-11.alpha.rpm
RPM_KERNEL_HEADERS=	kernel-headers-2.4.3-12.alpha.rpm
RPM_LIBSTDCXX_DEVEL=	libstdc++-devel-2.96-87.alpha.rpm
RPM_MAKE=		make-3.79.1-6.alpha.rpm
RPM_X_DEVEL=		XFree86-devel-4.0.3-21.alpha.rpm
UPDATES=
.endif

DBPATH=			/var/lib/rpm
RPM=			LC_ALL=C rpm
RPMFLAGS=		--root ${LINUXBASE} --dbpath ${DBPATH} --nodeps \
			--replacepkgs --ignoreos
RPMDIR=			${DISTDIR}/${DIST_SUBDIR}

REMOVE_DIRS=		dev tmp var/tmp
REMOVE_FILES=

do-patch:
	@${DO_NADA}

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${LINUXBASE}/tmp
	@${MKDIR} ${LINUXBASE}/var/tmp
	@${MKDIR} ${LINUXBASE}/dev
	@${RM} -f ${LINUXBASE}/dev/null
	@mknod ${LINUXBASE}/dev/null c 2 2
	@${CHMOD} 666 ${LINUXBASE}/dev/null
#
# Install all packages.
	@for R in ${DISTFILES}; do \
		${ECHO} $$R; \
		${RPM} -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
#
# Install updates
	@for R in ${PATCHFILES}; do \
		${ECHO} $$R; \
		${RPM} -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
#
# Finish
	@for D in ${REMOVE_DIRS}; do \
		${RM} -rf ${LINUXBASE}/$$D; \
	done
	@for F in ${REMOVE_FILES}; do \
		${RM} ${LINUXBASE}/$$F; \
	done

.include <bsd.port.post.mk>
