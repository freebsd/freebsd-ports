# New ports collection makefile for:	linux_base-fc4
# Date created:				2006-31-05
# Whom:					bsam@ipt.ru
# based on ports/emulators/linux_base-fc3 by netchild and myself
#
# $FreeBSD$
#

PORTNAME=		fc
PORTVERSION=		4
PORTREVISION=		16
CATEGORIES=		emulators linux
MASTER_SITES=		CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${PORTVERSION}
PKGNAMEPREFIX=		linux_base-
DISTFILES=		${BIN_DISTFILES} ${SRC_DISTFILES}
DIST_SUBDIR=		rpm/${LINUX_RPM_ARCH}/fedora/${PORTVERSION}
EXTRACT_ONLY=		${BIN_DISTFILES}

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Base set of packages needed in Linux mode (for i386/amd64)

BIN_DISTFILES=	basesystem-8.0-5.noarch.rpm \
		bash-3.0-31.${LINUX_RPM_ARCH}.rpm \
		bzip2-1.0.2-16.${LINUX_RPM_ARCH}.rpm \
		bzip2-libs-1.0.2-16.${LINUX_RPM_ARCH}.rpm \
		compat-db-4.2.52-3.fc4.${LINUX_RPM_ARCH}.rpm \
		compat-libstdc++-296-2.96-132.fc4.${LINUX_RPM_ARCH}.rpm \
		compat-libstdc++-33-3.2.3-47.fc4.${LINUX_RPM_ARCH}.rpm \
		coreutils-5.2.1-48.1.${LINUX_RPM_ARCH}.rpm \
		db4-4.3.27-5.fc4.${LINUX_RPM_ARCH}.rpm \
		e2fsprogs-1.38-0.FC4.1.${LINUX_RPM_ARCH}.rpm \
		elfutils-libelf-0.108-1.${LINUX_RPM_ARCH}.rpm \
		fedora-release-4-2.noarch.rpm \
		filesystem-2.3.4-1.${LINUX_RPM_ARCH}.rpm \
		freetype-2.1.9-2.${LINUX_RPM_ARCH}.rpm \
		gdbm-1.8.0-25.${LINUX_RPM_ARCH}.rpm \
		glib-1.2.10-16.${LINUX_RPM_ARCH}.rpm \
		glib2-2.6.6-1.${LINUX_RPM_ARCH}.rpm \
		glibc-2.3.6-3.${LINUX_RPM_ARCH}.rpm \
		glibc-common-2.3.6-3.${LINUX_RPM_ARCH}.rpm \
		grep-2.5.1-48.2.${LINUX_RPM_ARCH}.rpm \
		info-4.8-8.fc4.2.${LINUX_RPM_ARCH}.rpm \
		krb5-libs-1.4.1-5.${LINUX_RPM_ARCH}.rpm \
		libacl-2.2.32-1.FC4.2.${LINUX_RPM_ARCH}.rpm \
		libattr-2.4.24-1.FC4.1.${LINUX_RPM_ARCH}.rpm \
		libgcc-4.0.2-8.fc4.${LINUX_RPM_ARCH}.rpm \
		libselinux-1.23.11-1.1.${LINUX_RPM_ARCH}.rpm \
		libstdc++-4.0.2-8.fc4.${LINUX_RPM_ARCH}.rpm \
		libtermcap-2.0.8-41.${LINUX_RPM_ARCH}.rpm \
		ncurses-5.4-19.fc4.${LINUX_RPM_ARCH}.rpm \
		pcre-5.0-4.1.fc4.${LINUX_RPM_ARCH}.rpm \
		popt-1.10.1-23.${LINUX_RPM_ARCH}.rpm \
		readline-5.0-3.${LINUX_RPM_ARCH}.rpm \
		setserial-2.17-19.${LINUX_RPM_ARCH}.rpm \
		setup-2.5.44-1.1.noarch.rpm \
		slang-1.4.9-17.${LINUX_RPM_ARCH}.rpm \
		termcap-5.4-7fc4.noarch.rpm \
		zlib-1.2.2.2-5.fc4.${LINUX_RPM_ARCH}.rpm

.if defined(PACKAGE_BUILDING)

SRC_DISTFILES+=	acl-2.2.32-1.FC4.2.src.rpm \
		attr-2.4.24-1.FC4.1.src.rpm \
		basesystem-8.0-5.src.rpm \
		bash-3.0-31.src.rpm \
		bzip2-1.0.2-16.src.rpm \
		compat-db-4.2.52-3.fc4.src.rpm \
		coreutils-5.2.1-48.1.src.rpm \
		db4-4.3.27-5.fc4.src.rpm \
		e2fsprogs-1.38-0.FC4.1.src.rpm \
		elfutils-0.108-1.src.rpm \
		fedora-release-4-2.src.rpm \
		filesystem-2.3.4-1.src.rpm \
		freetype-2.1.9-2.src.rpm \
		gcc-4.0.2-8.fc4.src.rpm \
		gdbm-1.8.0-25.src.rpm \
		glib-1.2.10-16.src.rpm \
		glib2-2.6.6-1.src.rpm \
		glibc-2.3.6-3.src.rpm \
		grep-2.5.1-48.2.src.rpm \
		krb5-1.4.1-5.src.rpm \
		libselinux-1.23.11-1.1.src.rpm \
		libtermcap-2.0.8-41.src.rpm \
		ncurses-5.4-19.fc4.src.rpm \
		pcre-5.0-4.1.fc4.src.rpm \
		readline-5.0-3.src.rpm \
		setserial-2.17-19.src.rpm \
		setup-2.5.44-1.1.src.rpm \
		slang-1.4.9-17.src.rpm \
		termcap-5.4-7fc4.src.rpm \
		zlib-1.2.2.2-5.fc4.src.rpm

ALWAYS_KEEP_DISTFILES=	yes
.endif

LATEST_LINK=		linux_base
CONFLICTS=		linux_base-gentoo* linux_locale* \
			linux_base-f8* linux_base-f7* linux_base-fc6*
ONLY_FOR_ARCHS=		i386 amd64
LINUX_RPM_ARCH=		i386
USE_LINUX_PREFIX=	yes
NO_WRKSUBDIR=		yes
DISTINFO_FILE?=		${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}
PLIST_SUB=		GLIBCVER="2.3.6"

RPM2CPIO?=		${LOCALBASE}/bin/rpm2cpio

EXTRACT_DEPENDS+=	${RPM2CPIO}:${PORTSDIR}/archivers/rpm

EXTRACT_ONLY=		${BIN_DISTFILES}
EXTRACT_CMD?=		${RPM2CPIO}
EXTRACT_BEFORE_ARGS?=
EXTRACT_AFTER_ARGS?=	| ${CPIO} -id --quiet

.include <bsd.port.pre.mk>

REMOVE_DIRS=		boot dev home initrd media root tmp var/log var/run var/tmp \
			usr/local usr/tmp
REMOVE_FILES=		bin/df bin/su etc/exports etc/group etc/localtime \
			etc/motd etc/passwd etc/printcap etc/services \
			etc/protocols
ADD_FILES=		# empty

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
	@${MV} ${WRKSRC}/etc/krb5.conf ${WRKSRC}/etc/krb5.conf.dist

# Fix usr/bin/*db4* permissions to allow "portupgrade -s"
	@${CHMOD} u+w ${WRKSRC}/usr/bin/*db4*

	@${FIND} ${WRKSRC}/bin ${WRKSRC}/sbin/ ${WRKSRC}/usr/bin \
		${WRKSRC}/usr/sbin -type f -print0 | ${XARGS} -0 ${FILE} \
		| ${GREP} ELF | ${CUT} -d : -f 1 \
		| ${XARGS} ${BRANDELF} -t Linux
	@${BRANDELF} -t Linux ${WRKSRC}/lib/ld-2.3.6.so

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
#
# Let some linux applications (e.g. print/acroread8) print with default settings
#
	@${INSTALL_SCRIPT} ${FILESDIR}/lp ${PREFIX}/usr/bin
#
# Create a hard link to disallow using a FreeBSD native library, but find a
# linux one at /lib/obsolete/linuxthreads; soft link happened to be insufficient
#
	@${LN} -f ${PREFIX}/lib/librt-2.3.6.so ${PREFIX}/usr/lib/librt.so.1

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
