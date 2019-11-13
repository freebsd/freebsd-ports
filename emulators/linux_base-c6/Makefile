# Created by: Svyatoslav Lempert <svyatoslav.lempert@gmail dot com>
# $FreeBSD$

PORTNAME=	c6
PORTVERSION=	${LINUX_DIST_VER}
PORTREVISION=	2
CATEGORIES=	emulators linux
PKGNAMEPREFIX=	linux_base-

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Base set of packages needed in Linux mode (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c6
USE_LINUX=	# empty
USE_LINUX_RPM=	yes

BIN_DISTNAMES=	bash-4.1.2-48.el6 \
		bzip2-1.0.5-7.el6_0 \
		centos-release-6-10.el6.centos.12.3 \
		coreutils-8.4-47.el6 \
		e2fsprogs-1.41.12-24.el6 \
		elfutils-0.164-2.el6 \
		findutils-4.4.2-9.el6 \
		glibc-common-2.12-1.212.el6_10.3 \
		grep-2.20-6.el6 \
		info-4.13a-8.el6 \
		keyutils-1.4-5.el6 \
		less-436-13.el6 \
		ncurses-5.7-4.20090207.el6 \
		ncurses-base-5.7-4.20090207.el6 \
		sed-4.2.1-10.el6 \
		setserial-2.17-25.el6 \
		which-2.19-6.el6 \
		filesystem-2.4.30-3.el6
LIB_DISTNAMES=	bzip2-libs-1.0.5-7.el6_0 \
		compat-db43-4.3.29-17.el6 \
		compat-libstdc++-33-3.2.3-69.el6 \
		db4-4.7.25-22.el6 \
		e2fsprogs-libs-1.41.12-24.el6 \
		freetype-2.3.11-17.el6 \
		gamin-0.1.10-9.el6 \
		gdbm-1.8.0-39.el6 \
		glib2-2.28.8-10.el6 \
		glibc-2.12-1.212.el6_10.3 \
		gmp-4.3.1-13.el6 \
		keyutils-libs-1.4-5.el6 \
		krb5-libs-1.10.3-65.el6 \
		libacl-2.2.49-7.el6_9.1 \
		libattr-2.4.44-7.el6 \
		libblkid-2.17.2-12.28.el6_9.2 \
		libcap-2.16-5.5.el6 \
		libcom_err-1.41.12-24.el6 \
		libgcc-4.4.7-23.el6 \
		libidn-1.18-2.el6 \
		libselinux-2.0.94-7.el6 \
		libsepol-2.0.41-4.el6 \
		libstdc++-4.4.7-23.el6 \
		libuuid-2.17.2-12.28.el6_9.2 \
		ncurses-libs-5.7-4.20090207.el6 \
		nss-softokn-freebl-3.44.0-5.el6_10 \
		pcre-7.8-7.el6 \
		popt-1.13-7.el6 \
		readline-6.0-4.el6 \
		redhat-lsb-core-4.0-7.el6.centos \
		slang-2.2.1-1.el6 \
		util-linux-ng-2.17.2-12.28.el6_9.2 \
		zlib-1.2.3-29.el6
SHARE_DISTNAMES=basesystem-10.0-4.el6 \
		setup-2.8.14-23.el6
SRC_DISTFILES=	acl-2.2.49-7.el6_9.1${SRC_SUFX}:SOURCE \
		attr-2.4.44-7.el6${SRC_SUFX}:SOURCE \
		basesystem-10.0-4.el6${SRC_SUFX}:SOURCE \
		bash-4.1.2-48.el6${SRC_SUFX}:SOURCE \
		bzip2-1.0.5-7.el6_0${SRC_SUFX}:SOURCE \
		centos-release-6-10.el6.centos.12.3${SRC_SUFX}:SOURCE \
		compat-db-4.6.21-17.el6${SRC_SUFX}:SOURCE \
		compat-gcc-296-2.96-144.el6${SRC_SUFX}:SOURCE \
		compat-gcc-32-3.2.3-69.el6${SRC_SUFX}:SOURCE \
		coreutils-8.4-47.el6${SRC_SUFX}:SOURCE \
		db4-4.7.25-22.el6${SRC_SUFX}:SOURCE \
		e2fsprogs-1.41.12-24.el6${SRC_SUFX}:SOURCE \
		elfutils-0.164-2.el6${SRC_SUFX}:SOURCE \
		filesystem-2.4.30-3.el6${SRC_SUFX}:SOURCE \
		findutils-4.4.2-9.el6${SRC_SUFX}:SOURCE \
		freetype-2.3.11-17.el6${SRC_SUFX}:SOURCE \
		gamin-0.1.10-9.el6${SRC_SUFX}:SOURCE \
		gcc-4.4.7-23.el6${SRC_SUFX}:SOURCE \
		gdbm-1.8.0-39.el6${SRC_SUFX}:SOURCE \
		glib2-2.28.8-10.el6${SRC_SUFX}:SOURCE \
		glibc-2.12-1.212.el6_10.3${SRC_SUFX}:SOURCE \
		gmp-4.3.1-13.el6${SRC_SUFX}:SOURCE \
		grep-2.20-6.el6${SRC_SUFX}:SOURCE \
		keyutils-1.4-5.el6${SRC_SUFX}:SOURCE \
		krb5-1.10.3-65.el6${SRC_SUFX}:SOURCE \
		less-436-13.el6${SRC_SUFX}:SOURCE \
		libcap-2.16-5.5.el6${SRC_SUFX}:SOURCE \
		libidn-1.18-2.el6${SRC_SUFX}:SOURCE \
		libselinux-2.0.94-7.el6${SRC_SUFX}:SOURCE \
		libsepol-2.0.41-4.el6${SRC_SUFX}:SOURCE \
		ncurses-5.7-4.20090207.el6${SRC_SUFX}:SOURCE \
		nss-softokn-3.44.0-5.el6_10${SRC_SUFX}:SOURCE \
		pcre-7.8-7.el6${SRC_SUFX}:SOURCE \
		popt-1.13-7.el6${SRC_SUFX}:SOURCE \
		readline-6.0-4.el6${SRC_SUFX}:SOURCE \
		redhat-lsb-4.0-7.el6.centos${SRC_SUFX}:SOURCE \
		sed-4.2.1-10.el6${SRC_SUFX}:SOURCE \
		setserial-2.17-25.el6${SRC_SUFX}:SOURCE \
		setup-2.8.14-23.el6${SRC_SUFX}:SOURCE \
		slang-2.2.1-1.el6${SRC_SUFX}:SOURCE \
		texinfo-4.13a-8.el6${SRC_SUFX}:SOURCE \
		util-linux-ng-2.17.2-12.28.el6_9.2${SRC_SUFX}:SOURCE \
		which-2.19-6.el6${SRC_SUFX}:SOURCE \
		zlib-1.2.3-29.el6${SRC_SUFX}:SOURCE

PLIST_SUB=	LINUXBASE=${LINUXBASE} SYSCTLMIB=${SYSCTLMIB}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

REMOVE_DIRS=	boot home media mnt proc root sys tmp var/log var/run var/tmp
REMOVE_FILES=	bin/df bin/su etc/exports etc/group etc/gshadow etc/motd \
		etc/passwd etc/printcap etc/protocols etc/services etc/shadow

.include <bsd.port.options.mk>

.if ${ARCH} == amd64
SYSCTLMIB=	kern.features.linux64
.else
SYSCTLMIB=	compat.linux.osrelease
.endif

post-patch:
	@${RM} -r ${REMOVE_DIRS:S|^|${WRKSRC}/|}
	@${RM} ${REMOVE_FILES:S|^|${WRKSRC}/|}
	@${FIND} ${WRKSRC}/lib -type d -empty -delete
	@${FIND} ${WRKSRC}/usr -type d -empty -delete
	@${BRANDELF} -t Linux ${WRKSRC}/lib/ld-2.12.so
.if ${ARCH} == amd64
	@${FIND} ${WRKSRC}/lib64 -type d -empty -delete
	@${BRANDELF} -t Linux ${WRKSRC}/lib64/ld-2.12.so
.endif

post-install:
	${TOUCH} ${STAGEDIR}${PREFIX}/etc/mtab
	${MV} ${STAGEDIR}${PREFIX}/etc/krb5.conf \
		${STAGEDIR}${PREFIX}/etc/krb5.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/nsswitch.conf \
		${STAGEDIR}${PREFIX}/etc/nsswitch.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/usr/lib/locale/locale-archive.tmpl \
		${STAGEDIR}${PREFIX}/usr/lib/locale/locale-archive
	${LN} -sfh centos-release-6 \
		${STAGEDIR}${PREFIX}/usr/share/doc/redhat-release
	${LN} -sf ${LOCALBASE}/share/icons ${STAGEDIR}${PREFIX}/usr/share/icons
	${LN} -sfh /var/tmp ${STAGEDIR}${PREFIX}/usr/tmp
	${LN} -sf usr/bin ${STAGEDIR}${PREFIX}
	${LN} -sf usr/lib ${STAGEDIR}${PREFIX}
	${LN} -sf usr/sbin ${STAGEDIR}${PREFIX}
.if ${ARCH} == amd64
	${LN} -sf usr/lib64 ${STAGEDIR}${PREFIX}
.endif

.include <bsd.port.mk>
