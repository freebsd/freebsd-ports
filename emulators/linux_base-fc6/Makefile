# New ports collection makefile for:	linux_base-fc6
# Date created:				16 Jan 2007
# Whom:					Boris Samorodov <bsam@FreeBSD.org>
# Based on ports/emulators/linux_base-fc4 by netchild and myself
#
# $FreeBSD$
#

PORTNAME=		fc6
PORTVERSION=		6
PORTREVISION=		6
CATEGORIES=		emulators linux
MASTER_SITES=		${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR=	${PORTVERSION}/${LINUX_RPM_ARCH}/os/Fedora/RPMS \
			updates/${PORTVERSION}/${LINUX_RPM_ARCH}
PKGNAMEPREFIX=		linux_base-
DISTFILES=		${BIN_DISTFILES} ${SRC_DISTFILES}
DIST_SUBDIR=		rpm/${LINUX_RPM_ARCH}/fedora/${PORTVERSION}
EXTRACT_ONLY=		${BIN_DISTFILES}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Base set of packages needed in Linux mode (for i386/amd64)

BIN_DISTFILES=	basesystem-8.0-5.1.1.noarch.rpm \
		bash-3.1-16.1.${LINUX_RPM_ARCH}.rpm \
		bzip2-1.0.3-6.fc6.${LINUX_RPM_ARCH}.rpm \
		bzip2-libs-1.0.3-6.fc6.${LINUX_RPM_ARCH}.rpm \
		compat-db-4.2.52-5.1.${LINUX_RPM_ARCH}.rpm \
		compat-libstdc++-296-2.96-138.${LINUX_RPM_ARCH}.rpm \
		compat-libstdc++-33-3.2.3-61.${LINUX_RPM_ARCH}.rpm \
		coreutils-5.97-12.5.fc6.${LINUX_RPM_ARCH}.rpm \
		db4-4.3.29-9.fc6.${LINUX_RPM_ARCH}.rpm \
		e2fsprogs-1.39-7.fc6.${LINUX_RPM_ARCH}.rpm \
		elfutils-libelf-0.128-2.fc6.${LINUX_RPM_ARCH}.rpm \
		fedora-release-6-4.noarch.rpm \
		filesystem-2.4.0-1.${LINUX_RPM_ARCH}.rpm \
		freetype-2.2.1-17.fc6.${LINUX_RPM_ARCH}.rpm \
		gdbm-1.8.0-26.2.1.${LINUX_RPM_ARCH}.rpm \
		glib2-2.12.9-1.fc6.${LINUX_RPM_ARCH}.rpm \
		glibc-2.5-18.fc6.${LINUX_RPM_ARCH}.rpm \
		glibc-common-2.5-18.fc6.${LINUX_RPM_ARCH}.rpm \
		grep-2.5.1-54.1.2.fc6.${LINUX_RPM_ARCH}.rpm \
		info-4.8-14.fc6.${LINUX_RPM_ARCH}.rpm \
		krb5-libs-1.5-21.1.${LINUX_RPM_ARCH}.rpm \
		libacl-2.2.39-1.1.${LINUX_RPM_ARCH}.rpm \
		libattr-2.4.32-1.1.${LINUX_RPM_ARCH}.rpm \
		libgcc-4.1.2-13.fc6.${LINUX_RPM_ARCH}.rpm \
		libselinux-1.33.4-2.fc6.${LINUX_RPM_ARCH}.rpm \
		libsepol-1.15.3-1.fc6.${LINUX_RPM_ARCH}.rpm \
		libstdc++-4.1.2-13.fc6.${LINUX_RPM_ARCH}.rpm \
		libtermcap-2.0.8-46.1.${LINUX_RPM_ARCH}.rpm \
		ncurses-5.5-24.20060715.${LINUX_RPM_ARCH}.rpm \
		pcre-6.6-1.1.${LINUX_RPM_ARCH}.rpm \
		popt-1.10.2-33.fc6.${LINUX_RPM_ARCH}.rpm \
		readline-5.1-1.1.${LINUX_RPM_ARCH}.rpm \
		setserial-2.17-19.2.2.${LINUX_RPM_ARCH}.rpm \
		setup-2.6.1.1-1.fc6.noarch.rpm \
		slang-2.0.7-1.fc6.${LINUX_RPM_ARCH}.rpm \
		termcap-5.5-1.20060701.1.noarch.rpm \
		zlib-1.2.3-3.${LINUX_RPM_ARCH}.rpm

.if defined(PACKAGE_BUILDING)

MASTER_SITE_SUBDIR+=	${PORTVERSION}/source/SRPMS \
			updates/${PORTVERSION}/SRPMS

SRC_DISTFILES+=	acl-2.2.39-1.1.src.rpm \
		attr-2.4.32-1.1.src.rpm \
		basesystem-8.0-5.1.1.src.rpm \
		bash-3.1-16.1.src.rpm \
		bzip2-1.0.3-6.fc6.src.rpm \
		compat-db-4.2.52-5.1.src.rpm \
		coreutils-5.97-12.5.fc6.src.rpm \
		db4-4.3.29-9.fc6.src.rpm \
		e2fsprogs-1.39-7.fc6.src.rpm \
		elfutils-0.128-2.fc6.src.rpm \
		fedora-release-6-4.src.rpm \
		filesystem-2.4.0-1.src.rpm \
		freetype-2.2.1-17.fc6.src.rpm \
		gcc-4.1.2-13.fc6.src.rpm \
		gdbm-1.8.0-26.2.1.src.rpm \
		glib2-2.12.9-1.fc6.src.rpm \
		glibc-2.5-18.fc6.src.rpm \
		grep-2.5.1-54.1.2.fc6.src.rpm \
		krb5-1.5-21.1.src.rpm \
		libselinux-1.33.4-2.fc6.src.rpm \
		libsepol-1.15.3-1.fc6.src.rpm \
		libtermcap-2.0.8-46.1.src.rpm \
		ncurses-5.5-24.20060715.src.rpm \
		pcre-6.6-1.1.src.rpm \
		readline-5.1-1.1.src.rpm \
		setserial-2.17-19.2.2.src.rpm \
		setup-2.6.1.1-1.fc6.src.rpm \
		slang-2.0.7-1.fc6.src.rpm \
		termcap-5.5-1.20060701.1.src.rpm \
		zlib-1.2.3-3.src.rpm

ALWAYS_KEEP_DISTFILES=	yes
.endif

CONFLICTS=		linux_base-gentoo* linux_base-fc4
ONLY_FOR_ARCHS=		i386 amd64
LINUX_RPM_ARCH=		i386
USE_LINUX_PREFIX=	yes
NO_WRKSUBDIR=		yes
MD5_FILE?=		${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}
PLIST_SUB=		GLIBCVER="2.5"

RPM2CPIO?=		${LOCALBASE}/bin/rpm2cpio

EXTRACT_DEPENDS+=	${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_ONLY=		${BIN_DISTFILES}
EXTRACT_CMD?=		${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

.include <bsd.port.pre.mk>

LINUX_OSRELEASE!=	${ECHO_CMD} `${SYSCTL} -n compat.linux.osrelease 2>/dev/null`

.if ${LINUX_OSRELEASE}x == "x"
IGNORE=			linuxulator is not (kld)loaded
.elif ${LINUX_OSRELEASE} == "2.4.2"
IGNORE=			compat.linux.osrelease: 2.4.2 is not supported
.endif

REMOVE_DIRS=		boot dev home initrd media root tmp var/log var/run var/tmp \
			usr/local usr/tmp
REMOVE_FILES=		bin/df bin/su etc/exports etc/group etc/localtime \
			etc/motd etc/passwd etc/printcap etc/services \
			etc/protocols
ADD_FILES=		#empty

.if (${MACHINE_ARCH} == "amd64")
FALLBACK_ELF_MIB=	kern.elf32.fallback_brand
.else
FALLBACK_ELF_MIB=	kern.fallback_elf_brand
.endif

.if (${ARCH} == "amd64")
LATEST_LINK:=		${PKGBASE:C/linux/linux32/}
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
	@${MV} ${WRKSRC}/etc/krb5.conf ${WRKSRC}/etc/krb5.conf.dist

# Fix usr/bin/*db4* permissions to allow "portupgrade -s"
	@${CHMOD} u+w ${WRKSRC}/usr/bin/*db4*

	@${FIND} ${WRKSRC}/bin ${WRKSRC}/sbin/ ${WRKSRC}/usr/bin \
		${WRKSRC}/usr/sbin -type f -print0 | ${XARGS} -0 ${FILE} \
		| ${GREP} ELF | ${CUT} -d : -f 1 \
		| ${XARGS} ${BRANDELF} -t Linux
	@${BRANDELF} -t Linux ${WRKSRC}/lib/ld-2.5.so

# Restore the status quo for usr/bin/*db4* files
	@${CHMOD} u-w ${WRKSRC}/usr/bin/*db4*

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
