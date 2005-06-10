# New ports collection makefile for:    linux_devtools
# Date created:         Jul 9, 1999
# Whom:                 marcel@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		linux_devtools
PORTVERSION=		6.1
PORTREVISION=		2
CATEGORIES=		devel emulators linux
MASTER_SITES=		${MASTER_SITE_REDHAT_LINUX}
MASTER_SITE_SUBDIR=	${PORTVERSION}/en/os/${MACHINE_ARCH}/RedHat/RPMS
DISTFILES=		${RPM_KERNEL_HEADERS} \
			${RPM_GLIBC_DEVEL} \
			make-3.77-6.${MACHINE_ARCH}.rpm \
			cpp-1.1.2-24.${MACHINE_ARCH}.rpm \
			egcs-1.1.2-24.${MACHINE_ARCH}.rpm \
			egcs-c++-1.1.2-24.${MACHINE_ARCH}.rpm \
			egcs-g77-1.1.2-24.${MACHINE_ARCH}.rpm \
			${RPM_GDB} \
			${RPM_X_DEVEL}

PATCH_SITES=		${MASTER_SITE_REDHAT_LINUX}
PATCH_SITE_SUBDIR=	updates/${PORTVERSION}/en/os/${MACHINE_ARCH}
PATCHFILES=

MAINTAINER=		freebsd-emulation@FreeBSD.org
COMMENT=	Packages needed for doing development in Linux mode

BUILD_DEPENDS=		rpm:${PORTSDIR}/archivers/rpm

BROKEN=			"dependent on linux_base-6"
NO_LATEST_LINK=		yes
ONLY_FOR_ARCHS=		alpha i386
DIST_SUBDIR=		rpm
PREFIX=			/compat/linux
EXTRACT_ONLY=
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
USE_LINUX=		6
PLIST=			${PKGDIR}/pkg-plist.${MACHINE_ARCH}

.include <bsd.port.pre.mk>

.if (${MACHINE_ARCH} == "i386")
RPM_GDB=		gdb-4.18-4.i386.rpm
RPM_GLIBC_DEVEL=	glibc-devel-2.1.2-11.i386.rpm
RPM_KERNEL_HEADERS=	kernel-headers-2.2.12-20.i386.rpm
RPM_X_DEVEL=		XFree86-devel-3.3.5-3.i386.rpm
.else
RPM_GDB=		gdb-4.18-5.alpha.rpm
RPM_GLIBC_DEVEL=	glibc-devel-2.1.2-17.alpha.rpm
RPM_KERNEL_HEADERS=	kernel-headers-2.2.13-0.9.alpha.rpm
RPM_X_DEVEL=		XFree86-devel-3.3.5-17.alpha.rpm
.endif

DBPATH=			/var/lib/rpm
RPMFLAGS=		--ignoreos --root ${PREFIX} --dbpath ${DBPATH} \
			--replacepkgs
RPMDIR=			${DISTDIR}/${DIST_SUBDIR}

REMOVE_DIRS=		/dev /tmp /var/tmp
REMOVE_FILES=		/boot/kernel.h

.if ${OSVERSION} <= 320001
#
# Hack to let the rpm installer run.  The actual kernel change occurred after
# 400008 on 4.0-current and well after 320001, but we'll assume people running
# -current and -stable stay reasonably up-to-date.
#
# Define this if you get messages that look like
#
# --
# ELF interpreter /compat/linux/lib/ld-linux.so.2 not found
# execution of script failed
# --
#
NEEDLOADLINK=		true
.endif

do-patch:
	@${DO_NADA}

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
#
# Setup a chroot'able environment
#
	@${MKDIR} ${PREFIX}/tmp
	@${MKDIR} ${PREFIX}/var/tmp
	@${MKDIR} ${PREFIX}/dev
	@${RM} -f ${PREFIX}/dev/null
	@mknod ${PREFIX}/dev/null c 2 2
	@${CHMOD} 666 ${PREFIX}/dev/null
.if defined(NEEDLOADLINK)
	@${MKDIR} ${PREFIX}/compat
	@${LN} -s / ${PREFIX}/compat/linux
.endif
#
# Install all packages.
#
	@for R in ${DISTFILES}; do \
		${ECHO_MSG} $$R; \
		rpm -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
#
# Install updates
#
	@for R in ${PATCHFILES}; do \
		${ECHO_MSG} $$R; \
		rpm -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
#
# Finish
#
.if defined(NEEDLOADLINK)
	@${RM} -rf ${PREFIX}/compat
.endif
	@for D in ${REMOVE_DIRS}; do \
		${RM} -rf ${PREFIX}/$$D; \
	done
	@for F in ${REMOVE_FILES}; do \
		${RM} -f ${PREFIX}/$$F; \
	done

.include <bsd.port.post.mk>
