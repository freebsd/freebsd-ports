# Created by: Svyatoslav Lempert <svyatoslav.lempert@gmail dot com>
# $FreeBSD$

PORTNAME=		c6
PORTVERSION=		6.2
CATEGORIES=		emulators linux
MASTER_SITES=		http://vault.centos.org/${PORTVERSION}/os/i386/Packages/
PKGNAMEPREFIX=		linux_base-
DISTFILES=		${BIN_DISTFILES} ${SRC_DISTFILES}
DIST_SUBDIR=		rpm/${LINUX_RPM_ARCH}/centos/${PORTVERSION}
EXTRACT_ONLY=		${BIN_DISTFILES}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Base set of packages needed in Linux mode for i386/amd64 (Linux CentOS 6.2)

BIN_DISTFILES=	basesystem-10.0-4.el6.noarch.rpm \
		bash-4.1.2-8.el6.centos.${LINUX_RPM_ARCH}.rpm \
		bzip2-1.0.5-7.el6_0.${LINUX_RPM_ARCH}.rpm \
		bzip2-libs-1.0.5-7.el6_0.${LINUX_RPM_ARCH}.rpm \
		compat-db43-4.3.29-15.el6.${LINUX_RPM_ARCH}.rpm \
		compat-libstdc++-33-3.2.3-69.el6.${LINUX_RPM_ARCH}.rpm \
		compat-libstdc++-296-2.96-144.el6.${LINUX_RPM_ARCH}.rpm \
		coreutils-8.4-16.el6.${LINUX_RPM_ARCH}.rpm \
		db4-4.7.25-16.el6.${LINUX_RPM_ARCH}.rpm \
		e2fsprogs-1.41.12-11.el6.${LINUX_RPM_ARCH}.rpm \
		e2fsprogs-libs-1.41.12-11.el6.${LINUX_RPM_ARCH}.rpm \
		elfutils-0.152-1.el6.${LINUX_RPM_ARCH}.rpm \
		centos-release-6-2.el6.centos.7.${LINUX_RPM_ARCH}.rpm \
		filesystem-2.4.30-3.el6.${LINUX_RPM_ARCH}.rpm \
		freetype-2.3.11-6.el6_1.7.${LINUX_RPM_ARCH}.rpm \
		gdbm-1.8.0-36.el6.${LINUX_RPM_ARCH}.rpm \
		glib2-2.22.5-6.el6.${LINUX_RPM_ARCH}.rpm \
		glibc-2.12-1.47.el6.${LINUX_RPM_ARCH}.rpm \
		glibc-common-2.12-1.47.el6.${LINUX_RPM_ARCH}.rpm \
		grep-2.6.3-2.el6.${LINUX_RPM_ARCH}.rpm \
		info-4.13a-8.el6.${LINUX_RPM_ARCH}.rpm \
		keyutils-1.4-3.el6.${LINUX_RPM_ARCH}.rpm \
		krb5-libs-1.9-22.el6.${LINUX_RPM_ARCH}.rpm \
		libacl-2.2.49-6.el6.${LINUX_RPM_ARCH}.rpm \
		libattr-2.4.44-7.el6.${LINUX_RPM_ARCH}.rpm \
		libcap-2.16-5.5.el6.${LINUX_RPM_ARCH}.rpm \
		libgcc-4.4.6-3.el6.${LINUX_RPM_ARCH}.rpm \
		libidn-1.18-2.el6.${LINUX_RPM_ARCH}.rpm \
		libselinux-2.0.94-5.2.el6.${LINUX_RPM_ARCH}.rpm \
		libsepol-2.0.41-4.el6.${LINUX_RPM_ARCH}.rpm \
		libstdc++-4.4.6-3.el6.${LINUX_RPM_ARCH}.rpm \
		ncurses-5.7-3.20090208.el6.${LINUX_RPM_ARCH}.rpm \
		ncurses-libs-5.7-3.20090208.el6.${LINUX_RPM_ARCH}.rpm \
		pcre-7.8-3.1.el6.${LINUX_RPM_ARCH}.rpm \
		popt-1.13-7.el6.${LINUX_RPM_ARCH}.rpm \
		readline-6.0-3.el6.${LINUX_RPM_ARCH}.rpm \
		setserial-2.17-25.el6.${LINUX_RPM_ARCH}.rpm \
		setup-2.8.14-13.el6.noarch.rpm \
		slang-2.2.1-1.el6.${LINUX_RPM_ARCH}.rpm \
		zlib-1.2.3-27.el6.${LINUX_RPM_ARCH}.rpm

.if defined(PACKAGE_BUILDING)

MASTER_SITES+=	http://vault.centos.org/${PORTVERSION}/os/Source/SPackages/

SRC_DISTFILES=	basesystem-10.0-4.el6.src.rpm \
		bash-4.1.2-8.el6.centos.src.rpm \
		bzip2-1.0.5-7.el6_0.src.rpm \
		coreutils-8.4-16.el6.src.rpm \
		compat-db-4.6.21-15.el6.src.rpm \
		compat-gcc-296-2.96-144.el6.src.rpm \
		compat-gcc-32-3.2.3-69.el6.src.rpm \
		db4-4.7.25-16.el6.src.rpm \
		e2fsprogs-1.41.12-11.el6.src.rpm \
		elfutils-0.152-1.el6.src.rpm \
		centos-release-6-2.el6.centos.7.src.rpm \
		filesystem-2.4.30-3.el6.src.rpm \
		freetype-2.3.11-6.el6_1.7.src.rpm \
		gdbm-1.8.0-36.el6.src.rpm \
		glib2-2.22.5-6.el6.src.rpm \
		glibc-2.12-1.47.el6.src.rpm \
		grep-2.6.3-2.el6.src.rpm \
		texinfo-4.13a-8.el6.src.rpm \
		keyutils-1.4-3.el6.src.rpm \
		krb5-1.9-22.el6.src.rpm \
		acl-2.2.49-6.el6.src.rpm \
		attr-2.4.44-7.el6.src.rpm \
		libcap-2.16-5.5.el6.src.rpm \
		gcc-4.4.6-3.el6.src.rpm \
		libidn-1.18-2.el6.src.rpm \
		libselinux-2.0.94-5.2.el6.src.rpm \
		libsepol-2.0.41-4.el6.src.rpm \
		ncurses-5.7-3.20090208.el6.src.rpm \
		pcre-7.8-3.1.el6.src.rpm \
		popt-1.13-7.el6.src.rpm \
		readline-6.0-3.el6.src.rpm \
		setserial-2.17-25.el6.src.rpm \
		setup-2.8.14-13.el6.src.rpm \
		slang-2.2.1-1.el6.src.rpm \
		zlib-1.2.3-27.el6.src.rpm

ALWAYS_KEEP_DISTFILES=	yes
.endif

CONFLICTS=              linux_base-gentoo* linux_base-f* linux-glib2-*

ONLY_FOR_ARCHS=		i386 amd64
LINUX_RPM_ARCH=		i686
USE_LINUX_PREFIX=	yes
NO_WRKSUBDIR=		yes
DISTINFO_FILE?=		${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}
PLIST_SUB=		GLIBCVER="2.12"

# TODO:
# - move master sites to bsd.sites.mk
# - add 2-3 mirrors from each country (http://www.centos.org/modules/tinycontent/index.php?id=31)
# - create centos infrastructure in bsd.linux*.mk
# - look for updates in the updates folder of the CentOS mirrors
# - research what are the important differences between 2.6.16 and 2.6.18, and
#   if we need to add something to the linuxulator

EXTRACT_ONLY=		${BIN_DISTFILES}

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
		${MKDIR} ${WRKSRC}/$$F; \
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
# If ${PREFIX}/etc/krb5.conf exists, don't touch it
#
	@${MV} ${WRKSRC}/etc/krb5.conf ${WRKSRC}/etc/krb5.conf.dist

# Fix usr/bin/*db4* permissions to allow "portupgrade -s"
#	@${CHMOD} u+w ${WRKSRC}/usr/bin/*db4*

	@${FIND} ${WRKSRC}/bin ${WRKSRC}/sbin/ ${WRKSRC}/usr/bin \
		${WRKSRC}/usr/sbin -type f -print0 | ${XARGS} -0 ${FILE} \
		| ${GREP} ELF | ${CUT} -d : -f 1 \
		| ${XARGS} ${BRANDELF} -t Linux
	@${BRANDELF} -t Linux ${WRKSRC}/lib/ld-2.12.so

# Restore the status quo for usr/bin/*db4* files
#	@${CHMOD} u-w ${WRKSRC}/usr/bin/*db4*

do-install:
#
# Do install without using linux rpm system
#
	@cd ${WRKSRC} && ${FIND} * ! -path "stage*" -type d -exec ${MKDIR} "${STAGEDIR}${PREFIX}/{}" \;
	@cd ${WRKSRC} && ${FIND} * ! -path "stage/*" ! -type d \
		| ${CPIO} -pm -R root:wheel ${STAGEDIR}${PREFIX}

	@${LN} -sf /var/tmp ${STAGEDIR}${PREFIX}/usr/tmp
	@${CHMOD} 755 ${STAGEDIR}${PREFIX}/var/lock ${STAGEDIR}${PREFIX}/var/spool/mail
#
# Let some linux applications (e.g. print/acroread8) print with default settings
#
	@${INSTALL_SCRIPT} ${FILESDIR}/lp ${STAGEDIR}${PREFIX}/usr/bin

post-install:
	if [ ! -f ${PREFIX}/etc/krb5.conf ] ; then \
		${CP} -p ${STAGEDIR}${PREFIX}/etc/krb5.conf.dist ${STAGEDIR}${PREFIX}/etc/krb5.conf ; \
	fi
	if [ ! -f ${PREFIX}/etc/yp.conf ] ; then \
		${CP} -p ${STAGEDIR}${PREFIX}/etc/yp.conf.sample ${STAGEDIR}${PREFIX}/etc/yp.conf ; \
	fi

.include <bsd.port.post.mk>
