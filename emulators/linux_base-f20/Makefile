# Created by: Vassilis based on the f10 port by bsam
# $FreeBSD$

PORTNAME=		f20
PORTVERSION=		1
CATEGORIES=		emulators linux
MASTER_SITES=		http://archives.fedoraproject.org/pub/fedora/linux/releases/${LINUX_RPM_VERSION}/Everything/${LINUX_CPU_ARCH}/os/Packages/
PKGNAMEPREFIX=		linux_base-
DISTFILES=		${BIN_DISTFILES}
DIST_SUBDIR=		rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_RPM_VERSION}
EXTRACT_ONLY=		${BIN_DISTFILES}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Base set of Fedora 20 linux packages for i386/amd64 emulation

BIN_DISTFILES=	\
				b/basesystem-10.0-9.fc${LINUX_RPM_VERSION}.noarch.rpm \
				b/bash-4.2.45-4.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				b/bzip2-1.0.6-9.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				c/compat-libstdc++-33-3.2.3-68.7.${LINUX_RPM_ARCH}.rpm \
				c/compat-libstdc++-296-2.96-145.${LINUX_RPM_ARCH}.rpm \
				c/coreutils-8.21-18.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				e/e2fsprogs-1.42.8-3.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				e/e2fsprogs-libs-1.42.8-3.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				e/elfutils-0.157-1.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				f/fedora-release-${LINUX_RPM_VERSION}-1.noarch.rpm \
				f/filesystem-3.2-19.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				f/freetype-2.5.0-4.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				g/gamin-0.1.10-15.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				g/gdbm-1.10-7.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				g/glib-1.2.10-40.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				g/glib2-2.38.2-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				g/glibc-2.18-11.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				g/glibc-common-2.18-11.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				g/grep-2.15-1.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				h/hostname-3.13-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				i/info-5.1-4.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				k/keyutils-libs-1.5.8-1.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				k/krb5-libs-1.11.3-33.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				l/libacl-2.2.52-4.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				l/libattr-2.4.47-3.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				l/libcap-2.22-7.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				l/libcom_err-1.42.8-3.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				l/libgcc-4.8.2-1.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				l/libidn-1.28-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				l/libidn2-0.8-5.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				l/libselinux-2.1.13-19.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				l/libsepol-2.1.9-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				l/libstdc++-4.8.2-1.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				l/libuuid-2.24-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				n/ncurses-5.9-12.20130511.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				n/ncurses-libs-5.9-12.20130511.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				p/pcre-8.33-2.fc${LINUX_RPM_VERSION}.1.${LINUX_RPM_ARCH}.rpm \
				p/popt-1.13-15.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				r/readline-6.2-8.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				s/setserial-2.17-34.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				s/setup-2.8.71-2.fc${LINUX_RPM_VERSION}.noarch.rpm \
				s/slang-2.2.4-11.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				y/yp-tools-2.14-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				y/ypbind-1.37.1-7.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm \
				z/zlib-1.2.8-3.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm

CONFLICTS=		linux_base-gentoo* linux_base-fc4-[0-9]* linux_base-fc6-[0-9]* \
			linux_base-f7-[0-9]* linux_base-f8-[0-9]* linux_base-f9-[0-9]* \
			linux_base-c* linux-glib2-* linux_base-f10*

ONLY_FOR_ARCHS=		i386 amd64
LINUX_CPU_ARCH=		i386
LINUX_RPM_ARCH=		i686
LINUX_RPM_VERSION=	20
USE_LINUX_PREFIX=	yes
NO_WRKSUBDIR=		yes
DISTINFO_FILE?=		${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}
PLIST_SUB=		GLIBCVER="2.18"

EXTRACT_CMD?=		${TAR}
EXTRACT_BEFORE_ARGS?=	-xPf
EXTRACT_AFTER_ARGS?=

.include <bsd.port.pre.mk>

.if !defined(PACKAGE_BUILDING) || (defined(PACKAGE_BUILDING) && !defined(LINUX_OSRELEASE) )
LINUX_OSRELEASE!=	${ECHO_CMD} `${SYSCTL} -n compat.linux.osrelease 2>/dev/null`
.endif

.if ${LINUX_OSRELEASE}x == "x"
IGNORE=			linuxulator is not (kld)loaded
.endif

REMOVE_DIRS=	boot dev home media mnt opt proc root run srv sys tmp \
			var/log var/run var/tmp usr/local
REMOVE_FILES=

# These are shared directories that some linux packages (e.g. linux-f10-gtk2)
# use but aren't in any of the distfiles above.
#
ADD_DIRS=	boot dev home media mnt opt proc root run srv sys tmp \
			var/log var/run var/tmp usr/local

ADD_FILES=

.if (${ARCH} == "amd64")
FALLBACK_ELF_MIB=	kern.elf64.fallback_brand
.else
FALLBACK_ELF_MIB=	kern.fallback_elf_brand
.endif

.if (${ARCH} == "amd64")
LATEST_LINK:=		${PKGBASE:C/linux/linux32/}
.endif

do-extract:
	${RM} -rf ${WRKDIR}
	${MKDIR} ${WRKDIR}

.for file in ${EXTRACT_ONLY}
	if ! (cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${file} ${EXTRACT_AFTER_ARGS});\
	then \
		exit 1; \
	fi
.endfor

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
	#@${INSTALL} ${COPY} -m 644 ${FILESDIR}/yp.conf.sample ${WRKSRC}/etc
	#@${TOUCH} ${WRKSRC}/etc/mtab
#
# If ${PREFIX}/etc/nsswitch.conf exists, don't touch it,
# install only ${PREFIX}/etc/nsswitch.conf.dist
#
	#@${MV} ${WRKSRC}/etc/nsswitch.conf ${WRKSRC}/etc/nsswitch.conf.dist
	#@${MV} ${WRKSRC}/etc/krb5.conf ${WRKSRC}/etc/krb5.conf.dist

# Fix usr/bin/*db4* permissions to allow "portupgrade -s"
#	@${CHMOD} u+w ${WRKSRC}/usr/bin/*db4*

	@${FIND} ${WRKSRC}/bin ${WRKSRC}/sbin/ ${WRKSRC}/usr/bin \
		${WRKSRC}/usr/sbin -type f -print0 | ${XARGS} -0 ${FILE} \
		| ${GREP} ELF | ${CUT} -d : -f 1 \
		| ${XARGS} ${BRANDELF} -t Linux
	@${BRANDELF} -t Linux ${WRKSRC}/lib/ld-2.18.so

# Restore the status quo for usr/bin/*db4* files
#	@${CHMOD} u-w ${WRKSRC}/usr/bin/*db4*

do-install:
#
# Do install without using linux rpm system
#
	@cd ${WRKSRC} && ${FIND} * ! -path "stage*" -type d -exec ${MKDIR} "${STAGEDIR}${PREFIX}/{}" \;
	@cd ${WRKSRC} && ${FIND} * ! -path "stage/*" ! -type d \
		| ${CPIO} -pm -R root:wheel ${STAGEDIR}${PREFIX}

	@${LN} -sf ${PREFIX}/bin ${STAGEDIR}${PREFIX}/bin
	@${LN} -sf ${PREFIX}/sbin ${STAGEDIR}${PREFIX}/usr/sbin
	@${LN} -sf ${PREFIX}/lib ${STAGEDIR}${PREFIX}/usr/lib
	@${LN} -sf ${PREFIX}/usr/tmp ${STAGEDIR}${PREFIX}/var/tmp

	@${CHMOD} 1777 ${STAGEDIR}${PREFIX}/tmp ${STAGEDIR}${PREFIX}/var/tmp ${STAGEDIR}${PREFIX}/var/run

	#@${CHMOD} 755 ${STAGEDIR}${PREFIX}/var/lock ${STAGEDIR}${PREFIX}/var/spool/mail
#
# Let some linux applications (e.g. print/acroread8) print with default settings
#
	#@${INSTALL_SCRIPT} ${FILESDIR}/lp ${STAGEDIR}${PREFIX}/usr/bin

.include <bsd.port.post.mk>
