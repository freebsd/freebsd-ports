# New ports collection makefile for:	linux_base-suse-9.1
# Date created:				2004-12-19
# Whom:					trevor
# based on ports/emulators/linux_base by Marcel Moolenaar and others
#
# $FreeBSD$
#

PORTNAME=		linux_base-suse
PORTVERSION=		9.1
CATEGORIES=		emulators linux
MASTER_SITES=		${MASTER_SITE_SUSE}
MASTER_SITE_SUBDIR=	i386/9.1/suse/i586
DISTFILES=	suse-release-9.1-0.i586.rpm \
		glibc-locale-2.3.3-98.i586.rpm \
		glibc-2.3.3-98.i586.rpm \
		filesystem-9.1-0.i586.rpm \
		libattr-2.4.12-56.i586.rpm \
		db-4.2.52-85.i586.rpm \
		gdbm-1.8.3-225.i586.rpm \
		glib-1.2.10-586.i586.rpm \
		bash-2.05b-305.i586.rpm \
		ncurses-5.4-59.i586.rpm \
		readline-4.3-306.i586.rpm \
		zlib-1.2.1-70.i586.rpm \
		info-4.6-61.i586.rpm \
		grep-2.5.1-416.i586.rpm \
		desktop-file-utils-0.3.0.cvs20030807-221.i586.rpm \
		coreutils-5.2.1-23.i586.rpm \
		popt-1.7-176.i586.rpm \
		insserv-1.00.2-85.i586.rpm \
		setserial-2.17-577.i586.rpm \
		libstdc++-3.3.3-41.i586.rpm \
		slang-1.4.9-121.i586.rpm \
		bzip2-1.0.2-344.i586.rpm \
		libacl-2.2.21-54.i586.rpm \
		libselinux-1.8-16.i586.rpm \
		rpm-4.1.1-177.i586.rpm \
		libgcc-3.3.3-41.i586.rpm \
		termcap-2.0.8-876.i586.rpm \
		freetype2-2.1.7-53.i586.rpm

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Basic packages for Linux mode from SUSE 9.1/i386

EXTRACT_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm

CONFLICTS=	linux_base-7* linux_base-debian* \
		linux_base-gentoo* linux_base-rh-9*

NO_LATEST_LINK=		yes
RESTRICTED=		"binaries under GNU GPL without accompanying source"
ONLY_FOR_ARCHS=		i386
DIST_SUBDIR=		rpm/${MACHINE_ARCH}/suse
PREFIX=			${LINUXBASE}
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
PLIST=			${WRKDIR}/pkg-plist

.undef USE_LINUX

.include <bsd.port.pre.mk>
DBPATH=			/var/lib/rpm
RPM=			LC_ALL=C rpm
RPMFLAGS=		--root ${WRKSRC} --dbpath ${DBPATH} --nodeps \
			--replacepkgs --ignoreos --ignorearch
RPMDIR=			${DISTDIR}/${DIST_SUBDIR}
REMOVE_DIRS=		boot dev home initrd root tmp var/tmp usr/local usr/tmp
REMOVE_FILES=		bin/df bin/su etc/exports etc/group etc/localtime \
			etc/motd etc/passwd etc/printcap etc/services \
			etc/protocols
BRAND_FILES=		bin/rpm sbin/ldconfig

.if (${ARCH} == "amd64")
LATEST_LINK:=	${LATEST_LINK:C/linux/linux32/}
FALLBACK_ELF_MIB=	kern.elf32.fallback_brand
.else
FALLBACK_ELF_MIB=	kern.fallback_elf_brand
.endif
LINUX_ELF=		3
PREVIOUS_ELF!=		/sbin/sysctl -n ${FALLBACK_ELF_MIB}

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
	@for R in ${DISTFILES:S/:new//}; do \
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
	${TOUCH} ${WRKSRC}/etc/mtab ${WRKSRC}/etc/host.conf
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
