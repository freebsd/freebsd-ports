# New ports collection makefile for:	linux_base-8
# Date created:				2003-06-02
# Whom:					trevor
# based on ports/emulators/linux_base by Marcel Moolenaar and others
#
# $FreeBSD$
#

PORTNAME=		linux_base-8
PORTVERSION=		8.0
PORTREVISION=		14
CATEGORIES=		emulators linux
MASTER_SITES=		http://download.fedoralegacy.org/redhat/%SUBDIR%/ \
			ftp://mirror.switch.ch/mirror/ximian/mono/redhat-80-i386/:ft
MASTER_SITE_SUBDIR=	${PORTVERSION}/os/${ARCH} \
			${PORTVERSION}/updates/${ARCH} \
			${PORTVERSION}/os/SRPMS \
			${PORTVERSION}/updates/SRPMS
DISTFILES=		${BIN_DISTFILES} ${SRC_DISTFILES}
EXTRACT_ONLY=

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Base set of packages needed in Linux mode (for i386/amd64)

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm

BIN_DISTFILES=		redhat-release-8.0-8.noarch.rpm \
			glibc-common-2.3.2-4.80.8.${ARCH}.rpm \
			glibc-2.3.2-4.80.8.${ARCH}.rpm \
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
			bash-2.05b-5.1.${ARCH}.rpm \
			bzip2-1.0.2-5.${ARCH}.rpm \
			compat-libstdc++-7.3-2.96.110.${ARCH}.rpm \
			ncurses-5.2-28.${ARCH}.rpm \
			info-4.2-5.${ARCH}.rpm \
			grep-2.5.1-4.${ARCH}.rpm \
			fileutils-4.1.9-11.2.${ARCH}.rpm \
			popt-1.7-1.06.${ARCH}.rpm \
			readline-4.3-3.${ARCH}.rpm \
			setserial-2.17-9.${ARCH}.rpm \
			libstdc++-3.2-7.${ARCH}.rpm \
			slang-1.4.5-11.${ARCH}.rpm \
			sh-utils-2.0.12-3.${ARCH}.rpm \
			rpm-4.1-1.06.${ARCH}.rpm \
			libgcc-3.2-7.${ARCH}.rpm \
			freetype-2.1.5-0.ximian.5.1.${ARCH}.rpm:ft \
			zlib-1.1.4-8.8x.${ARCH}.rpm

.if defined(PACKAGE_BUILDING)
SRC_DISTFILES+=	acl-2.0.11-2.src.rpm \
		attr-2.0.8-3.src.rpm \
		basesystem-8.0-1.src.rpm \
		bash-2.05b-5.1.src.rpm \
		bzip2-1.0.2-5.src.rpm \
		compat-db-3.3.11-2.src.rpm \
		compat-gcc-7.3-2.96.110.src.rpm \
		db4-4.0.14-14.src.rpm \
		filesystem-2.1.6-5.src.rpm \
		fileutils-4.1.9-11.2.src.rpm \
		gcc-3.2-7.src.rpm \
		gdbm-1.8.0-18.src.rpm \
		glib-1.2.10-8.src.rpm \
		glibc-2.3.2-4.80.8.src.rpm \
		grep-2.5.1-4.src.rpm \
		libelf-0.8.2-2.src.rpm \
		libtermcap-2.0.8-31.src.rpm \
		ncurses-5.2-28.src.rpm \
		readline-4.3-3.src.rpm \
		redhat-release-8.0-8.src.rpm \
		rpm-4.1-1.06.src.rpm \
		setserial-2.17-9.src.rpm \
		setup-2.5.20-1.src.rpm \
		sh-utils-2.0.12-3.src.rpm \
		slang-1.4.5-11.src.rpm \
		termcap-11.0.1-13.src.rpm \
		texinfo-4.2-5.src.rpm \
		zlib-1.1.4-8.8x.src.rpm

ALWAYS_KEEP_DISTFILES=	yes
.endif

CONFLICTS=	linux_base-7* linux_base-deb* linux_base-gentoo* \
		linux_base-rh* linux_base-suse*
ONLY_FOR_ARCHS=		i386 amd64
DIST_SUBDIR=		rpm/${ARCH}/${PORTVERSION}
PREFIX?=		${LINUXBASE}
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
MD5_FILE=		${MASTERDIR}/distinfo.${ARCH}

.include <bsd.port.pre.mk>

DBPATH=			/var/lib/rpm
RPM=			LC_ALL=C rpm
RPMFLAGS=		--root ${PREFIX} --dbpath ${DBPATH} --nodeps \
			--replacepkgs --ignoreos --ignorearch
RPMDIR=			${DISTDIR}/${DIST_SUBDIR}

REMOVE_DIRS=		boot dev home initrd root tmp var/run var/tmp usr/tmp
REMOVE_FILES=		bin/df bin/su etc/exports etc/group etc/localtime \
			etc/motd etc/passwd etc/printcap etc/services \
			etc/protocols

.if (${MACHINE_ARCH} == "amd64")
FALLBACK_ELF_MIB=	kern.elf32.fallback_brand
RPMFLAGS+=		--noscripts
.else
FALLBACK_ELF_MIB=	kern.fallback_elf_brand
.endif

.if (${ARCH} == "amd64")
LATEST_LINK:=		${LATEST_LINK:C/linux/linux32/}
ARCH=			i386
.endif

LINUX_ELF=		3
PREVIOUS_ELF!=		/sbin/sysctl -n ${FALLBACK_ELF_MIB}

# FIXME. The double-// can go away, once we deprecate rpm-3
RPMFLAGS+=	--relocate /etc/nsswitch.conf=/etc//nsswitch.conf.dist --badreloc

do-install:
#
# Handle the loading of the linux loadable kernel module if required.
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

	@${MKDIR} ${PREFIX}/${DBPATH} ${PREFIX}/var/tmp ${PREFIX}/lib
	@cd ${PREFIX}/lib && ${LN} -sf libtermcap.so.2.0.8 libtermcap.so.2
	@${RPM} --initdb --root ${PREFIX} --dbpath ${DBPATH}
#
# Install all packages. Ignore dependencies just like the Red Hat installer.
# Also, set the ELF fallback brand to Linux, so that we don't have to do
# anything special to run staticly linked binaries.
	@/sbin/sysctl -w ${FALLBACK_ELF_MIB}=${LINUX_ELF}
	@for R in ${BIN_DISTFILES:S/:ft//}; do \
		${ECHO} $$R; \
		${RPM} -U ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
	@test -f ${PREFIX}/etc/nsswitch.conf || ${CP} ${PREFIX}/etc/nsswitch.conf.dist \
		${PREFIX}/etc/nsswitch.conf
	@${FIND} ${PREFIX}/bin ${PREFIX}/sbin/ ${PREFIX}/usr/bin \
		${PREFIX}/usr/sbin -type f -print0 | ${XARGS} -0 ${FILE} \
		| ${GREP} ELF | ${CUT} -d : -f 1 \
		| ${XARGS} ${BRANDELF} -t Linux
#
# Install yp.conf as a hint to NIS users and make sure there's a
# mtab in etc, albeit an empty one. This is needed in a couple of
# cases. Most notably staroffice6.
#
	@${INSTALL} ${COPY} -m 644 ${FILESDIR}/yp.conf ${PREFIX}/etc
	@${TOUCH} ${PREFIX}/etc/mtab
#
# Create a good ld.so.conf
#
	@${ECHO_CMD} -e '/lib\n/usr/lib\n/usr/X11R6/lib' > ${PREFIX}/etc/ld.so.conf
#
# Build locale-archive manually, we passes --noscripts to rpm
#
.if ${MACHINE_ARCH} == "amd64"
	@${PREFIX}/usr/sbin/build-locale-archive
.endif
#
# Finish
#
	@for D in ${REMOVE_DIRS}; do \
		${RM} -rf ${PREFIX}/$$D; \
	done
	@for F in ${REMOVE_FILES}; do \
		${RM} -f ${PREFIX}/$$F; \
	done
	@${LN} -sf /var/tmp ${PREFIX}/usr/tmp
	@${CHOWN} root:wheel ${PREFIX}/var/lock ${PREFIX}/var/spool/mail
	@${CHMOD} 755 ${PREFIX}/var/lock ${PREFIX}/var/spool/mail
	@${PREFIX}/sbin/ldconfig -r ${PREFIX}

post-install:
	@${ECHO} ''
	@${CAT} ${PKGMESSAGE}
	@${ECHO} ''

.include <bsd.port.post.mk>
