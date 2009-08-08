# New ports collection makefile for:	emulators/linux_base-f10
# Date created:				2009-04-30
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=		f10
PORTVERSION=		10
PORTREVISION=		1
CATEGORIES=		emulators linux
MASTER_SITES=		${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR=	../updates/${PORTVERSION}/${LINUX_RPM_ARCH} \
			../releases/${PORTVERSION}/Everything/${LINUX_RPM_ARCH}/os/Packages
PKGNAMEPREFIX=		linux_base-
DISTFILES=		${BIN_DISTFILES} ${SRC_DISTFILES}
DIST_SUBDIR=		rpm/${LINUX_RPM_ARCH}/fedora/${PORTVERSION}
EXTRACT_ONLY=		${BIN_DISTFILES}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Base set of packages needed in Linux mode for i386/amd64 (Linux Fedora 10)

BIN_DISTFILES=	basesystem-10.0-1.noarch.rpm \
		bash-3.2-30.fc10.${LINUX_RPM_ARCH}.rpm \
		bzip2-1.0.5-3.fc10.${LINUX_RPM_ARCH}.rpm \
		bzip2-libs-1.0.5-3.fc10.${LINUX_RPM_ARCH}.rpm \
		compat-db-4.6.21-5.fc10.${LINUX_RPM_ARCH}.rpm \
		compat-libstdc++-296-2.96-141.${LINUX_RPM_ARCH}.rpm \
		compat-libstdc++-33-3.2.3-64.${LINUX_RPM_ARCH}.rpm \
		coreutils-6.12-20.fc10.${LINUX_RPM_ARCH}.rpm \
		db4-4.7.25-7.fc10.${LINUX_RPM_ARCH}.rpm \
		e2fsprogs-1.41.4-6.fc10.${LINUX_RPM_ARCH}.rpm \
		e2fsprogs-libs-1.41.4-6.fc10.${LINUX_RPM_ARCH}.rpm \
		elfutils-0.141-1.fc10.${LINUX_RPM_ARCH}.rpm \
		fedora-release-10-1.noarch.rpm \
		filesystem-2.4.19-1.fc10.${LINUX_RPM_ARCH}.rpm \
		freetype-2.3.7-3.fc10.${LINUX_RPM_ARCH}.rpm \
		gdbm-1.8.0-29.fc10.${LINUX_RPM_ARCH}.rpm \
		glib-1.2.10-32.fc10.${LINUX_RPM_ARCH}.rpm \
		glib2-2.18.4-2.fc10.${LINUX_RPM_ARCH}.rpm \
		glibc-2.9-3.${LINUX_RPM_ARCH}.rpm \
		glibc-common-2.9-3.${LINUX_RPM_ARCH}.rpm \
		grep-2.5.1a-61.fc10.${LINUX_RPM_ARCH}.rpm \
		info-4.12-4.fc10.${LINUX_RPM_ARCH}.rpm \
		keyutils-libs-1.2-3.fc9.${LINUX_RPM_ARCH}.rpm \
		krb5-libs-1.6.3-18.fc10.${LINUX_RPM_ARCH}.rpm \
		libacl-2.2.47-3.fc10.${LINUX_RPM_ARCH}.rpm \
		libattr-2.4.43-2.fc10.${LINUX_RPM_ARCH}.rpm \
		libcap-2.10-2.fc10.${LINUX_RPM_ARCH}.rpm \
		libgcc-4.3.2-7.${LINUX_RPM_ARCH}.rpm \
		libidn-0.6.14-8.${LINUX_RPM_ARCH}.rpm \
		libselinux-2.0.78-1.fc10.${LINUX_RPM_ARCH}.rpm \
		libsepol-2.0.33-1.fc10.${LINUX_RPM_ARCH}.rpm \
		libstdc++-4.3.2-7.${LINUX_RPM_ARCH}.rpm \
		ncurses-5.6-20.20080927.fc10.${LINUX_RPM_ARCH}.rpm \
		ncurses-libs-5.6-20.20080927.fc10.${LINUX_RPM_ARCH}.rpm \
		pcre-7.8-1.fc10.${LINUX_RPM_ARCH}.rpm \
		popt-1.13-4.fc10.${LINUX_RPM_ARCH}.rpm \
		readline-5.2-13.fc9.${LINUX_RPM_ARCH}.rpm \
		setserial-2.17-22.fc9.${LINUX_RPM_ARCH}.rpm \
		setup-2.7.4-4.fc10.noarch.rpm \
		slang-2.1.4-1.fc10.${LINUX_RPM_ARCH}.rpm \
		zlib-1.2.3-18.fc9.${LINUX_RPM_ARCH}.rpm

.if defined(PACKAGE_BUILDING)

MASTER_SITE_SUBDIR+= ../updates/${PORTVERSION}/SRPMS \
		../releases/${PORTVERSION}/Everything/source/SRPMS/

SRC_DISTFILES+=	acl-2.2.47-3.fc10.src.rpm \
		attr-2.4.43-1.fc10.src.rpm \
		basesystem-10.0-1.src.rpm \
		bash-3.2-29.fc10.src.rpm \
		bzip2-1.0.5-3.fc10.src.rpm \
		compat-db-4.6.21-5.fc10.src.rpm \
		coreutils-6.12-17.fc10.src.rpm \
		db4-4.7.25-5.fc10.src.rpm \
		e2fsprogs-1.41.4-6.fc10.src.rpm \
		elfutils-0.141-1.fc10.src.rpm \
		fedora-release-10-1.src.rpm \
		filesystem-2.4.19-1.fc10.src.rpm \
		freetype-2.3.7-1.fc10.src.rpm \
		gcc-4.3.2-7.src.rpm \
		gdbm-1.8.0-29.fc10.src.rpm \
		glib-1.2.10-32.fc10.src.rpm \
		glib2-2.18.2-3.fc10.src.rpm \
		glibc-2.9-2.src.rpm \
		grep-2.5.1a-61.fc10.src.rpm \
		keyutils-1.2-3.fc9.src.rpm \
		krb5-1.6.3-16.fc10.src.rpm \
		libcap-2.10-2.fc10.src.rpm \
		libidn-0.6.14-8.src.rpm \
		libselinux-2.0.73-1.fc10.src.rpm \
		libsepol-2.0.33-1.fc10.src.rpm \
		ncurses-5.6-20.20080927.fc10.src.rpm \
		pcre-7.8-1.fc10.src.rpm \
		readline-5.2-13.fc9.src.rpm \
		setserial-2.17-22.fc9.src.rpm \
		setup-2.7.4-1.fc10.src.rpm \
		slang-2.1.4-1.fc10.src.rpm \
		texinfo-4.12-4.fc10.src.rpm \
		zlib-1.2.3-18.fc9.src.rpm

ALWAYS_KEEP_DISTFILES=	yes
.endif

CONFLICTS=		linux_base-gentoo* linux_base-fc4-[0-9]* linux_base-fc6-[0-9]* \
			linux_base-f7-[0-9]* linux_base-f8-[0-9]* linux_base-f9-[0-9]* linux-glib2-*
ONLY_FOR_ARCHS=		i386 amd64
LINUX_RPM_ARCH=		i386
USE_LINUX_PREFIX=	yes
NO_WRKSUBDIR=		yes
MD5_FILE?=		${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}
PLIST_SUB=		GLIBCVER="2.9"

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
IGNORE=			compat.linux.osrelease: 2.4.2 is not supported, please use 2.6.16
.endif

REMOVE_DIRS=		boot dev etc/fonts home initrd root tmp var/log var/run var/tmp \
			usr/local usr/tmp
REMOVE_FILES=		bin/df bin/su etc/exports etc/group etc/localtime \
			etc/motd etc/passwd etc/printcap etc/services \
			etc/protocols
ADD_DIRS=		usr/X11R6/share usr/X11R6/man usr/X11R6/lib/tls \
			usr/X11R6/include usr/X11R6/bin
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
	@for F in ${ADD_DIRS}; do \
		${MKDIR} -p ${WRKSRC}/$$F; \
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
#	@${CHMOD} u+w ${WRKSRC}/usr/bin/*db4*

	@${FIND} ${WRKSRC}/bin ${WRKSRC}/sbin/ ${WRKSRC}/usr/bin \
		${WRKSRC}/usr/sbin -type f -print0 | ${XARGS} -0 ${FILE} \
		| ${GREP} ELF | ${CUT} -d : -f 1 \
		| ${XARGS} ${BRANDELF} -t Linux
	@${BRANDELF} -t Linux ${WRKSRC}/lib/ld-2.9.so

# Restore the status quo for usr/bin/*db4* files
#	@${CHMOD} u-w ${WRKSRC}/usr/bin/*db4*

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
