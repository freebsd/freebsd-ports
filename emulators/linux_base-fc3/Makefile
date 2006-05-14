# New ports collection makefile for:	linux_base-fc3
# Date created:				$Date$
# Whom:					bsam@ipt.ru
# based on ports/emulators/linux_base by trevor, netchild and others
#
# $FreeBSD$
#

PORTNAME=		fc
PORTVERSION=		3
PORTREVISION=		3
CATEGORIES=		emulators linux
MASTER_SITES=		${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR=	${PORTVERSION}/${LINUX_RPM_ARCH}/os/Fedora/RPMS \
			updates/${PORTVERSION}/${LINUX_RPM_ARCH} \
			${PORTVERSION}/SRPMS \
			updates/${PORTVERSION}/SRPMS
PKGNAMEPREFIX=		linux_base-
DISTFILES=		${BIN_DISTFILES} ${SRC_DISTFILES}
DIST_SUBDIR=		rpm/${LINUX_RPM_ARCH}/fedora/${PORTVERSION}
EXTRACT_ONLY=		${BIN_DISTFILES}

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Base set of packages needed in Linux mode (for i386/amd64)

BIN_DISTFILES=	basesystem-8.0-4.noarch.rpm \
		bash-3.0-18.${LINUX_RPM_ARCH}.rpm \
		bzip2-1.0.2-13.${LINUX_RPM_ARCH}.rpm \
		bzip2-libs-1.0.2-13.${LINUX_RPM_ARCH}.rpm \
		compat-db-4.1.25-6.${LINUX_RPM_ARCH}.rpm \
		compat-libstdc++-8-3.3.4.2.${LINUX_RPM_ARCH}.rpm \
		coreutils-5.2.1-31.${LINUX_RPM_ARCH}.rpm \
		db4-4.2.52-6.${LINUX_RPM_ARCH}.rpm \
		elfutils-libelf-0.96-1.${LINUX_RPM_ARCH}.rpm \
		fedora-release-3-8.${LINUX_RPM_ARCH}.rpm \
		filesystem-2.3.0-1.${LINUX_RPM_ARCH}.rpm \
		freetype-2.1.9-1.${LINUX_RPM_ARCH}.rpm \
		gdbm-1.8.0-24.${LINUX_RPM_ARCH}.rpm \
		glib-1.2.10-15.${LINUX_RPM_ARCH}.rpm \
		glibc-2.3.6-0.fc3.1.${LINUX_RPM_ARCH}.rpm \
		glibc-common-2.3.6-0.fc3.1.${LINUX_RPM_ARCH}.rpm \
		grep-2.5.1-31.${LINUX_RPM_ARCH}.rpm \
		info-4.7-5.${LINUX_RPM_ARCH}.rpm \
		libacl-2.2.23-5.${LINUX_RPM_ARCH}.rpm \
		libattr-2.4.16-3.${LINUX_RPM_ARCH}.rpm \
		libgcc-3.4.4-2.fc3.${LINUX_RPM_ARCH}.rpm \
		libselinux-1.19.1-8.${LINUX_RPM_ARCH}.rpm \
		libstdc++-3.4.2-6.fc3.${LINUX_RPM_ARCH}.rpm \
		libtermcap-2.0.8-39.${LINUX_RPM_ARCH}.rpm \
		ncurses-5.4-13.${LINUX_RPM_ARCH}.rpm \
		pcre-4.5-3.1.1.fc3.${LINUX_RPM_ARCH}.rpm \
		popt-1.9.1-21.${LINUX_RPM_ARCH}.rpm \
		readline-4.3-13.${LINUX_RPM_ARCH}.rpm \
		rpm-4.3.2-21.${LINUX_RPM_ARCH}.rpm \
		setserial-2.17-17.${LINUX_RPM_ARCH}.rpm \
		setup-2.5.36-1.noarch.rpm \
		slang-1.4.9-13.${LINUX_RPM_ARCH}.rpm \
		termcap-5.4-4fc3.noarch.rpm \
		zlib-1.2.1.2-3.fc3.${LINUX_RPM_ARCH}.rpm

.if defined(PACKAGE_BUILDING)
SRC_DISTFILES+= basesystem-8.0-4.src.rpm \
		bash-3.0-18.src.rpm \
		bzip2-1.0.2-13.src.rpm \
		compat-db-4.1.25-6.src.rpm \
		coreutils-5.2.1-31.src.rpm \
		db4-4.2.52-6.src.rpm \
		elfutils-0.96-1.src.rpm \
		fedora-release-3-8.src.rpm \
		filesystem-2.3.0-1.src.rpm \
		freetype-2.1.9-1.src.rpm \
		gcc-3.4.4-2.fc3.src.rpm \
		gdbm-1.8.0-24.src.rpm \
		glib-1.2.10-15.src.rpm \
		glibc-2.3.6-0.fc3.1.src.rpm \
		grep-2.5.1-31.src.rpm \
		libselinux-1.19.1-8.src.rpm \
		libtermcap-2.0.8-39.src.rpm \
		ncurses-5.4-13.src.rpm \
		pcre-4.5-3.src.rpm \
		readline-4.3-13.src.rpm \
		rpm-4.3.2-21.src.rpm \
		setserial-2.17-17.src.rpm \
		setup-2.5.36-1.src.rpm \
		slang-1.4.9-13.src.rpm \
		termcap-5.4-4fc3.src.rpm \
		zlib-1.2.1.2-3.fc3.src.rpm

ALWAYS_KEEP_DISTFILES=  yes
.endif

CONFLICTS=		linux_base-7* linux_base-deb* linux_base-gentoo* \
			linux_base-rh-9* linux_base-suse-9* linux_base-8* \
			linux-libgcc*
ONLY_FOR_ARCHS=		i386 amd64
LINUX_RPM_ARCH=		i386
PREFIX?=		${LINUXBASE}
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
NO_WRKSUBDIR=		yes
MD5_FILE?=		${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}
PLIST_SUB=		GLIBCVER="2.3.6"

RPM2CPIO?=			${LOCALBASE}/bin/rpm2cpio

EXTRACT_DEPENDS+=		${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_ONLY=		${BIN_DISTFILES}
EXTRACT_CMD?=		${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

PLIST=			pkg-plist

.include <bsd.port.pre.mk>

REMOVE_DIRS=		boot dev home initrd root tmp var/run var/tmp usr/tmp \
			usr/local
REMOVE_FILES=		bin/df bin/su etc/exports etc/group etc/localtime \
			etc/motd etc/passwd etc/printcap etc/services \
			etc/protocols
ADD_FILES=		var/lib/rpm/packages.rpm \
			var/lib/rpm/nameindex.rpm \
			var/lib/rpm/fileindex.rpm \
			var/lib/rpm/providesindex.rpm \
			var/lib/rpm/requiredby.rpm \
			var/lib/rpm/conflictsindex.rpm \
			var/lib/rpm/groupindex.rpm \
			var/lib/rpm/triggerindex.rpm

.if (${MACHINE_ARCH} == "amd64")
FALLBACK_ELF_MIB=	kern.elf32.fallback_brand
.else
FALLBACK_ELF_MIB=	kern.fallback_elf_brand
.endif

.if (${ARCH} == "amd64")
LATEST_LINK:=		${LATEST_LINK:C/linux/linux32/}
ARCH=			i386
.endif

do-build:
	@for D in ${REMOVE_DIRS}; do \
		${RM} -rf ${WRKSRC}/$$D; \
	done
	@for F in ${REMOVE_FILES}; do \
		${RM} -f ${WRKSRC}/$$F; \
	done
	@for F in ${ADD_FILES}; do \
		${TOUCH} ${WRKSRC}/$$F; \
	done
#
# Create a good ld.so.conf and touch ld.so.cache
#
	@${ECHO_CMD} -e '/lib\n/usr/lib\n${X11BASE}/lib' >> \
		${WRKSRC}/etc/ld.so.conf
	@${TOUCH} ${WRKSRC}/etc/ld.so.cache
#
# Create yp.conf as a hint to NIS users and make sure there's a
# mtab in etc, albeit an empty one. This is needed in a couple of
# cases. Most notably staroffice6. If yp.conf exists install only
# yp.conf.sample
#
	@${INSTALL} ${COPY} -m 644 ${FILESDIR}/yp.conf.sample ${WRKSRC}/etc
	@${TOUCH} ${WRKSRC}/etc/mtab
#
# If ${PREFIX}/etc/nsswitch.conf exists, don't touch it,
# install only ${PREFIX}/etc/nsswitch.conf.dist
#
	@${MV} ${WRKSRC}/etc/nsswitch.conf ${WRKSRC}/etc/nsswitch.conf.dist

do-install:
#
# Handle the loading of the linux loadable kernel module if required.
#
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
#
# Do install without using linux rpm system
#
	@cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${PREFIX}/{}" \;
	@cd ${WRKSRC} && ${FIND} * ! -type d \
		| ${CPIO} -pm -R root:wheel ${PREFIX}

	@${FIND} ${PREFIX}/bin ${PREFIX}/sbin/ ${PREFIX}/usr/bin \
		${PREFIX}/usr/sbin -type f -print0 | ${XARGS} -0 ${FILE} \
		| ${GREP} ELF | ${CUT} -d : -f 1 \
		| ${XARGS} ${BRANDELF} -t Linux
	@${LN} -sf /var/tmp ${PREFIX}/usr/tmp
	@${CHOWN} root:wheel ${PREFIX}/var/lock ${PREFIX}/var/spool/mail
	@${CHMOD} 755 ${PREFIX}/var/lock ${PREFIX}/var/spool/mail

post-install:
#
# Handle mounting linux procfs if exists at /etc/fstab and
# installing etc/nsswitch.conf, etc/yp.conf if so far they don't exist
#
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
#
# And finally show the pkg-message
#
	@${ECHO} ''
	@${CAT} ${PKGMESSAGE}
	@${ECHO} ''

.include <bsd.port.post.mk>
