# New ports collection makefile for:    linux_devtools
# Date created:         Oct 3, 2001
# Whom:                 marcel@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		linux_devtools
PORTVERSION=		7.1
PORTREVISION=		3
CATEGORIES=		devel emulators linux
MASTER_SITES=		${MASTER_SITE_REDHAT_LINUX}
MASTER_SITE_SUBDIR=	${PORTVERSION}/${LANG}/os/${MACHINE_ARCH}/RedHat/RPMS
DISTFILES=		${RPM_MAKE} \
			binutils-2.10.91.0.2-3.${MACHINE_ARCH}.rpm \
			${RPM_GDB}
EXTRACT_ONLY=

PATCH_SITES=		${MASTER_SITE_REDHAT_LINUX}
PATCH_SITE_SUBDIR=	updates/${PORTVERSION}/${LANG}/os/${MACHINE_ARCH}
PATCHFILES=		${UPDATES}

MAINTAINER=		trevor@FreeBSD.org
COMMENT=		Packages needed for doing development in Linux mode

BROKEN=			Missing dependency

EXTRACT_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm

ONLY_FOR_ARCHS=		alpha i386

RESTRICTED=		"binaries under GNU GPL without accompanying source"

USE_LINUX=		yes
DIST_SUBDIR=		rpm
PREFIX=			${LINUXBASE}
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
PLIST=			${WRKDIR}/plist
MD5_FILE=		${MASTERDIR}/distinfo.${MACHINE_ARCH}

# Let's avoid hardcoding 'en' as the language.
LANG=			en

.include <bsd.port.pre.mk>

.if (${MACHINE_ARCH} == "alpha")
PATCH_SITES=	\
	ftp://ftp2.compaq.com/pub/linux/RedHat/7.2-alpha/updates/rpms/alpha/ \
	ftp://alpha.crl.dec.com/pub/linux/redhat/7.2-alpha/updates/rpms/alpha/
PORTREVISION=	2
.endif

.if (${MACHINE_ARCH} == "i386")
RPM_GDB=		gdb-5.0rh-5.i386.rpm
RPM_MAKE=		make-3.79.1-5.i386.rpm
UPDATES=		XFree86-devel-4.1.0-50.i386.rpm \
			glibc-devel-2.2.4-33.i386.rpm \
			cpp-2.96-112.7.1.i386.rpm \
			gcc-2.96-112.7.1.i386.rpm \
			gcc-c++-2.96-112.7.1.i386.rpm \
			gcc-g77-2.96-112.7.1.i386.rpm \
			libstdc++-devel-2.96-112.7.1.i386.rpm \
			kernel-headers-2.4.9-34.i386.rpm
.else
RPM_GDB=		gdb-5.0rh-9.alpha.rpm
RPM_MAKE=		make-3.79.1-6.alpha.rpm
UPDATES=		XFree86-devel-4.1.0-29.4hp.alpha.rpm \
			glibc-devel-2.2.4-32.1.alpha.rpm \
			cpp-2.96-112.7.2.1hp.alpha.rpm \
			gcc-2.96-112.7.2.1hp.alpha.rpm \
			gcc-c++-2.96-112.7.2.1hp.alpha.rpm \
			gcc-g77-2.96-112.7.2.1hp.alpha.rpm \
			kernel-source-2.4.18-27.7.x.hp.alpha.rpm \
			libstdc++-devel-2.96-112.7.2.1hp.alpha.rpm
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
	@${RM} -rf ${WRKSRC}/tmp
	@${MKDIR} ${WRKSRC}/tmp
.for ii in ${DISTFILES} ${PATCHFILES}
	cd ${WRKSRC}/tmp; rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${ii} | cpio -id
.endfor
	cd ${WRKSRC}/tmp; ${FIND} * -type f -o -type l > ${PLIST}
.if (${MACHINE_ARCH} == "i386")
	${ECHO_CMD} boot/kernel.h >> ${PLIST}
.endif
	cd ${WRKSRC}/tmp; ${FIND} -d * -type d | ${GREP} -vE "man|locale" | \
		${GREP} -vE "(bin$$|doc$$|info$$|hare$$|src$$|usr$$)" | \
		${GREP} -vE "(lib/X11$$|usr/include$$|X11R6/include$$)" | \
		${GREP} -vE "(usr/lib$$|gcc-lib$$|X11R6/lib$$|X11R6$$)" | \
		${SED} -e 's:^:@dirrm :' |grep -v "dirrm lib" >> ${PLIST}
	@${RM} -rf ${WRKSRC}/tmp

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
