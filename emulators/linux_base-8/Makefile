# New ports collection makefile for:	linux_base-8
# Date created:				2003-06-02
# Whom:					trevor
# based on ports/emulators/linux_base by Marcel Moolenaar and others
#
# $FreeBSD$
#

PORTNAME=		linux_base-8
PORTVERSION=		8.0
PORTREVISION=		6
CATEGORIES=		emulators linux
MASTER_SITES=		${MASTER_SITE_REDHAT_LINUX} \
			${MASTER_SITE_REDHAT_LINUX:S/$/:new/} \
			ftp://mirror.switch.ch/mirror/ximian/mono/redhat-80-i386/:ft
MASTER_SITE_SUBDIR=    \
			${PORTVERSION}/${LANG}/os/${ARCH}/RedHat/RPMS \
			updates/${PORTVERSION}/${LANG}/os/${ARCH}/:new
DISTFILES=		redhat-release-8.0-8.noarch.rpm \
			glibc-common-2.3.2-4.80.8.${ARCH}.rpm:new \
			glibc-2.3.2-4.80.8.${ARCH}.rpm:new \
			setup-2.5.20-1.noarch.rpm \
			filesystem-2.1.6-5.noarch.rpm \
			basesystem-8.0-1.noarch.rpm \
			libattr-2.0.8-3.${ARCH}.rpm \
			libacl-2.0.11-2.${ARCH}.rpm \
			libelf-0.8.2-2.${ARCH}.rpm \
			bzip2-libs-1.0.2-5.${ARCH}.rpm \
			termcap-11.0.1-13.noarch.rpm \
			compat-db-3.3.11-2.${ARCH}.rpm \
			db4-4.0.14-14.${ARCH}.rpm \
			gdbm-1.8.0-18.${ARCH}.rpm \
			glib-1.2.10-8.${ARCH}.rpm \
			libtermcap-2.0.8-31.${ARCH}.rpm \
			bash-2.05b-5.${ARCH}.rpm \
			bzip2-1.0.2-5.${ARCH}.rpm \
			compat-libstdc++-7.3-2.96.110.${ARCH}.rpm \
			ncurses-5.2-28.${ARCH}.rpm \
			info-4.2-5.${ARCH}.rpm \
			grep-2.5.1-4.${ARCH}.rpm \
			fileutils-4.1.9-11.${ARCH}.rpm \
			popt-1.7-1.06.${ARCH}.rpm \
			readline-4.3-3.${ARCH}.rpm \
			setserial-2.17-9.${ARCH}.rpm \
			libstdc++-3.2-7.${ARCH}.rpm \
			slang-1.4.5-11.${ARCH}.rpm \
			sh-utils-2.0.12-3.${ARCH}.rpm \
			rpm-4.1-1.06.${ARCH}.rpm \
			libgcc-3.2-7.${ARCH}.rpm \
			freetype-2.1.5-0.ximian.5.1.${ARCH}.rpm:ft \
			zlib-1.1.4-8.8x.${ARCH}.rpm:new
EXTRACT_ONLY=

MAINTAINER=		freebsd-emulation@FreeBSD.org
COMMENT=	Base set of packages needed in Linux mode (only for i386)

BUILD_DEPENDS=		rpm:${PORTSDIR}/archivers/rpm

CONFLICTS=	linux_base-7* linux_base-deb* linux_base-gentoo* \
		linux_base-rh* linux_base-suse*
ONLY_FOR_ARCHS=		i386 amd64
DIST_SUBDIR=		rpm/${ARCH}/${PORTVERSION}
PREFIX?=		${LINUXBASE}
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
PLIST=			${WRKDIR}/pkg-plist
MD5_FILE=		${MASTERDIR}/distinfo.${ARCH}

# Let's avoid hardcoding 'en' as the language.
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
ARCH=			i386
FALLBACK_ELF_MIB=	kern.elf32.fallback_brand
RPMFLAGS+=		--noscripts
.else
FALLBACK_ELF_MIB=	kern.fallback_elf_brand
.endif
LINUX_ELF=		3
PREVIOUS_ELF!=		/sbin/sysctl -n ${FALLBACK_ELF_MIB}

pre-install:
#
# Handle the loading of the linux loadable kernel module if required.
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

	@${MKDIR} ${WRKSRC}/${DBPATH} ${WRKSRC}/var/tmp ${WRKSRC}/lib
	@cd ${WRKSRC}/lib && ${LN} -sf libtermcap.so.2.0.8 libtermcap.so.2
	@${RPM} --initdb --root ${WRKSRC} --dbpath ${DBPATH}
#
# Install all packages. Ignore dependencies just like the Red Hat installer.
# Also, set the ELF fallback brand to Linux, so that we don't have to do
# anything special to run staticly linked binaries.
	@/sbin/sysctl -w ${FALLBACK_ELF_MIB}=${LINUX_ELF}
	@for R in ${DISTFILES:S/:new//:S/:ft//}; do \
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
# Create a good ld.so.conf
#
	${ECHO_CMD} -e '/lib\n/usr/lib\n/usr/X11R6/lib' > ${WRKSRC}/etc/ld.so.conf
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
#
# Create PLIST
#
	${RM} -f ${PLIST}
	cd ${WRKSRC} && ${FIND} -s . -type f -o -type l | \
		${CUT} -c3-999 >> ${PLIST} \
		&& ${FIND} -d * -type d | ${SED} -e 's:^:@dirrm :' >> ${PLIST}

do-install:
	cd ${WRKSRC} && ${FIND} * | ${CPIO} -dmp ${PREFIX}
	${FIND} ${PREFIX} -type d -exec ${CHMOD} 755 \{\} \;
	${PREFIX}/sbin/ldconfig

post-install:
	@${ECHO} ''
	@fmt ${PKGMESSAGE}
	@${ECHO} ''

.include <bsd.port.post.mk>
