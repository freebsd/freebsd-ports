# $FreeBSD$

PORTNAME=	c7
PORTVERSION=	${LINUX_DIST_VER}
PORTREVISION=	3
CATEGORIES=	emulators linux
PKGNAMEPREFIX=	linux_base-
EXTRACT_ONLY=	${DISTFILES:N*.src.rpm*:Nfilesystem-*}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Base set of packages needed in Linux mode for i386/amd64 (Linux CentOS 7)

BIN_i386=	centos-release-7-2.1511.el7.centos.2.9${EXTRACT_SUFX}
BIN_x86_64=	centos-release-7-2.1511.el7.centos.2.10${EXTRACT_SUFX}
BIN_DISTFILES=	${BIN_${LINUX_ARCH}} \
		basesystem-10.0-7.el7.centos.noarch.rpm \
		bash-4.2.46-20.el7_2${EXTRACT_SUFX} \
		bzip2-1.0.6-13.el7${EXTRACT_SUFX} \
		coreutils-8.22-15.el7_2.1${EXTRACT_SUFX} \
		e2fsprogs-1.42.9-7.el7${EXTRACT_SUFX} \
		elfutils-0.163-3.el7${EXTRACT_SUFX} \
		filesystem-3.2-20.el7${EXTRACT_SUFX} \
		findutils-4.5.11-5.el7${EXTRACT_SUFX} \
		glibc-common-2.17-106.el7_2.8${EXTRACT_SUFX} \
		grep-2.20-2.el7${EXTRACT_SUFX} \
		info-5.1-4.el7${EXTRACT_SUFX} \
		keyutils-1.5.8-3.el7${EXTRACT_SUFX} \
		less-458-9.el7${EXTRACT_SUFX} \
		ncurses-5.9-13.20130511.el7${EXTRACT_SUFX} \
		sed-4.2.2-5.el7${EXTRACT_SUFX} \
		setserial-2.17-33.el7${EXTRACT_SUFX} \
		setup-2.8.71-6.el7.noarch.rpm \
		which-2.20-7.el7${EXTRACT_SUFX}
LIB_DISTFILES=	bzip2-libs-1.0.6-13.el7${EXTRACT_SUFX} \
		compat-db47-4.7.25-28.el7${EXTRACT_SUFX} \
		compat-libstdc++-33-3.2.3-72.el7${EXTRACT_SUFX} \
		e2fsprogs-libs-1.42.9-7.el7${EXTRACT_SUFX} \
		freetype-2.4.11-11.el7${EXTRACT_SUFX} \
		gamin-0.1.10-16.el7${EXTRACT_SUFX} \
		gdbm-1.10-8.el7${EXTRACT_SUFX} \
		glib2-2.42.2-5.el7${EXTRACT_SUFX} \
		glibc-2.17-106.el7_2.8${EXTRACT_SUFX} \
		gmp-6.0.0-12.el7_1${EXTRACT_SUFX} \
		keyutils-libs-1.5.8-3.el7${EXTRACT_SUFX} \
		krb5-libs-1.13.2-12.el7_2${EXTRACT_SUFX} \
		libacl-2.2.51-12.el7${EXTRACT_SUFX} \
		libattr-2.4.46-12.el7${EXTRACT_SUFX} \
		libblkid-2.23.2-26.el7_2.3${EXTRACT_SUFX} \
		libcap-2.22-8.el7${EXTRACT_SUFX} \
		libcom_err-1.42.9-7.el7${EXTRACT_SUFX} \
		libdb-5.3.21-19.el7${EXTRACT_SUFX} \
		libffi-3.0.13-16.el7${EXTRACT_SUFX} \
		libgcc-4.8.5-4.el7${EXTRACT_SUFX} \
		libidn-1.28-4.el7${EXTRACT_SUFX} \
		libselinux-2.2.2-6.el7${EXTRACT_SUFX} \
		libsepol-2.1.9-3.el7${EXTRACT_SUFX} \
		libstdc++-4.8.5-4.el7${EXTRACT_SUFX} \
		libuuid-2.23.2-26.el7_2.3${EXTRACT_SUFX} \
		ncurses-libs-5.9-13.20130511.el7${EXTRACT_SUFX} \
		pcre-8.32-15.el7_2.1${EXTRACT_SUFX} \
		popt-1.13-16.el7${EXTRACT_SUFX} \
		readline-6.2-9.el7${EXTRACT_SUFX} \
		redhat-lsb-core-4.1-27.el7.centos.1${EXTRACT_SUFX} \
		slang-2.2.4-11.el7${EXTRACT_SUFX} \
		util-linux-2.23.2-26.el7_2.3${EXTRACT_SUFX} \
		xz-libs-5.1.2-12alpha.el7${EXTRACT_SUFX} \
		zlib-1.2.7-15.el7${EXTRACT_SUFX}
SRC_DISTFILES=	acl-2.2.51-12.el7.src.rpm:SOURCE \
		attr-2.4.46-12.el7.src.rpm:SOURCE \
		basesystem-10.0-7.el7.centos.src.rpm:SOURCE \
		bash-4.2.46-20.el7_2.src.rpm:SOURCE \
		bzip2-1.0.6-13.el7.src.rpm:SOURCE \
		centos-release-7-2.1511.el7.centos.2.10.src.rpm:SOURCE \
		compat-db-4.7.25-28.el7.src.rpm:SOURCE \
		compat-gcc-32-3.2.3-72.el7.src.rpm:SOURCE \
		coreutils-8.22-15.el7_2.1.src.rpm:SOURCE \
		e2fsprogs-1.42.9-7.el7.src.rpm:SOURCE \
		elfutils-0.163-3.el7.src.rpm:SOURCE \
		filesystem-3.2-20.el7.src.rpm:SOURCE \
		findutils-4.5.11-5.el7.src.rpm:SOURCE \
		freetype-2.4.11-11.el7.src.rpm:SOURCE \
		gamin-0.1.10-16.el7.src.rpm:SOURCE \
		gcc-4.8.5-4.el7.src.rpm:SOURCE \
		gdbm-1.10-8.el7.src.rpm:SOURCE \
		glib2-2.42.2-5.el7.src.rpm:SOURCE \
		glibc-2.17-106.el7_2.8.src.rpm:SOURCE \
		gmp-6.0.0-12.el7_1.src.rpm:SOURCE \
		grep-2.20-2.el7.src.rpm:SOURCE \
		keyutils-1.5.8-3.el7.src.rpm:SOURCE \
		krb5-1.13.2-12.el7_2.src.rpm:SOURCE \
		less-458-9.el7.src.rpm:SOURCE \
		libcap-2.22-8.el7.src.rpm:SOURCE \
		libdb-5.3.21-19.el7.src.rpm:SOURCE \
		libffi-3.0.13-16.el7.src.rpm:SOURCE \
		libidn-1.28-4.el7.src.rpm:SOURCE \
		libselinux-2.2.2-6.el7.src.rpm:SOURCE \
		libsepol-2.1.9-3.el7.src.rpm:SOURCE \
		ncurses-5.9-13.20130511.el7.src.rpm:SOURCE \
		pcre-8.32-15.el7_2.1.src.rpm:SOURCE \
		popt-1.13-16.el7.src.rpm:SOURCE \
		readline-6.2-9.el7.src.rpm:SOURCE \
		redhat-lsb-4.1-27.el7.centos.1.src.rpm:SOURCE \
		sed-4.2.2-5.el7.src.rpm:SOURCE \
		setserial-2.17-33.el7.src.rpm:SOURCE \
		setup-2.8.71-6.el7.src.rpm:SOURCE \
		slang-2.2.4-11.el7.src.rpm:SOURCE \
		texinfo-5.1-4.el7.src.rpm:SOURCE \
		util-linux-2.23.2-26.el7_2.3.src.rpm:SOURCE \
		which-2.20-7.el7.src.rpm:SOURCE \
		xz-5.1.2-12alpha.el7.src.rpm:SOURCE \
		zlib-1.2.7-15.el7.src.rpm:SOURCE

PLIST_SUB=	LINUXBASE=${LINUXBASE} SYSCTLMIB=${SYSCTLMIB}
USES=		linux:c7
USE_LINUX=	# empty
USE_LINUX_RPM=	yes

REMOVE_DIRS=	boot home media root run tmp usr/lib/pm-utils \
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
		${DISTDIR}/${DIST_SUBDIR}/filesystem-3.2-20.el7${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS})

post-patch:
	@${RM} -r ${REMOVE_DIRS:S|^|${WRKSRC}/|}
	@${RM} ${REMOVE_FILES:S|^|${WRKSRC}/|}
	@${BRANDELF} -t Linux ${WRKSRC}/usr/lib/ld-2.17.so
.if ${LINUX_ARCH} == x86_64
	@${BRANDELF} -t Linux ${WRKSRC}/usr/lib64/ld-2.17.so
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/dev/shm
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
