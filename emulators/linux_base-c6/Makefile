# Created by: Svyatoslav Lempert <svyatoslav.lempert@gmail dot com>
# $FreeBSD$

PORTNAME=	c6
PORTVERSION=	6.7
PORTREVISION=	1
CATEGORIES=	emulators linux
MASTER_SITES=	CENTOS_LINUX CENTOS_LINUX_UPDATES
MASTER_SITE_SUBDIR=	centos/${LINUX_DIST_VER}/os/${LINUX_REPO_ARCH}/Packages/\
			centos/${LINUX_DIST_VER}/updates/${LINUX_REPO_ARCH}/Packages/

PKGNAMEPREFIX=	linux_base-
DISTFILES=	${PRE_BIN_DISTFILES} ${BIN_DISTFILES} ${SRC_DISTFILES}
EXTRACT_ONLY=	${BIN_DISTFILES}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Base set of packages needed in Linux mode for i386/amd64 (Linux CentOS 6)

LINUX_DIST=	centos
LINUX_DIST_VER= ${PORTVERSION}
DIST_SUBDIR=	rpm/${LINUX_RPM_ARCH}/${LINUX_DIST}/${LINUX_DIST_VER}

# these get extracted from pre-extract, then some directory permissions
# get fixed up
PRE_BIN_DISTFILES=	filesystem-2.4.30-3.el6.${LINUX_RPM_ARCH}.rpm \
			setup-2.8.14-20.el6_4.1.noarch.rpm

BIN_DISTFILES=	basesystem-10.0-4.el6.noarch.rpm \
		bash-4.1.2-33.el6_7.1.${LINUX_RPM_ARCH}.rpm \
		bzip2-1.0.5-7.el6_0.${LINUX_RPM_ARCH}.rpm \
		centos-release-6-7.el6.centos.12.3.${LINUX_RPM_ARCH}.rpm \
		coreutils-8.4-37.el6_7.3.${LINUX_RPM_ARCH}.rpm \
		e2fsprogs-1.41.12-22.el6.${LINUX_RPM_ARCH}.rpm \
		elfutils-0.161-3.el6.${LINUX_RPM_ARCH}.rpm \
		findutils-4.4.2-6.el6.${LINUX_RPM_ARCH}.rpm \
		glibc-common-2.12-1.166.el6_7.7.${LINUX_RPM_ARCH}.rpm \
		grep-2.20-3.el6_7.1.${LINUX_RPM_ARCH}.rpm \
		info-4.13a-8.el6.${LINUX_RPM_ARCH}.rpm \
		keyutils-1.4-5.el6.${LINUX_RPM_ARCH}.rpm \
		less-436-13.el6.${LINUX_RPM_ARCH}.rpm \
		ncurses-5.7-4.20090207.el6.${LINUX_RPM_ARCH}.rpm \
		sed-4.2.1-10.el6.${LINUX_RPM_ARCH}.rpm \
		setserial-2.17-25.el6.${LINUX_RPM_ARCH}.rpm \
		which-2.19-6.el6.${LINUX_RPM_ARCH}.rpm \
		compat-libstdc++-296-2.96-144.el6.i686.rpm
LIB_DISTFILES=	bzip2-libs-1.0.5-7.el6_0.${LINUX_RPM_ARCH}.rpm \
		compat-db43-4.3.29-15.el6.${LINUX_RPM_ARCH}.rpm \
		compat-libstdc++-33-3.2.3-69.el6.${LINUX_RPM_ARCH}.rpm \
		db4-4.7.25-20.el6_7.${LINUX_RPM_ARCH}.rpm \
		e2fsprogs-libs-1.41.12-22.el6.${LINUX_RPM_ARCH}.rpm \
		freetype-2.3.11-15.el6_6.1.${LINUX_RPM_ARCH}.rpm \
		gamin-0.1.10-9.el6.${LINUX_RPM_ARCH}.rpm \
		gdbm-1.8.0-38.el6.${LINUX_RPM_ARCH}.rpm \
		glib2-2.28.8-4.el6.${LINUX_RPM_ARCH}.rpm \
		glibc-2.12-1.166.el6_7.7.${LINUX_RPM_ARCH}.rpm \
		gmp-4.3.1-7.el6_2.2.${LINUX_RPM_ARCH}.rpm \
		keyutils-libs-1.4-5.el6.${LINUX_RPM_ARCH}.rpm \
		krb5-libs-1.10.3-42.el6.${LINUX_RPM_ARCH}.rpm \
		libacl-2.2.49-6.el6.${LINUX_RPM_ARCH}.rpm \
		libattr-2.4.44-7.el6.${LINUX_RPM_ARCH}.rpm \
		libblkid-2.17.2-12.18.el6.${LINUX_RPM_ARCH}.rpm \
		libcap-2.16-5.5.el6.${LINUX_RPM_ARCH}.rpm \
		libcom_err-1.41.12-22.el6.${LINUX_RPM_ARCH}.rpm \
		libgcc-4.4.7-16.el6.${LINUX_RPM_ARCH}.rpm \
		libidn-1.18-2.el6.${LINUX_RPM_ARCH}.rpm \
		libselinux-2.0.94-5.8.el6.${LINUX_RPM_ARCH}.rpm \
		libsepol-2.0.41-4.el6.${LINUX_RPM_ARCH}.rpm \
		libstdc++-4.4.7-16.el6.${LINUX_RPM_ARCH}.rpm \
		libuuid-2.17.2-12.18.el6.${LINUX_RPM_ARCH}.rpm \
		ncurses-libs-5.7-4.20090207.el6.${LINUX_RPM_ARCH}.rpm \
		pcre-7.8-7.el6.${LINUX_RPM_ARCH}.rpm \
		popt-1.13-7.el6.${LINUX_RPM_ARCH}.rpm \
		readline-6.0-4.el6.${LINUX_RPM_ARCH}.rpm \
		redhat-lsb-core-4.0-7.el6.centos.${LINUX_RPM_ARCH}.rpm \
		slang-2.2.1-1.el6.${LINUX_RPM_ARCH}.rpm \
		util-linux-ng-2.17.2-12.18.el6.${LINUX_RPM_ARCH}.rpm \
		zlib-1.2.3-29.el6.${LINUX_RPM_ARCH}.rpm

BIN_DISTFILES+=	${LIB_DISTFILES}


.if defined(PACKAGE_BUILDING)
SRC_DISTFILES=	basesystem-10.0-4.el6.src.rpm:SOURCE \
		bash-4.1.2-33.el6_7.1.src.rpm:SOURCE \
		bzip2-1.0.5-7.el6_0.src.rpm:SOURCE \
		coreutils-8.4-37.el6_7.3.src.rpm:SOURCE \
		compat-db-4.6.21-15.el6.src.rpm:SOURCE \
		compat-gcc-296-2.96-144.el6.src.rpm:SOURCE \
		compat-gcc-32-3.2.3-69.el6.src.rpm:SOURCE \
		db4-4.7.25-20.el6_7.src.rpm:SOURCE \
		e2fsprogs-1.41.12-22.el6.src.rpm:SOURCE \
		elfutils-0.161-3.el6.src.rpm:SOURCE \
		centos-release-6-7.el6.centos.12.3.src.rpm:SOURCE \
		filesystem-2.4.30-3.el6.src.rpm:SOURCE \
		findutils-4.4.2-6.el6.src.rpm:SOURCE \
		freetype-2.3.11-15.el6_6.1.src.rpm:SOURCE \
		gamin-0.1.10-9.el6.src.rpm:SOURCE \
		gdbm-1.8.0-38.el6.src.rpm:SOURCE \
		glib2-2.28.8-4.el6.src.rpm:SOURCE \
		glibc-2.12-1.166.el6_7.7.src.rpm:SOURCE \
		gmp-4.3.1-7.el6_2.2.src.rpm:SOURCE \
		grep-2.20-3.el6_7.1.src.rpm:SOURCE \
		texinfo-4.13a-8.el6.src.rpm:SOURCE \
		keyutils-1.4-5.el6.src.rpm:SOURCE \
		krb5-1.10.3-42.el6.src.rpm:SOURCE \
		less-436-13.el6.src.rpm:SOURCE \
		acl-2.2.49-6.el6.src.rpm:SOURCE \
		attr-2.4.44-7.el6.src.rpm:SOURCE \
		libcap-2.16-5.5.el6.src.rpm:SOURCE \
		gcc-4.4.7-16.el6.src.rpm:SOURCE \
		libidn-1.18-2.el6.src.rpm:SOURCE \
		libselinux-2.0.94-5.8.el6.src.rpm:SOURCE \
		libsepol-2.0.41-4.el6.src.rpm:SOURCE \
		ncurses-5.7-4.20090207.el6.src.rpm:SOURCE \
		pcre-7.8-7.el6.src.rpm:SOURCE \
		popt-1.13-7.el6.src.rpm:SOURCE \
		readline-6.0-4.el6.src.rpm:SOURCE \
		redhat-lsb-4.0-7.el6.centos.src.rpm:SOURCE \
		sed-4.2.1-10.el6.src.rpm:SOURCE \
		setserial-2.17-25.el6.src.rpm:SOURCE \
		setup-2.8.14-20.el6_4.1.src.rpm:SOURCE \
		slang-2.2.1-1.el6.src.rpm:SOURCE \
		util-linux-ng-2.17.2-12.18.el6.src.rpm:SOURCE \
		which-2.19-6.el6.src.rpm:SOURCE \
		zlib-1.2.3-29.el6.src.rpm:SOURCE

ALWAYS_KEEP_DISTFILES=	yes
.endif

CONFLICTS=		linux_base-gentoo* linux_base-f10-[0-9]* linux-glib2-*

ONLY_FOR_ARCHS=		i386 amd64
.	if defined(OVERRIDE_LINUX_BASE_PORT) && ${OVERRIDE_LINUX_BASE_PORT} == "c6_64"
PKGNAMESUFFIX=		_64
LINUX_RPM_ARCH=	x86_64
LINUX_REPO_ARCH=	x86_64

# hack to add i686 distfiles

_32BIT_LINUX_RPM_ARCH=  i686
_32BIT_DISTFILES=   ${LIB_DISTFILES:S/${LINUX_RPM_ARCH}/${_32BIT_LINUX_RPM_ARCH}/g}
.       if ${_32BIT_DISTFILES} != ${LIB_DISTFILES}
# they could be the same if above regexp doesn't match
BIN_DISTFILES+=         ${_32BIT_DISTFILES}
.       endif


.	else
LINUX_RPM_ARCH=		i686
LINUX_REPO_ARCH=	i386
.	endif


USE_LINUX_PREFIX=	yes
NO_WRKSUBDIR=		yes
DISTINFO_FILE?=		${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}
PLIST=			${MASTERDIR}/pkg-plist.${LINUX_RPM_ARCH}
PLIST_SUB=		GLIBCVER="2.12" LINUXBASE=${LINUXBASE}
USES=	shebangfix
SHEBANG_FILES=	bin/redhat_lsb_init sbin/mount.tmpfs
# bash scripts need to work in chroot /compat/linux, so use env instead.
bash_CMD=	/usr/bin/env bash

.include <bsd.port.pre.mk>

.if !defined(PACKAGE_BUILDING) || (defined(PACKAGE_BUILDING) && !defined(LINUX_OSRELEASE) )
LINUX_OSRELEASE!=	${ECHO_CMD} `${SYSCTL} -n compat.linux.osrelease 2>/dev/null`
.endif

.if ${LINUX_OSRELEASE}x == "x"
IGNORE=			linuxulator is not (kld)loaded
.elif ${LINUX_OSRELEASE} == "2.6.16"
IGNORE=			compat.linux.osrelease: ${LINUX_OSRELEASE} is not supported, please use 2.6.18, BEWARE this is highly experimental
.endif

REMOVE_DIRS=		boot dev etc/fonts home initrd media root tmp var/log var/run var/tmp \
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
.	if defined(OVERRIDE_LINUX_BASE_PORT) && ${OVERRIDE_LINUX_BASE_PORT} != "c6_64"
ARCH=			i386
.	endif
.endif

pre-extract:
	@for file in ${PRE_BIN_DISTFILES}; do \
	    if ! (cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$file ${EXTRACT_AFTER_ARGS});\
	    then \
	        exit 1; \
	    fi; \
	done
	# now fix up broken permissions
.	if defined(OVERRIDE_LINUX_BASE_PORT) && ${OVERRIDE_LINUX_BASE_PORT} == "c6_64"
	@${CHMOD} -R u+rwX ${WRKSRC}/lib64 ${WRKSRC}/usr/lib64
.	endif
	@${CHMOD} -R u+rwX ${WRKSRC}/bin ${WRKSRC}/lib ${WRKSRC}/sbin ${WRKSRC}/usr/bin ${WRKSRC}/usr/lib ${WRKSRC}/usr/sbin
	@${CHMOD} 400 ${WRKSRC}/etc/*shadow

do-build:
	@for D in ${REMOVE_DIRS}; do \
		${RM} -rf ${WRKSRC}/$$D; \
	done
	@for F in ${REMOVE_FILES}; do \
		${RM} -f ${WRKSRC}/$$F; \
	done
	@for F in ${ADD_DIRS}; do \
		${MKDIR} ${WRKSRC}/$$F; \
	done
	@for F in ${ADD_FILES}; do \
		${TOUCH} ${WRKSRC}/$$F; \
	done
#
# Create a good ld.so.conf and touch ld.so.cache
#
	@${ECHO_CMD} -e '/lib\n/usr/lib\n/usr/lib64\n${X11BASE}/lib' >> \
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
# If ${PREFIX}/etc/krb5.conf exists, don't touch it
#
	@${MV} ${WRKSRC}/etc/krb5.conf ${WRKSRC}/etc/krb5.conf.sample

	@${FIND} ${WRKSRC}/bin ${WRKSRC}/sbin/ ${WRKSRC}/usr/bin \
		${WRKSRC}/usr/sbin -type f -print0 | ${XARGS} -0 ${FILE} \
		| ${GREP} ELF | ${CUT} -d : -f 1 \
		| ${XARGS} ${BRANDELF} -t Linux
.	if defined(OVERRIDE_LINUX_BASE_PORT) && ${OVERRIDE_LINUX_BASE_PORT} == "c6_64"
	@${BRANDELF} -t Linux ${WRKSRC}/lib64/ld-2.12.so
.	else
	@${BRANDELF} -t Linux ${WRKSRC}/lib/ld-2.12.so
.	endif

# Install locales
	@${MV} ${WRKSRC}/usr/lib/locale/locale-archive.tmpl \
		${WRKSRC}/usr/lib/locale/locale-archive

do-install:
#
# Do install without using linux rpm system
#
	@cd ${WRKSRC} && ${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${PREFIX}/{}" \;
	@cd ${WRKSRC} && ${FIND} * ! -type d \
		| ${CPIO} -pm -R root:wheel ${STAGEDIR}${PREFIX}

	@${LN} -sf /var/tmp ${STAGEDIR}${PREFIX}/usr/tmp
	@${LN} -sf ../usr/bin/[ ${STAGEDIR}${PREFIX}/bin/[
	@${LN} -sf ../usr/bin/expr ${STAGEDIR}${PREFIX}/bin/expr
	@${LN} -sf ../usr/bin/test ${STAGEDIR}${PREFIX}/bin/test
	@${LN} -sf ../usr/bin/uuidgen ${STAGEDIR}${PREFIX}/bin/uuidgen
	@${LN} -sf ../../lib/librt.so.1 ${STAGEDIR}${PREFIX}/usr/lib/librt.so.1
	@${CHMOD} 755 ${STAGEDIR}${PREFIX}/var/lock ${STAGEDIR}${PREFIX}/var/spool/mail
#
# Let some linux applications (e.g. print/acroread8) print with default settings
#
	@${INSTALL_SCRIPT} ${FILESDIR}/lp ${STAGEDIR}${PREFIX}/usr/bin

.include <bsd.port.post.mk>
