# New ports collection makefile for:	linux_base-8
# Date created:				2003-06-02
# Whom:					trevor
# based on ports/emulators/linux_base by Marcel Moolenaar and others
#
# $FreeBSD$
#

PORTNAME=		linux_base-8
PORTVERSION=		8.0
PORTREVISION=		4
CATEGORIES=		emulators linux
MASTER_SITES=		${MASTER_SITE_REDHAT_LINUX}
MASTER_SITE_SUBDIR=	${PORTVERSION}/${LANG}/os/${MACHINE_ARCH}/RedHat/RPMS
DISTFILES=		redhat-release-8.0-8.noarch.rpm \
			${RPM_SETUP} \
			filesystem-2.1.6-5.noarch.rpm \
			basesystem-8.0-1.noarch.rpm \
			libattr-2.0.8-3.${MACHINE_ARCH}.rpm \
			libacl-2.0.11-2.${MACHINE_ARCH}.rpm \
			libelf-0.8.2-2.${MACHINE_ARCH}.rpm \
			bzip2-libs-1.0.2-5.${MACHINE_ARCH}.rpm \
			termcap-11.0.1-13.noarch.rpm \
			compat-db-3.3.11-2.${MACHINE_ARCH}.rpm \
			db4-4.0.14-14.${MACHINE_ARCH}.rpm \
			${RPM_GDBM} \
			glib-1.2.10-8.${MACHINE_ARCH}.rpm \
			libtermcap-2.0.8-31.${MACHINE_ARCH}.rpm \
			bash-2.05b-5.${MACHINE_ARCH}.rpm \
			${RPM_BZIP2} \
			${RPM_LIBSTDCXX} \
			${RPM_COMPAT_LIBSTDCXX} \
			ncurses-5.2-28.${MACHINE_ARCH}.rpm \
			info-4.2-5.${MACHINE_ARCH}.rpm \
			grep-2.5.1-4.${MACHINE_ARCH}.rpm \
			fileutils-4.1.9-11.${MACHINE_ARCH}.rpm \
			popt-1.7-1.06.${MACHINE_ARCH}.rpm \
			readline-4.3-3.${MACHINE_ARCH}.rpm \
			${RPM_SETSERIAL} \
			libstdc++-3.2-7.i386.rpm \
			slang-1.4.5-11.${MACHINE_ARCH}.rpm \
			sh-utils-2.0.12-3.${MACHINE_ARCH}.rpm \
			rpm-4.1-1.06.${MACHINE_ARCH}.rpm \
			libgcc-3.2-7.${MACHINE_ARCH}.rpm \
			${RPM_FREETYPE}

PATCH_SITES=		${MASTER_SITE_REDHAT_LINUX}
PATCH_SITE_SUBDIR=	updates/${PORTVERSION}/${LANG}/os/${MACHINE_ARCH}
PATCHFILES=		${UPDATES}

MAINTAINER=		trevor@FreeBSD.org
COMMENT=	Base set of packages needed in Linux mode (only for i386)

EXTRACT_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm

RESTRICTED=		"binaries under GNU GPL without accompanying source"
CONFLICTS=		linux_base-*
ONLY_FOR_ARCHS=		i386
DIST_SUBDIR=		rpm/${MACHINE_ARCH}/${PORTVERSION}
PREFIX=			${LINUXBASE}
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
PLIST=			${WRKDIR}/pkg-plist
MD5_FILE=		${MASTERDIR}/distinfo.${MACHINE_ARCH}

# Let's avoid hardcoding 'en' as the language.
LANG=			en

UPD_SET1=		glibc-common-2.3.2-4.80.8.${MACHINE_ARCH}.rpm \
			glibc-2.3.2-4.80.8.${MACHINE_ARCH}.rpm
UPD_SET2=		zlib-1.1.4-8.8x.${MACHINE_ARCH}.rpm
UPDATES=		${UPD_SET1} ${UPD_SET2}

.ifdef USE_LINUX
.error You have `USE_LINUX' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.include <bsd.port.pre.mk>

RPM_BZIP2=		bzip2-1.0.2-5.i386.rpm
RPM_FREETYPE=		freetype-2.1.2-7.i386.rpm
RPM_GDBM=		gdbm-1.8.0-18.i386.rpm
RPM_LIBSTDCXX=
RPM_COMPAT_LIBSTDCXX=	compat-libstdc++-7.3-2.96.110.i386.rpm
RPM_SETSERIAL=		setserial-2.17-9.i386.rpm
RPM_SETUP=		setup-2.5.20-1.noarch.rpm

DBPATH=			/var/lib/rpm
RPM=			LC_ALL=C rpm
RPMFLAGS=		--root ${WRKSRC} --dbpath ${DBPATH} --nodeps \
			--replacepkgs --ignoreos --ignorearch
RPMDIR=			${DISTDIR}/${DIST_SUBDIR}

REMOVE_DIRS=		boot dev home initrd root tmp var/tmp usr/local usr/tmp
REMOVE_FILES=		bin/df bin/su etc/exports etc/group etc/localtime \
			etc/motd etc/passwd etc/printcap etc/services \
			etc/protocols
BRAND_FILES=		bin/rpm sbin/ldconfig sbin/sln

FALLBACK_ELF_MIB=	kern.fallback_elf_brand
LINUX_ELF=		3
PREVIOUS_ELF!=		/sbin/sysctl -n ${FALLBACK_ELF_MIB}

do-patch:
	@${DO_NADA}

do-extract:
#
# Handle the loading of the linux loadable kernel module if required.
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

	@${MKDIR} ${WRKSRC}/${DBPATH} ${WRKSRC}/var/tmp ${WRKSRC}/lib
	@cd ${WRKSRC}/lib && ${LN} -sf libtermcap.so.2.0.8 libtermcap.so.2
	@${RPM} --initdb --root ${WRKSRC} --dbpath ${DBPATH}
#
# Make sure we have a /dev/null in the chrooted environment.
	@${MKDIR} ${WRKSRC}/dev
	@${RM} -f ${WRKSRC}/dev/null
	@mknod ${WRKSRC}/dev/null c 2 2
	@${CHMOD} 666 ${WRKSRC}/dev/null
#
# Install all packages. Ignore dependencies just like the Red Hat installer.
# Also, set the ELF fallback brand to Linux, so that we don't have to do
# anything special to run staticly linked binaries.
	@/sbin/sysctl -w ${FALLBACK_ELF_MIB}=${LINUX_ELF}
	@for R in ${UPD_SET1} ${DISTFILES} ${UPD_SET2}; do \
		${ECHO} $$R; \
		${RPM} -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
	@for F in ${BRAND_FILES}; do \
		brandelf -t Linux ${WRKSRC}/$$F; \
	done
	@/sbin/sysctl -w ${FALLBACK_ELF_MIB}=${PREVIOUS_ELF}
#
# Install yp.conf as a hint to NIS users and make sure there's a
# mtab in etc, albeit an empty one. This is needed in a couple of
# cases. Most notably staroffice6.
#
	${INSTALL} ${COPY} -m 644 ${FILESDIR}/yp.conf ${WRKSRC}/etc
	${TOUCH} ${WRKSRC}/etc/mtab
#
# Finish
#
	@for D in ${REMOVE_DIRS}; do \
		${RM} -rf ${WRKSRC}/$$D; \
	done
	@for F in ${REMOVE_FILES}; do \
		${RM} -f ${WRKSRC}/$$F; \
	done
	@${LN} -sf /var/tmp ${WRKSRC}/usr/tmp

pre-install:
	${RM} -f ${PLIST}
	cd ${WRKSRC} && ${FIND} -s . -type f -o -type l | \
		${CUT} -c3-999 >> ${PLIST} \
		&& ${FIND} -d * -type d | ${SED} -e 's:^:@dirrm :' >> ${PLIST}

do-install:
	cd ${WRKSRC} && ${FIND} * | ${CPIO} -dlmp ${PREFIX}
	${FIND} ${PREFIX} -type d -exec ${CHMOD} 755 \{\} \;

post-install:
	@${ECHO} ''
	@fmt ${PKGMESSAGE}
	@${ECHO} ''

.include <bsd.port.post.mk>
