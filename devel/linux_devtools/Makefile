# New ports collection makefile for:    linux_devtools
# Date created:         Jul 9, 1999
# Whom:                 marcel@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		linux_devtools
PORTVERSION=		8.0
PORTREVISION=	1
CATEGORIES=		devel emulators linux
MASTER_SITES=		${MASTER_SITE_REDHAT_LINUX}
MASTER_SITE_SUBDIR=	${PORTVERSION}/${LANG}/os/${MACHINE_ARCH}/RedHat/RPMS
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
			rpm-devel-4.1-1.06.i386.rpm
EXTRACT_ONLY=

PATCH_SITES=		${MASTER_SITE_REDHAT_LINUX}
PATCH_SITE_SUBDIR=	updates/${PORTVERSION}/${LANG}/os/${MACHINE_ARCH}
PATCHFILES=		${UPDATES}

MAINTAINER=		trevor@FreeBSD.org
COMMENT=		Packages needed for doing development in Linux mode

EXTRACT_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm
RUN_DEPENDS=${LINUXBASE}/lib/libc-2.3.2.so:${PORTSDIR}/emulators/linux_base-8

RESTRICTED=		"binaries under GNU GPL without accompanying source"

NO_LATEST_LINK=		yes
ONLY_FOR_ARCHS=		i386
CONFLICTS=		linux_devtools-*
DIST_SUBDIR=		rpm/${MACHINE_ARCH}/${PORTVERSION}
PREFIX=			${LINUXBASE}
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
PLIST=			${WRKDIR}/pkg-plist

# Let's avoid hardcoding 'en' as the language.
LANG=			en

.include <bsd.port.pre.mk>

UPDATES=		XFree86-devel-4.2.1-23.i386.rpm

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
	${RM} -rf ${WRKSRC}/tmp
	${MKDIR} ${WRKSRC}/tmp
.for ii in ${DISTFILES} ${PATCHFILES}
	cd ${WRKSRC}/tmp; rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${ii} | \
		${CPIO} -id
.endfor
	cd ${WRKSRC}/tmp; ${FIND} * -type f -o -type l > ${PLIST}; \
		${FIND} -d * -type d | ${SED} -e 's:^:@dirrm :'>> ${PLIST}
	${RM} -rf ${WRKSRC}/tmp

do-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${MKDIR} ${LINUXBASE}/tmp
	@${MKDIR} ${LINUXBASE}/var/tmp
	@${MKDIR} ${LINUXBASE}/dev
	@${RM} -f ${LINUXBASE}/dev/null
	@mknod ${LINUXBASE}/dev/null c 2 2
	@${CHMOD} 666 ${LINUXBASE}/dev/null
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
		${RM} -rf ${LINUXBASE}/$$D; \
	done
	@for F in ${REMOVE_FILES}; do \
		${RM} ${LINUXBASE}/$$F; \
	done

.include <bsd.port.post.mk>
