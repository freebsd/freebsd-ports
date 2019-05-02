# $FreeBSD$

PORTNAME=	c7
PORTVERSION=	${LINUX_DIST_VER}
PORTREVISION=	7
CATEGORIES=	emulators linux
PKGNAMEPREFIX=	linux_base-
BIN_DISTNAMES=	centos-release-7-4.1708.el7.centos \
		bash-4.2.46-29.el7_4 \
		bzip2-1.0.6-13.el7 \
		coreutils-8.22-18.el7 \
		e2fsprogs-1.42.9-10.el7 \
		elfutils-0.168-8.el7 \
		filesystem-3.2-21.el7 \
		findutils-4.5.11-5.el7 \
		glibc-common-2.17-196.el7_4.2 \
		grep-2.20-3.el7 \
		info-5.1-4.el7 \
		keyutils-1.5.8-3.el7 \
		less-458-9.el7 \
		ncurses-5.9-14.20130511.el7_4 \
		sed-4.2.2-5.el7 \
		setserial-2.17-33.el7 \
		which-2.20-7.el7
LIB_DISTNAMES=	bzip2-libs-1.0.6-13.el7 \
		compat-db47-4.7.25-28.el7 \
		compat-libstdc++-33-3.2.3-72.el7 \
		e2fsprogs-libs-1.42.9-10.el7 \
		freetype-2.4.11-15.el7 \
		gamin-0.1.10-16.el7 \
		gdbm-1.10-8.el7 \
		glib2-2.50.3-3.el7 \
		glibc-2.17-196.el7_4.2 \
		gmp-6.0.0-15.el7 \
		keyutils-libs-1.5.8-3.el7 \
		krb5-libs-1.15.1-8.el7 \
		libacl-2.2.51-12.el7 \
		libattr-2.4.46-12.el7 \
		libblkid-2.23.2-43.el7_4.2 \
		libcap-2.22-9.el7 \
		libcom_err-1.42.9-10.el7 \
		libdb-5.3.21-21.el7_4 \
		libffi-3.0.13-18.el7 \
		libgcc-4.8.5-16.el7_4.2 \
		libidn-1.28-4.el7 \
		libmount-2.23.2-43.el7_4.2 \
		libselinux-2.5-11.el7 \
		libsepol-2.5-6.el7 \
		libstdc++-4.8.5-16.el7_4.2 \
		libuuid-2.23.2-43.el7_4.2 \
		ncurses-libs-5.9-14.20130511.el7_4 \
		nss-softokn-freebl-3.28.3-8.el7_4 \
		pcre-8.32-17.el7 \
		popt-1.13-16.el7 \
		readline-6.2-10.el7 \
		redhat-lsb-core-4.1-27.el7.centos.1 \
		slang-2.2.4-11.el7 \
		util-linux-2.23.2-43.el7_4.2 \
		xz-libs-5.2.2-1.el7 \
		zlib-1.2.7-17.el7
SHARE_DISTNAMES=basesystem-10.0-7.el7.centos \
		ncurses-base-5.9-14.20130511.el7_4 \
		setup-2.8.71-7.el7
SRC_DISTFILES=	acl-2.2.51-12.el7${SRC_SUFX}:SOURCE \
		attr-2.4.46-12.el7${SRC_SUFX}:SOURCE \
		basesystem-10.0-7.el7.centos${SRC_SUFX}:SOURCE \
		bash-4.2.46-29.el7_4${SRC_SUFX}:SOURCE \
		bzip2-1.0.6-13.el7${SRC_SUFX}:SOURCE \
		centos-release-7-4.1708.el7.centos${SRC_SUFX}:SOURCE \
		compat-db-4.7.25-28.el7${SRC_SUFX}:SOURCE \
		compat-gcc-32-3.2.3-72.el7${SRC_SUFX}:SOURCE \
		coreutils-8.22-18.el7${SRC_SUFX}:SOURCE \
		e2fsprogs-1.42.9-10.el7${SRC_SUFX}:SOURCE \
		elfutils-0.168-8.el7${SRC_SUFX}:SOURCE \
		filesystem-3.2-21.el7${SRC_SUFX}:SOURCE \
		findutils-4.5.11-5.el7${SRC_SUFX}:SOURCE \
		freetype-2.4.11-15.el7${SRC_SUFX}:SOURCE \
		gamin-0.1.10-16.el7${SRC_SUFX}:SOURCE \
		gcc-4.8.5-16.el7_4.2${SRC_SUFX}:SOURCE \
		gdbm-1.10-8.el7${SRC_SUFX}:SOURCE \
		glib2-2.50.3-3.el7${SRC_SUFX}:SOURCE \
		glibc-2.17-196.el7_4.2${SRC_SUFX}:SOURCE \
		gmp-6.0.0-15.el7${SRC_SUFX}:SOURCE \
		grep-2.20-3.el7${SRC_SUFX}:SOURCE \
		keyutils-1.5.8-3.el7${SRC_SUFX}:SOURCE \
		krb5-1.15.1-8.el7${SRC_SUFX}:SOURCE \
		less-458-9.el7${SRC_SUFX}:SOURCE \
		libcap-2.22-9.el7${SRC_SUFX}:SOURCE \
		libdb-5.3.21-21.el7_4${SRC_SUFX}:SOURCE \
		libffi-3.0.13-18.el7${SRC_SUFX}:SOURCE \
		libidn-1.28-4.el7${SRC_SUFX}:SOURCE \
		libselinux-2.5-11.el7${SRC_SUFX}:SOURCE \
		libsepol-2.5-6.el7${SRC_SUFX}:SOURCE \
		ncurses-5.9-14.20130511.el7_4${SRC_SUFX}:SOURCE \
		nss-softokn-3.28.3-8.el7_4${SRC_SUFX}:SOURCE \
		pcre-8.32-17.el7${SRC_SUFX}:SOURCE \
		popt-1.13-16.el7${SRC_SUFX}:SOURCE \
		readline-6.2-10.el7${SRC_SUFX}:SOURCE \
		redhat-lsb-4.1-27.el7.centos.1${SRC_SUFX}:SOURCE \
		sed-4.2.2-5.el7${SRC_SUFX}:SOURCE \
		setserial-2.17-33.el7${SRC_SUFX}:SOURCE \
		setup-2.8.71-7.el7${SRC_SUFX}:SOURCE \
		slang-2.2.4-11.el7${SRC_SUFX}:SOURCE \
		texinfo-5.1-4.el7${SRC_SUFX}:SOURCE \
		util-linux-2.23.2-43.el7_4.2${SRC_SUFX}:SOURCE \
		which-2.20-7.el7${SRC_SUFX}:SOURCE \
		xz-5.2.2-1.el7${SRC_SUFX}:SOURCE \
		zlib-1.2.7-17.el7${SRC_SUFX}:SOURCE
EXTRACT_ONLY=	${DISTFILES:N*${SRC_SUFX}*:Nfilesystem-*:C/:[^:]+$//}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Base set of packages needed in Linux mode (Linux CentOS ${LINUX_DIST_VER})

PLIST_SUB=	LINUXBASE=${LINUXBASE} SYSCTLMIB=${SYSCTLMIB}
USES=		linux:c7
USE_LINUX=	# empty
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

REMOVE_DIRS=	boot home media mnt proc root run sys tmp var/log var/tmp
REMOVE_FILES=	bin/su etc/exports etc/group etc/gshadow etc/motd \
		etc/passwd etc/printcap etc/protocols etc/services etc/shadow

.include <bsd.port.pre.mk>

.if ${LINUX_ARCH} == x86_64
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
		${DISTDIR}/${DIST_SUBDIR}/filesystem-3.2-21.el7${EXTRACT_SUFX_${LINUX_ARCH:S/x86_64/amd64/}} \
		${EXTRACT_AFTER_ARGS})
.if ${LINUX_ARCH} == i386
	@${CHMOD} u+w ${WRKSRC}/usr/lib/pm-utils
.elif ${LINUX_ARCH} == x86_64
	@${CHMOD} u+w ${WRKSRC}/usr/lib64/pm-utils
.endif

post-patch:
	@${RM} -r ${REMOVE_DIRS:S|^|${WRKSRC}/|}
	@${RM} ${REMOVE_FILES:S|^|${WRKSRC}/|}
	@${FIND} ${WRKSRC}/usr -type d -empty -not -path '*/lib*/gio/*' -delete
	@${BRANDELF} -t Linux ${WRKSRC}/usr/lib/ld-2.17.so
.if ${LINUX_ARCH} == x86_64
	@${BRANDELF} -t Linux ${WRKSRC}/usr/lib64/ld-2.17.so
.endif

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/krb5.conf \
		${STAGEDIR}${PREFIX}/etc/krb5.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/nsswitch.conf \
		${STAGEDIR}${PREFIX}/etc/nsswitch.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/usr/lib/locale/locale-archive.tmpl \
		${STAGEDIR}${PREFIX}/usr/lib/locale/locale-archive
	${LN} -sf "../proc/self/mounts" ${STAGEDIR}${PREFIX}/etc/mtab
	${LN} -sf ${LOCALBASE}/share/icons ${STAGEDIR}${PREFIX}/usr/share/icons
	${LN} -sf /var/run ${STAGEDIR}${PREFIX}/run
	${LN} -sf /var/tmp ${STAGEDIR}${PREFIX}/usr/tmp

.include <bsd.port.post.mk>
