# New ports collection makefile for:    linux_base
# Date created:         Oct 3, 2001
# Whom:                 marcel@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		linux_base
PORTVERSION=		7.1
PORTREVISION=		1
CATEGORIES=		emulators linux
MASTER_SITES=		${MASTER_SITE_REDHAT_LINUX}
MASTER_SITE_SUBDIR=	${PORTVERSION}/${LANG}/os/${MACHINE_ARCH}/RedHat/RPMS
DISTFILES=		redhat-release-7.1-1.noarch.rpm \
			${RPM_SETUP} \
			filesystem-2.0.7-1.noarch.rpm \
			basesystem-7.0-2.noarch.rpm \
			termcap-11.0.1-8.noarch.rpm \
			db1-1.85-5.${MACHINE_ARCH}.rpm \
			db3-3.1.17-7.${MACHINE_ARCH}.rpm \
			${RPM_GDBM} \
			glib-1.2.9-1.${MACHINE_ARCH}.rpm \
			libtermcap-2.0.8-26.${MACHINE_ARCH}.rpm \
			bash-2.04-21.${MACHINE_ARCH}.rpm \
			${RPM_BZIP2} \
			${RPM_LIBSTDCXX} \
			${RPM_COMPAT_LIBSTDCXX} \
			ncurses-5.2-8.${MACHINE_ARCH}.rpm \
			info-4.0-20.${MACHINE_ARCH}.rpm \
			fileutils-4.0.36-4.${MACHINE_ARCH}.rpm \
			grep-2.4.2-5.${MACHINE_ARCH}.rpm \
			popt-1.6.2-8.${MACHINE_ARCH}.rpm \
			readline-4.1-9.${MACHINE_ARCH}.rpm \
			${RPM_SETSERIAL} \
			slang-1.4.2-2.${MACHINE_ARCH}.rpm \
			sh-utils-2.0-13.${MACHINE_ARCH}.rpm \
			rpm-4.0.2-8.${MACHINE_ARCH}.rpm \
			${RPM_FREETYPE} \
			${RPM_XFREE86_LIBS}

PATCH_SITES=		${MASTER_SITE_REDHAT_LINUX}
PATCH_SITE_SUBDIR=	updates/${PORTVERSION}/${LANG}/os/${MACHINE_ARCH}
PATCHFILES=		${UPDATES}

MAINTAINER=		ports@FreeBSD.org

BUILD_DEPENDS=		rpm:${PORTSDIR}/archivers/rpm

ONLY_FOR_ARCHS=		alpha i386
DIST_SUBDIR=		rpm
PREFIX=			${LINUXBASE}
EXTRACT_ONLY=
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
PLIST=			${PKGDIR}/pkg-plist.${MACHINE_ARCH}
MD5_FILE=		${MASTERDIR}/distinfo.${MACHINE_ARCH}

# Let's avoid hardcoding 'en' as the language.
LANG=			en

UPDATES=		glibc-common-2.2.4-29.${MACHINE_ARCH}.rpm \
				glibc-2.2.4-29.${MACHINE_ARCH}.rpm \
				zlib-1.1.3-25.7.${MACHINE_ARCH}.rpm

.ifdef USE_LINUX
.error You have `USE_LINUX' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.include <bsd.port.pre.mk>

.if (${MACHINE_ARCH} == "i386")
RPM_BZIP2=		bzip2-1.0.1-3.i386.rpm
RPM_FREETYPE=		freetype-2.0.1-4.i386.rpm
RPM_GDBM=		gdbm-1.8.0-5.i386.rpm
RPM_LIBSTDCXX=		libstdc++-2.96-85.i386.rpm
RPM_COMPAT_LIBSTDCXX=	compat-libstdc++-6.2-2.9.0.14.i386.rpm
RPM_SETSERIAL=		setserial-2.17-2.i386.rpm
RPM_SETUP=		setup-2.4.7-1.noarch.rpm
RPM_XFREE86_LIBS=	XFree86-libs-4.0.3-5.i386.rpm
UPDATES+=		${RPM_LIBSTDCXX}
.else
RPM_BZIP2=		bzip2-1.0.1-4.alpha.rpm
RPM_FREETYPE=		freetype-2.0.1-5.alpha.rpm
RPM_GDBM=		gdbm-1.8.0-6.alpha.rpm
RPM_LIBSTDCXX=		libstdc++-2.96-87.alpha.rpm
RPM_COMPAT_LIBSTDCXX=
RPM_SETSERIAL=		setserial-2.17-3.alpha.rpm
RPM_SETUP=		setup-2.4.7-2.noarch.rpm
RPM_XFREE86_LIBS=	XFree86-libs-4.0.3-21.alpha.rpm
UPDATES+=
.endif

DBPATH=			/var/lib/rpm
RPM=			LC_ALL=C rpm
RPMFLAGS=		--root ${LINUXBASE} --dbpath ${DBPATH} --nodeps \
			--replacepkgs --ignoreos --ignorearch
RPMDIR=			${DISTDIR}/${DIST_SUBDIR}

REMOVE_DIRS=		boot dev home root tmp var/tmp usr/local usr/tmp
REMOVE_FILES=		bin/df bin/su etc/exports etc/group etc/localtime \
			etc/motd etc/passwd etc/printcap etc/services \
			etc/protocols
BRAND_FILES=		bin/rpm sbin/ldconfig sbin/sln

FALLBACK_ELF_MIB=	kern.fallback_elf_brand
LINUX_ELF=		3
PREVIOUS_ELF!=		/sbin/sysctl -n ${FALLBACK_ELF_MIB}

do-patch:
	@${DO_NADA}

pre-install:
#
# Handle the loading of the linux loadable kernel module if required.
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${LINUXBASE}/${DBPATH}
	@${MKDIR} ${LINUXBASE}/var/tmp ${LINUXBASE}/lib
	@cd ${LINUXBASE}/lib && ${LN} -sf libtermcap.so.2.0.8 libtermcap.so.2
	@${RPM} --initdb --root ${LINUXBASE} --dbpath ${DBPATH}
#
# Make sure we have a /dev/null in the chrooted environment.
	@${MKDIR} ${LINUXBASE}/dev
	@${RM} -f ${LINUXBASE}/dev/null
	@mknod ${LINUXBASE}/dev/null c 2 2
	@${CHMOD} 666 ${LINUXBASE}/dev/null
#
# Install all packages. Ignore dependencies just like the Red Hat installer.
# Also, set the ELF fallback brand to Linux, so that we don't have to do
# anything special to run staticly linked binaries.
	@/sbin/sysctl -w ${FALLBACK_ELF_MIB}=${LINUX_ELF}
	@for R in glibc-common-2.2.4-29.${MACHINE_ARCH}.rpm \
		glibc-2.2.4-29.${MACHINE_ARCH}.rpm \
		${DISTFILES} zlib-1.1.3-25.7.${MACHINE_ARCH}.rpm; do \
		${ECHO} $$R; \
		${RPM} -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
	@for F in ${BRAND_FILES}; do \
		brandelf -t Linux ${LINUXBASE}/$$F; \
	done
	@/sbin/sysctl -w ${FALLBACK_ELF_MIB}=${PREVIOUS_ELF}
#
# Install yp.conf as a hint to NIS users and make sure there's a
# mtab in etc, albeit an empty one. This is needed in a couple of
# cases. Most notably staroffice6.
#
	${INSTALL} ${COPY} -m 644 ${FILESDIR}/yp.conf ${LINUXBASE}/etc
	${TOUCH} ${LINUXBASE}/etc/mtab
#
# Finish
#
	@for D in ${REMOVE_DIRS}; do \
		${RM} -rf ${LINUXBASE}/$$D; \
	done
	@for F in ${REMOVE_FILES}; do \
		${RM} -f ${LINUXBASE}/$$F; \
	done
	@${LN} -sf /var/tmp ${LINUXBASE}/usr/tmp

post-install:
	@${ECHO} ''
	@fmt ${PKGMESSAGE}
	@${ECHO} ''

.include <bsd.port.post.mk>
