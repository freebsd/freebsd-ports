# Created by: Svyatoslav Lempert <svyatoslav.lempert@gmail dot com>
# $FreeBSD$

PORTNAME=	c6
PORTVERSION=	${LINUX_DIST_VER}
PORTREVISION=	6
CATEGORIES=	emulators linux
PKGNAMEPREFIX=	linux_base-

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Base set of packages needed in Linux mode for i386/amd64 (Linux CentOS 6)

BIN_DISTFILES=	basesystem-10.0-4.el6.noarch.rpm \
		bash-4.1.2-40.el6${EXTRACT_SUFX} \
		bzip2-1.0.5-7.el6_0${EXTRACT_SUFX} \
		centos-release-6-8.el6.centos.12.3${EXTRACT_SUFX} \
		compat-libstdc++-296-2.96-144.el6.i686.rpm \
		coreutils-8.4-43.el6${EXTRACT_SUFX} \
		e2fsprogs-1.41.12-22.el6${EXTRACT_SUFX} \
		elfutils-0.164-2.el6${EXTRACT_SUFX} \
		findutils-4.4.2-9.el6${EXTRACT_SUFX} \
		glibc-common-2.12-1.192.el6${EXTRACT_SUFX} \
		grep-2.20-5.el6_8${EXTRACT_SUFX} \
		info-4.13a-8.el6${EXTRACT_SUFX} \
		keyutils-1.4-5.el6${EXTRACT_SUFX} \
		less-436-13.el6${EXTRACT_SUFX} \
		ncurses-5.7-4.20090207.el6${EXTRACT_SUFX} \
		sed-4.2.1-10.el6${EXTRACT_SUFX} \
		setserial-2.17-25.el6${EXTRACT_SUFX} \
		setup-2.8.14-20.el6_4.1.noarch.rpm \
		which-2.19-6.el6${EXTRACT_SUFX} \
		filesystem-2.4.30-3.el6${EXTRACT_SUFX}
LIB_DISTFILES=	bzip2-libs-1.0.5-7.el6_0${EXTRACT_SUFX} \
		compat-db43-4.3.29-15.el6${EXTRACT_SUFX} \
		compat-libstdc++-33-3.2.3-69.el6${EXTRACT_SUFX} \
		db4-4.7.25-20.el6_7${EXTRACT_SUFX} \
		e2fsprogs-libs-1.41.12-22.el6${EXTRACT_SUFX} \
		freetype-2.3.11-17.el6${EXTRACT_SUFX} \
		gamin-0.1.10-9.el6${EXTRACT_SUFX} \
		gdbm-1.8.0-39.el6${EXTRACT_SUFX} \
		glib2-2.28.8-5.el6${EXTRACT_SUFX} \
		glibc-2.12-1.192.el6${EXTRACT_SUFX} \
		gmp-4.3.1-10.el6${EXTRACT_SUFX} \
		keyutils-libs-1.4-5.el6${EXTRACT_SUFX} \
		krb5-libs-1.10.3-57.el6${EXTRACT_SUFX} \
		libacl-2.2.49-6.el6${EXTRACT_SUFX} \
		libattr-2.4.44-7.el6${EXTRACT_SUFX} \
		libblkid-2.17.2-12.24.el6_8.1${EXTRACT_SUFX} \
		libcap-2.16-5.5.el6${EXTRACT_SUFX} \
		libcom_err-1.41.12-22.el6${EXTRACT_SUFX} \
		libgcc-4.4.7-17.el6${EXTRACT_SUFX} \
		libidn-1.18-2.el6${EXTRACT_SUFX} \
		libselinux-2.0.94-7.el6${EXTRACT_SUFX} \
		libsepol-2.0.41-4.el6${EXTRACT_SUFX} \
		libstdc++-4.4.7-17.el6${EXTRACT_SUFX} \
		libuuid-2.17.2-12.24.el6_8.1${EXTRACT_SUFX} \
		ncurses-libs-5.7-4.20090207.el6${EXTRACT_SUFX} \
		pcre-7.8-7.el6${EXTRACT_SUFX} \
		popt-1.13-7.el6${EXTRACT_SUFX} \
		readline-6.0-4.el6${EXTRACT_SUFX} \
		redhat-lsb-core-4.0-7.el6.centos${EXTRACT_SUFX} \
		slang-2.2.1-1.el6${EXTRACT_SUFX} \
		util-linux-ng-2.17.2-12.24.el6_8.1${EXTRACT_SUFX} \
		zlib-1.2.3-29.el6${EXTRACT_SUFX}
SRC_DISTFILES=	acl-2.2.49-6.el6${SRC_SUFX}:SOURCE \
		attr-2.4.44-7.el6${SRC_SUFX}:SOURCE \
		basesystem-10.0-4.el6${SRC_SUFX}:SOURCE \
		bash-4.1.2-40.el6${SRC_SUFX}:SOURCE \
		bzip2-1.0.5-7.el6_0${SRC_SUFX}:SOURCE \
		centos-release-6-8.el6.centos.12.3${SRC_SUFX}:SOURCE \
		compat-db-4.6.21-15.el6${SRC_SUFX}:SOURCE \
		compat-gcc-296-2.96-144.el6${SRC_SUFX}:SOURCE \
		compat-gcc-32-3.2.3-69.el6${SRC_SUFX}:SOURCE \
		coreutils-8.4-43.el6${SRC_SUFX}:SOURCE \
		db4-4.7.25-20.el6_7${SRC_SUFX}:SOURCE \
		e2fsprogs-1.41.12-22.el6${SRC_SUFX}:SOURCE \
		elfutils-0.164-2.el6${SRC_SUFX}:SOURCE \
		filesystem-2.4.30-3.el6${SRC_SUFX}:SOURCE \
		findutils-4.4.2-9.el6${SRC_SUFX}:SOURCE \
		freetype-2.3.11-17.el6${SRC_SUFX}:SOURCE \
		gamin-0.1.10-9.el6${SRC_SUFX}:SOURCE \
		gcc-4.4.7-17.el6${SRC_SUFX}:SOURCE \
		gdbm-1.8.0-39.el6${SRC_SUFX}:SOURCE \
		glib2-2.28.8-5.el6${SRC_SUFX}:SOURCE \
		glibc-2.12-1.192.el6${SRC_SUFX}:SOURCE \
		gmp-4.3.1-10.el6${SRC_SUFX}:SOURCE \
		grep-2.20-5.el6_8${SRC_SUFX}:SOURCE \
		keyutils-1.4-5.el6${SRC_SUFX}:SOURCE \
		krb5-1.10.3-57.el6${SRC_SUFX}:SOURCE \
		less-436-13.el6${SRC_SUFX}:SOURCE \
		libcap-2.16-5.5.el6${SRC_SUFX}:SOURCE \
		libidn-1.18-2.el6${SRC_SUFX}:SOURCE \
		libselinux-2.0.94-7.el6${SRC_SUFX}:SOURCE \
		libsepol-2.0.41-4.el6${SRC_SUFX}:SOURCE \
		ncurses-5.7-4.20090207.el6${SRC_SUFX}:SOURCE \
		pcre-7.8-7.el6${SRC_SUFX}:SOURCE \
		popt-1.13-7.el6${SRC_SUFX}:SOURCE \
		readline-6.0-4.el6${SRC_SUFX}:SOURCE \
		redhat-lsb-4.0-7.el6.centos${SRC_SUFX}:SOURCE \
		sed-4.2.1-10.el6${SRC_SUFX}:SOURCE \
		setserial-2.17-25.el6${SRC_SUFX}:SOURCE \
		setup-2.8.14-20.el6_4.1${SRC_SUFX}:SOURCE \
		slang-2.2.1-1.el6${SRC_SUFX}:SOURCE \
		texinfo-4.13a-8.el6${SRC_SUFX}:SOURCE \
		util-linux-ng-2.17.2-12.24.el6_8.1${SRC_SUFX}:SOURCE \
		which-2.19-6.el6${SRC_SUFX}:SOURCE \
		zlib-1.2.3-29.el6${SRC_SUFX}:SOURCE

CONFLICTS=	linux_base-gentoo* linux_base-f10-[0-9]* linux-glib2-*
PLIST_SUB=	LINUXBASE=${LINUXBASE} SYSCTLMIB=${SYSCTLMIB}
USES=		linux:c6
USE_LINUX=	# empty
USE_LINUX_RPM=	yes

REMOVE_DIRS=	boot home media root tmp usr/lib/pm-utils usr/lib64/pm-utils \
		usr/local var/log var/run var/tmp
REMOVE_FILES=	bin/df bin/su etc/exports etc/group etc/gshadow etc/motd \
		etc/passwd etc/printcap etc/protocols etc/services etc/shadow \
		usr/tmp

.include <bsd.port.pre.mk>

.if ${LINUX_ARCH} == x86_64 && ${OPSYS} == FreeBSD && ${OSVERSION} >= 11000105
SYSCTLMIB=	kern.features.linux64
.else
SYSCTLMIB=	compat.linux.osrelease
.endif

post-patch:
	@${RM} -r ${REMOVE_DIRS:S|^|${WRKSRC}/|}
	@${RM} ${REMOVE_FILES:S|^|${WRKSRC}/|}
	@${LN} -sfh centos-release-6 ${WRKSRC}/usr/share/doc/redhat-release
	@${BRANDELF} -t Linux ${WRKSRC}/lib/ld-2.12.so
.if ${LINUX_ARCH} == x86_64
	@${BRANDELF} -t Linux ${WRKSRC}/lib64/ld-2.12.so
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
	${LN} -sf /var/tmp ${STAGEDIR}${PREFIX}/usr/tmp
	${LN} -sf ../usr/bin/[ ${STAGEDIR}${PREFIX}/bin/[
	${LN} -sf ../usr/bin/expr ${STAGEDIR}${PREFIX}/bin/expr
	${LN} -sf ../usr/bin/test ${STAGEDIR}${PREFIX}/bin/test
	${LN} -sf ../usr/bin/uuidgen ${STAGEDIR}${PREFIX}/bin/uuidgen
	${LN} -sf ../../lib/librt.so.1 ${STAGEDIR}${PREFIX}/usr/lib/librt.so.1

.include <bsd.port.post.mk>
