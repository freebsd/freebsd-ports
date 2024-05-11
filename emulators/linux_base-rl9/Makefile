PORTNAME=	rl9
PORTVERSION=	${LINUX_DIST_VER}
PORTREVISION=	1
CATEGORIES=	emulators linux
PKGNAMEPREFIX=	linux_base-
EXTRACT_ONLY=	${DISTFILES:N*${SRC_SUFX}*:Nf/filesystem-*:C/:[^:]+$//}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Base set of packages needed in Linux mode (Rocky Linux ${LINUX_DIST_VER})

LICENSE=	BSD2CLAUSE

USES=		linux:rl9
USE_LINUX=	# empty
USE_LINUX_RPM=	yes

BIN_DISTNAMES=	bash-5.1.8-6.el9_1 \
		bzip2-1.0.8-8.el9 \
		coreutils-8.32-34.el9 \
		diffutils-3.7-12.el9 \
		e2fsprogs-1.46.5-3.el9 \
		filesystem-3.16-2.el9 \
		findutils-4.8.0-6.el9 \
		gawk-5.1.0-6.el9 \
		glibc-common-${GLIBC_VER} \
		grep-3.6-5.el9 \
		info-6.7-15.el9 \
		keyutils-1.6.3-1.el9 \
		less-590-3.el9_3 \
		ncurses-6.2-10.20210508.el9 \
		sed-4.8-9.el9 \
		setserial-2.17-54.el9 \
		which-2.21-29.el9
LIB_DISTNAMES=	bzip2-libs-1.0.8-8.el9 \
		e2fsprogs-libs-1.46.5-3.el9 \
		gdbm-libs-1.19-4.el9 \
		geocode-glib-3.26.2-5.el9 \
		glib-networking-2.68.3-3.el9 \
		glib2-2.68.4-11.el9 \
		glibc-${GLIBC_VER} \
		gmp-6.2.0-13.el9 \
		json-glib-1.6.6-1.el9 \
		keyutils-libs-1.6.3-1.el9 \
		krb5-libs-1.21.1-1.el9 \
		libacl-2.3.1-3.el9 \
		libattr-2.5.1-3.el9 \
		libblkid-2.37.4-15.el9 \
		libcap-2.48-9.el9_2  \
		libcom_err-1.46.5-3.el9 \
		libdatrie-0.2.13-4.el9 \
		libdb-5.3.28-53.el9 \
		libedit-3.1-38.20210216cvs.el9\
		libffi-3.4.2-8.el9 \
		libgcc-11.4.1-2.1.el9 \
		libgudev-237-1.el9 \
		libmount-2.37.4-15.el9 \
		libselinux-3.5-1.el9 \
		libsepol-3.5-1.el9 \
		libssh-0.10.4-12.el9_3 \
		libstdc++-11.4.1-2.1.el9 \
		libuuid-2.37.4-15.el9 \
		libverto-0.3.2-3.el9 \
		libzstd-1.5.1-2.el9 \
		ncurses-libs-6.2-10.20210508.el9 \
		openssl-libs-3.0.7-25.el9_3 \
		pcre-8.44-3.el9.3 \
		pcre2-10.40-2.el9 \
		popt-1.18-8.el9 \
		readline-8.1-4.el9 \
		slang-2.3.2-11.el9 \
		util-linux-2.37.4-15.el9 \
		xz-libs-5.2.5-8.el9_0 \
		zlib-1.2.11-40.el9

SHARE_DISTNAMES=basesystem-11-13.el9.0.1 \
		ncurses-base-6.2-10.20210508.el9 \
		rocky-release-9.3-1.3.el9 \
		setup-2.13.7-9.el9
SRC_DISTFILES=	acl-2.3.1-3.el9${SRC_SUFX}:SOURCE \
		attr-2.5.1-3.el9${SRC_SUFX}:SOURCE \
		basesystem-11-13.el9.0.1${SRC_SUFX}:SOURCE \
		bash-5.1.8-6.el9_1${SRC_SUFX}:SOURCE \
		bzip2-1.0.8-8.el9${SRC_SUFX}:SOURCE \
		coreutils-8.32-34.el9${SRC_SUFX}:SOURCE \
		diffutils-3.7-12.el9${SRC_SUFX}:SOURCE \
		e2fsprogs-1.46.5-3.el9${SRC_SUFX}:SOURCE \
		filesystem-3.16-2.el9${SRC_SUFX}:SOURCE \
		findutils-4.8.0-6.el9${SRC_SUFX}:SOURCE \
		gawk-5.1.0-6.el9${SRC_SUFX}:SOURCE \
		gcc-11.4.1-2.1.el9${SRC_SUFX}:SOURCE \
		gdbm-1.19-4.el9${SRC_SUFX}:SOURCE \
		glib2-2.68.4-11.el9${SRC_SUFX}:SOURCE \
		glibc-${GLIBC_VER}${SRC_SUFX}:SOURCE \
		gmp-6.2.0-13.el9${SRC_SUFX}:SOURCE \
		grep-3.6-5.el9${SRC_SUFX}:SOURCE \
		keyutils-1.6.3-1.el9${SRC_SUFX}:SOURCE \
		krb5-1.21.1-1.el9${SRC_SUFX}:SOURCE \
		less-590-3.el9_3${SRC_SUFX}:SOURCE \
		libcap-2.48-9.el9_2${SRC_SUFX}:SOURCE \
		libdb-5.3.28-53.el9${SRC_SUFX}:SOURCE \
		libffi-3.4.2-8.el9${SRC_SUFX}:SOURCE \
		libgudev-237-1.el9${SRC_SUFX}:SOURCE \
		libselinux-3.5-1.el9${SRC_SUFX}:SOURCE \
		libsepol-3.5-1.el9${SRC_SUFX}:SOURCE \
		libssh-0.10.4-12.el9_3${SRC_SUFX}:SOURCE \
		libverto-0.3.2-3.el9${SRC_SUFX}:SOURCE \
		ncurses-6.2-10.20210508.el9${SRC_SUFX}:SOURCE \
		openssl-3.0.7-25.el9_3${SRC_SUFX}:SOURCE \
		pcre-8.44-3.el9.3${SRC_SUFX}:SOURCE \
		pcre2-10.40-2.el9${SRC_SUFX}:SOURCE \
		popt-1.18-8.el9${SRC_SUFX}:SOURCE \
		readline-8.1-4.el9${SRC_SUFX}:SOURCE \
		rocky-release-9.3-1.3.el9${SRC_SUFX}:SOURCE \
		sed-4.8-9.el9${SRC_SUFX}:SOURCE \
		setserial-2.17-54.el9${SRC_SUFX}:SOURCE \
		setup-2.13.7-9.el9${SRC_SUFX}:SOURCE \
		slang-2.3.2-11.el9${SRC_SUFX}:SOURCE \
		texinfo-6.7-15.el9${SRC_SUFX}:SOURCE \
		util-linux-2.37.4-15.el9${SRC_SUFX}:SOURCE \
		which-2.21-29.el9${SRC_SUFX}:SOURCE \
		xz-5.2.5-8.el9_0${SRC_SUFX}:SOURCE \
		zlib-1.2.11-40.el9${SRC_SUFX}:SOURCE

PLIST_SUB=	LINUXBASE=${LINUXBASE} SYSCTLMIB=${SYSCTLMIB}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

REMOVE_DIRS=	boot etc/pam.d home media mnt proc root run sys tmp var/log \
		var/tmp
REMOVE_FILES=	bin/chfn bin/chsh bin/findmnt bin/login bin/lsblk bin/lscpu \
		bin/lsipc bin/lslogins bin/lsmem bin/lsns bin/script \
		bin/setpriv bin/su \
		etc/exports etc/group etc/gshadow etc/motd \
		etc/passwd etc/printcap etc/protocols etc/services etc/shadow \
		sbin/clock sbin/debugfs sbin/hwclock sbin/runuser sbin/zramctl

.include <bsd.port.options.mk>

GLIBC_VER=	2.34-83.el9.12
PLIST_SUB+=	NEWGLIBC=""

.if ${ARCH} == aarch64 || ${ARCH} == amd64
SYSCTLMIB=	kern.features.linux64
.else
SYSCTLMIB=	compat.linux.osrelease
.endif

post-extract:
# These directories become symbolic links when the filesystem distfile is
# extracted.  Other distfiles cannot be extracted when these are links so the
# filesystem distfile must be extracted last.
.for d in bin lib lib64 sbin
	@(cd ${WRKSRC} && if [ -e ${d} -a ! -L ${d} ]; then \
		${FIND} ${d} | ${CPIO} -dumpl --quiet usr && ${RM} -r ${d}; fi)
.endfor
	@(cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DIST_SUBDIR}/f/filesystem-3.16-2.el9${EXTRACT_SUFX_${ARCH}} \
		${EXTRACT_AFTER_ARGS})
.if ${ARCH} == i386
	@${CHMOD} u+w ${WRKSRC}/usr/lib/pm-utils
.elif ${ARCH} == aarch64 || ${ARCH} == amd64
	@${CHMOD} u+w ${WRKSRC}/usr/lib64/pm-utils
.endif

post-patch:
	@${RM} -r ${REMOVE_DIRS:S|^|${WRKSRC}/|}
	@${RM} ${REMOVE_FILES:S|^|${WRKSRC}/|}
	@${FIND} ${WRKSRC}/usr -type d -empty -not -path '*/lib*/gio/*' -delete
.if ${ARCH} == aarch64
	${BRANDELF} -t Linux ${WRKSRC}/usr/lib/ld-linux-*
.else
	${BRANDELF} -t Linux ${WRKSRC}/usr/lib64/ld-linux-*.so.2
.endif

post-install:
	${RM} -r ${STAGEDIR}${LOCALBASE}
	${MV} ${STAGEDIR}${PREFIX}/etc/krb5.conf \
		${STAGEDIR}${PREFIX}/etc/krb5.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/nsswitch.conf \
		${STAGEDIR}${PREFIX}/etc/nsswitch.conf.sample
	${LN} -sf "../proc/self/mounts" ${STAGEDIR}${PREFIX}/etc/mtab
	${LN} -sf ${LOCALBASE}/share/icons ${STAGEDIR}${PREFIX}/usr/share/icons
	${LN} -sf /var/run ${STAGEDIR}${PREFIX}/run
	${LN} -sf /var/tmp ${STAGEDIR}${PREFIX}/usr/tmp

.include <bsd.port.mk>
