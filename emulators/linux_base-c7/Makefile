# $FreeBSD$

PORTNAME=	c7
PORTVERSION=	${LINUX_DIST_VER}
CATEGORIES=	emulators linux
PKGNAMEPREFIX=	linux_base-
EXTRACT_ONLY=	${DISTFILES:N*${SRC_SUFX}*:Nfilesystem-*}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Base set of packages needed in Linux mode for i386/amd64 (Linux CentOS 7)

BIN_DISTFILES=	centos-release-7-3.1611.el7.centos${EXTRACT_SUFX} \
		basesystem-10.0-7.el7.centos.noarch.rpm \
		bash-4.2.46-21.el7_3${EXTRACT_SUFX} \
		bzip2-1.0.6-13.el7${EXTRACT_SUFX} \
		coreutils-8.22-18.el7${EXTRACT_SUFX} \
		e2fsprogs-1.42.9-9.el7${EXTRACT_SUFX} \
		elfutils-0.166-2.el7${EXTRACT_SUFX} \
		filesystem-3.2-21.el7${EXTRACT_SUFX} \
		findutils-4.5.11-5.el7${EXTRACT_SUFX} \
		glibc-common-2.17-157.el7_3.1${EXTRACT_SUFX} \
		grep-2.20-2.el7${EXTRACT_SUFX} \
		info-5.1-4.el7${EXTRACT_SUFX} \
		keyutils-1.5.8-3.el7${EXTRACT_SUFX} \
		less-458-9.el7${EXTRACT_SUFX} \
		ncurses-5.9-13.20130511.el7${EXTRACT_SUFX} \
		sed-4.2.2-5.el7${EXTRACT_SUFX} \
		setserial-2.17-33.el7${EXTRACT_SUFX} \
		setup-2.8.71-7.el7.noarch.rpm \
		which-2.20-7.el7${EXTRACT_SUFX}
LIB_DISTFILES=	bzip2-libs-1.0.6-13.el7${EXTRACT_SUFX} \
		compat-db47-4.7.25-28.el7${EXTRACT_SUFX} \
		compat-libstdc++-33-3.2.3-72.el7${EXTRACT_SUFX} \
		e2fsprogs-libs-1.42.9-9.el7${EXTRACT_SUFX} \
		freetype-2.4.11-12.el7${EXTRACT_SUFX} \
		gamin-0.1.10-16.el7${EXTRACT_SUFX} \
		gdbm-1.10-8.el7${EXTRACT_SUFX} \
		glib2-2.46.2-4.el7${EXTRACT_SUFX} \
		glibc-2.17-157.el7_3.1${EXTRACT_SUFX} \
		gmp-6.0.0-12.el7_1${EXTRACT_SUFX} \
		keyutils-libs-1.5.8-3.el7${EXTRACT_SUFX} \
		krb5-libs-1.14.1-27.el7_3${EXTRACT_SUFX} \
		libacl-2.2.51-12.el7${EXTRACT_SUFX} \
		libattr-2.4.46-12.el7${EXTRACT_SUFX} \
		libblkid-2.23.2-33.el7${EXTRACT_SUFX} \
		libcap-2.22-8.el7${EXTRACT_SUFX} \
		libcom_err-1.42.9-9.el7${EXTRACT_SUFX} \
		libdb-5.3.21-19.el7${EXTRACT_SUFX} \
		libffi-3.0.13-18.el7${EXTRACT_SUFX} \
		libgcc-4.8.5-11.el7${EXTRACT_SUFX} \
		libidn-1.28-4.el7${EXTRACT_SUFX} \
		libselinux-2.5-6.el7${EXTRACT_SUFX} \
		libsepol-2.5-6.el7${EXTRACT_SUFX} \
		libstdc++-4.8.5-11.el7${EXTRACT_SUFX} \
		libuuid-2.23.2-33.el7${EXTRACT_SUFX} \
		ncurses-libs-5.9-13.20130511.el7${EXTRACT_SUFX} \
		pcre-8.32-15.el7_2.1${EXTRACT_SUFX} \
		popt-1.13-16.el7${EXTRACT_SUFX} \
		readline-6.2-9.el7${EXTRACT_SUFX} \
		redhat-lsb-core-4.1-27.el7.centos.1${EXTRACT_SUFX} \
		slang-2.2.4-11.el7${EXTRACT_SUFX} \
		util-linux-2.23.2-33.el7${EXTRACT_SUFX} \
		xz-libs-5.2.2-1.el7${EXTRACT_SUFX} \
		zlib-1.2.7-17.el7${EXTRACT_SUFX}
SRC_DISTFILES=	acl-2.2.51-12.el7${SRC_SUFX}:SOURCE \
		attr-2.4.46-12.el7${SRC_SUFX}:SOURCE \
		basesystem-10.0-7.el7.centos${SRC_SUFX}:SOURCE \
		bash-4.2.46-21.el7_3${SRC_SUFX}:SOURCE \
		bzip2-1.0.6-13.el7${SRC_SUFX}:SOURCE \
		centos-release-7-3.1611.el7.centos${SRC_SUFX}:SOURCE \
		compat-db-4.7.25-28.el7${SRC_SUFX}:SOURCE \
		compat-gcc-32-3.2.3-72.el7${SRC_SUFX}:SOURCE \
		coreutils-8.22-18.el7${SRC_SUFX}:SOURCE \
		e2fsprogs-1.42.9-9.el7${SRC_SUFX}:SOURCE \
		elfutils-0.166-2.el7${SRC_SUFX}:SOURCE \
		filesystem-3.2-21.el7${SRC_SUFX}:SOURCE \
		findutils-4.5.11-5.el7${SRC_SUFX}:SOURCE \
		freetype-2.4.11-12.el7${SRC_SUFX}:SOURCE \
		gamin-0.1.10-16.el7${SRC_SUFX}:SOURCE \
		gcc-4.8.5-11.el7${SRC_SUFX}:SOURCE \
		gdbm-1.10-8.el7${SRC_SUFX}:SOURCE \
		glib2-2.46.2-4.el7${SRC_SUFX}:SOURCE \
		glibc-2.17-157.el7_3.1${SRC_SUFX}:SOURCE \
		gmp-6.0.0-12.el7_1${SRC_SUFX}:SOURCE \
		grep-2.20-2.el7${SRC_SUFX}:SOURCE \
		keyutils-1.5.8-3.el7${SRC_SUFX}:SOURCE \
		krb5-1.14.1-27.el7_3${SRC_SUFX}:SOURCE \
		less-458-9.el7${SRC_SUFX}:SOURCE \
		libcap-2.22-8.el7${SRC_SUFX}:SOURCE \
		libdb-5.3.21-19.el7${SRC_SUFX}:SOURCE \
		libffi-3.0.13-18.el7${SRC_SUFX}:SOURCE \
		libidn-1.28-4.el7${SRC_SUFX}:SOURCE \
		libselinux-2.5-6.el7${SRC_SUFX}:SOURCE \
		libsepol-2.5-6.el7${SRC_SUFX}:SOURCE \
		ncurses-5.9-13.20130511.el7${SRC_SUFX}:SOURCE \
		pcre-8.32-15.el7_2.1${SRC_SUFX}:SOURCE \
		popt-1.13-16.el7${SRC_SUFX}:SOURCE \
		readline-6.2-9.el7${SRC_SUFX}:SOURCE \
		redhat-lsb-4.1-27.el7.centos.1${SRC_SUFX}:SOURCE \
		sed-4.2.2-5.el7${SRC_SUFX}:SOURCE \
		setserial-2.17-33.el7${SRC_SUFX}:SOURCE \
		setup-2.8.71-7.el7${SRC_SUFX}:SOURCE \
		slang-2.2.4-11.el7${SRC_SUFX}:SOURCE \
		texinfo-5.1-4.el7${SRC_SUFX}:SOURCE \
		util-linux-2.23.2-33.el7${SRC_SUFX}:SOURCE \
		which-2.20-7.el7${SRC_SUFX}:SOURCE \
		xz-5.2.2-1.el7${SRC_SUFX}:SOURCE \
		zlib-1.2.7-17.el7${SRC_SUFX}:SOURCE

PLIST_SUB=	LINUXBASE=${LINUXBASE} SYSCTLMIB=${SYSCTLMIB}
USES=		linux:c7
USE_LINUX=	# empty
USE_LINUX_RPM=	yes

REMOVE_DIRS=	boot home media mnt proc root run sys tmp \
		usr/lib64/pm-utils usr/local var/log var/tmp
REMOVE_FILES=	bin/df bin/su etc/exports etc/group etc/gshadow etc/motd \
		etc/passwd etc/printcap etc/protocols etc/services etc/shadow \
		usr/tmp

.include <bsd.port.pre.mk>

.if ${LINUX_ARCH} == x86_64 && ${OPSYS} == FreeBSD && ${OSVERSION} >= 11000105
SYSCTLMIB=	kern.features.linux64
.else
SYSCTLMIB=	compat.linux.osrelease
.endif

post-extract:
# These directories become symbolic links when the filesystem distfile is
# extracted.  Other distfiles cannot be extracted when these are links so the
# filesystem distfile must be extracted last.
.for d in bin lib/lsb lib sbin
	@${MV} ${WRKSRC}/${d}/* ${WRKSRC}/usr/${d}
	@${RMDIR} ${WRKSRC}/${d}
.endfor
.if ${LINUX_ARCH} == x86_64
	@${MV} ${WRKSRC}/lib64/* ${WRKSRC}/usr/lib64
	@${RMDIR} ${WRKSRC}/lib64
.endif
	@(cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DIST_SUBDIR}/filesystem-3.2-21.el7${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS})
	@${CHMOD} u+w ${WRKSRC}/usr/lib64/pm-utils

post-patch:
	@${RM} -r ${REMOVE_DIRS:S|^|${WRKSRC}/|}
	@${RM} ${REMOVE_FILES:S|^|${WRKSRC}/|}
	@${BRANDELF} -t Linux ${WRKSRC}/usr/lib/ld-2.17.so
.if ${LINUX_ARCH} == x86_64
	@${BRANDELF} -t Linux ${WRKSRC}/usr/lib64/ld-2.17.so
.endif

post-install:
	${TOUCH} ${STAGEDIR}${PREFIX}/etc/mtab
	${MV} ${STAGEDIR}${PREFIX}/etc/krb5.conf \
		${STAGEDIR}${PREFIX}/etc/krb5.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/nsswitch.conf \
		${STAGEDIR}${PREFIX}/etc/nsswitch.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/usr/lib/locale/locale-archive.tmpl \
		${STAGEDIR}${PREFIX}/usr/lib/locale/locale-archive
	${LN} -sf /var/run ${STAGEDIR}${PREFIX}/run
	${LN} -sf /var/tmp ${STAGEDIR}${PREFIX}/usr/tmp

.include <bsd.port.post.mk>
