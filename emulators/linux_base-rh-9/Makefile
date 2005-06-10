# New ports collection makefile for:	linux_base-rh-9
# Date created:				2004-11-15
# Whom:					delphij
# based on linux_base-8 port by Marcel Moolenaar, Trevor Johnson and others
#
# $FreeBSD$
#

PORTNAME=	linux_base-rh
PORTVERSION=	9
CATEGORIES=	emulators linux
MASTER_SITES=	${MASTER_SITE_REDHAT_LINUX} \
		${MASTER_SITE_REDHAT_LINUX:S/$/:new/}
MASTER_SITE_SUBDIR=	\
		${PORTVERSION}/${LANG}/os/i386/RedHat/RPMS \
		updates/${PORTVERSION}/${LANG}/os/i386/:new
DISTFILES=	glibc-2.3.2-27.9.7.i386.rpm:new \
		glibc-common-2.3.2-27.9.7.i386.rpm:new \
		redhat-release-9-3.i386.rpm \
		setup-2.5.25-1.noarch.rpm \
		filesystem-2.2.1-3.i386.rpm \
		basesystem-8.0-2.noarch.rpm \
		zlib-1.1.4-8.i386.rpm \
		libattr-2.2.0-1.i386.rpm \
		libacl-2.2.3-1.i386.rpm \
		elfutils-libelf-0.76-3.i386.rpm \
		bzip2-libs-1.0.2-8.i386.rpm \
		termcap-11.0.1-16.noarch.rpm \
		db4-4.0.14-20.i386.rpm \
		gdbm-1.8.0-20.i386.rpm \
		glib-1.2.10-10.i386.rpm \
		libtermcap-2.0.8-35.i386.rpm \
		bash-2.05b-20.1.i386.rpm:new \
		bzip2-1.0.2-8.i386.rpm \
		compat-libstdc++-7.3-2.96.118.i386.rpm \
		ncurses-5.3-4.i386.rpm \
		info-4.3-5.i386.rpm \
		pcre-3.9-10.i386.rpm \
		findutils-4.1.7-9.i386.rpm \
		grep-2.5.1-7.i386.rpm \
		coreutils-4.5.3-19.0.2.i386.rpm:new \
		popt-1.8-0.69.i386.rpm \
		readline-4.3-5.i386.rpm \
		setserial-2.17-12.i386.rpm \
		libstdc++-3.2.2-5.i386.rpm \
		slang-1.4.5-16.i386.rpm \
		glibc-utils-2.3.2-11.9.i386.rpm \
		rpm-4.2-0.69.i386.rpm \
		libgcc-3.2.2-5.i386.rpm \
		freetype-2.1.3-6.i386.rpm

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Base set of packages needed in Linux mode (only for i386)

EXTRACT_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm

CONFLICTS=		linux_base-7* linux_base-8* \
			linux_base-debian* linux_base-gentoo* linux_base-suse*
RESTRICTED=		"binaries under GNU GPL without accompanying source"
ONLY_FOR_ARCHS=		amd64 i386
DIST_SUBDIR=		rpm/i386/rh9
PREFIX=			${LINUXBASE}
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
PLIST=			${WRKDIR}/pkg-plist

# Red Hat Linux 9 is only available in English.
LANG=			en

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
BRAND_FILES=		bin/rpm sbin/ldconfig sbin/sln

.if (${ARCH} == "amd64")
LATEST_LINK:=		${LATEST_LINK:C/linux/linux32/}
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
		${BRANDELF} -t Linux ${WRKSRC}/$$F; \
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
