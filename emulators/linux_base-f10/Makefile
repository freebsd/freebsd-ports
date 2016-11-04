# Created by: bsam
# $FreeBSD$

PORTNAME=	f10
PORTVERSION=	${LINUX_DIST_VER}
PORTREVISION=	12
CATEGORIES=	emulators linux
PKGNAMEPREFIX=	linux_base-

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Base set of packages needed in Linux mode for i386/amd64 (Linux Fedora 10)

BIN_DISTFILES=	basesystem-10.0-1.noarch.rpm \
		bash-3.2-30.fc10${EXTRACT_SUFX} \
		bzip2-1.0.5-3.fc10${EXTRACT_SUFX} \
		bzip2-libs-1.0.5-3.fc10${EXTRACT_SUFX} \
		compat-db-4.6.21-5.fc10${EXTRACT_SUFX} \
		compat-libstdc++-296-2.96-141${EXTRACT_SUFX} \
		compat-libstdc++-33-3.2.3-64${EXTRACT_SUFX} \
		coreutils-6.12-20.fc10${EXTRACT_SUFX} \
		db4-4.7.25-7.fc10${EXTRACT_SUFX} \
		e2fsprogs-1.41.4-6.fc10${EXTRACT_SUFX} \
		e2fsprogs-libs-1.41.4-6.fc10${EXTRACT_SUFX} \
		elfutils-0.142-1.fc10${EXTRACT_SUFX} \
		fedora-release-10-1.noarch.rpm \
		filesystem-2.4.19-1.fc10${EXTRACT_SUFX} \
		freetype-2.3.7-3.fc10${EXTRACT_SUFX} \
		gamin-0.1.9-6.fc10${EXTRACT_SUFX} \
		gdbm-1.8.0-29.fc10${EXTRACT_SUFX} \
		glib-1.2.10-32.fc10${EXTRACT_SUFX} \
		glib2-2.18.4-2.fc10${EXTRACT_SUFX} \
		glibc-2.9-3${EXTRACT_SUFX} \
		glibc-common-2.9-3${EXTRACT_SUFX} \
		gmp-4.2.2-8.fc10${EXTRACT_SUFX} \
		grep-2.5.1a-61.fc10${EXTRACT_SUFX} \
		info-4.12-4.fc10${EXTRACT_SUFX} \
		keyutils-libs-1.2-3.fc9${EXTRACT_SUFX} \
		krb5-libs-1.6.3-18.fc10${EXTRACT_SUFX} \
		libacl-2.2.47-3.fc10${EXTRACT_SUFX} \
		libattr-2.4.43-2.fc10${EXTRACT_SUFX} \
		libcap-2.10-2.fc10${EXTRACT_SUFX} \
		libgcc-4.3.2-7${EXTRACT_SUFX} \
		libidn-0.6.14-8${EXTRACT_SUFX} \
		libselinux-2.0.78-1.fc10${EXTRACT_SUFX} \
		libsepol-2.0.33-1.fc10${EXTRACT_SUFX} \
		libstdc++-4.3.2-7${EXTRACT_SUFX} \
		ncurses-5.6-20.20080927.fc10${EXTRACT_SUFX} \
		ncurses-libs-5.6-20.20080927.fc10${EXTRACT_SUFX} \
		pcre-7.8-1.fc10${EXTRACT_SUFX} \
		popt-1.13-4.fc10${EXTRACT_SUFX} \
		readline-5.2-13.fc9${EXTRACT_SUFX} \
		setserial-2.17-22.fc9${EXTRACT_SUFX} \
		setup-2.7.4-4.fc10.noarch.rpm \
		slang-2.1.4-1.fc10${EXTRACT_SUFX} \
		zlib-1.2.3-18.fc9${EXTRACT_SUFX}
SRC_DISTFILES=	acl-2.2.47-3.fc10.src.rpm:SOURCE \
		attr-2.4.43-1.fc10.src.rpm:SOURCE \
		basesystem-10.0-1.src.rpm:SOURCE \
		bash-3.2-29.fc10.src.rpm:SOURCE \
		bzip2-1.0.5-3.fc10.src.rpm:SOURCE \
		compat-db-4.6.21-5.fc10.src.rpm:SOURCE \
		coreutils-6.12-17.fc10.src.rpm:SOURCE \
		db4-4.7.25-5.fc10.src.rpm:SOURCE \
		e2fsprogs-1.41.4-6.fc10.src.rpm:SOURCE \
		elfutils-0.142-1.fc10.src.rpm:SOURCE \
		fedora-release-10-1.src.rpm:SOURCE \
		filesystem-2.4.19-1.fc10.src.rpm:SOURCE \
		freetype-2.3.7-1.fc10.src.rpm:SOURCE \
		gamin-0.1.9-6.fc10.src.rpm:SOURCE \
		gcc-4.3.2-7.src.rpm:SOURCE \
		gdbm-1.8.0-29.fc10.src.rpm:SOURCE \
		glib-1.2.10-32.fc10.src.rpm:SOURCE \
		glib2-2.18.2-3.fc10.src.rpm:SOURCE \
		glibc-2.9-2.src.rpm:SOURCE \
		gmp-4.2.2-8.fc10.src.rpm:SOURCE \
		grep-2.5.1a-61.fc10.src.rpm:SOURCE \
		keyutils-1.2-3.fc9.src.rpm:SOURCE \
		krb5-1.6.3-16.fc10.src.rpm:SOURCE \
		libcap-2.10-2.fc10.src.rpm:SOURCE \
		libidn-0.6.14-8.src.rpm:SOURCE \
		libselinux-2.0.73-1.fc10.src.rpm:SOURCE \
		libsepol-2.0.33-1.fc10.src.rpm:SOURCE \
		ncurses-5.6-20.20080927.fc10.src.rpm:SOURCE \
		pcre-7.8-1.fc10.src.rpm:SOURCE \
		readline-5.2-13.fc9.src.rpm:SOURCE \
		setserial-2.17-22.fc9.src.rpm:SOURCE \
		setup-2.7.4-1.fc10.src.rpm:SOURCE \
		slang-2.1.4-1.fc10.src.rpm:SOURCE \
		texinfo-4.12-4.fc10.src.rpm:SOURCE \
		zlib-1.2.3-18.fc9.src.rpm:SOURCE

CONFLICTS=	linux_base-gentoo* linux_base-fc4-[0-9]* linux_base-fc6-[0-9]* \
		linux_base-f7-[0-9]* linux_base-f8-[0-9]* linux_base-f9-[0-9]* \
		linux_base-c* linux-glib2-*
ONLY_FOR_ARCHS=	i386 amd64
PLIST_SUB=	LINUXBASE=${LINUXBASE}
USES=		linux:f10
USE_LINUX=	# empty
USE_LINUX_RPM=	nolib

REMOVE_DIRS=	boot etc/fonts home media root tmp var/log var/run var/tmp \
		usr/local
REMOVE_FILES=	bin/df bin/su etc/exports etc/group etc/localtime \
		etc/motd etc/passwd etc/printcap etc/protocols etc/services \
		usr/tmp

post-patch:
	@${RM} -r ${REMOVE_DIRS:S|^|${WRKSRC}/|}
	@${RM} ${REMOVE_FILES:S|^|${WRKSRC}/|}
	@${BRANDELF} -t Linux ${WRKSRC}/lib/ld-2.9.so

post-install:
	${TOUCH} ${STAGEDIR}${PREFIX}/etc/mtab
	${MV} ${STAGEDIR}${PREFIX}/etc/krb5.conf \
		${STAGEDIR}${PREFIX}/etc/krb5.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/nsswitch.conf \
		${STAGEDIR}${PREFIX}/etc/nsswitch.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/usr/lib/locale/locale-archive.tmpl \
		${STAGEDIR}${PREFIX}/usr/lib/locale/locale-archive
	${LN} -sf /tmp ${STAGEDIR}${PREFIX}/dev/shm
	${LN} -sf /var/tmp ${STAGEDIR}${PREFIX}/usr/tmp
	${LN} -sf ../usr/bin/[ ${STAGEDIR}${PREFIX}/bin/[
	${LN} -sf ../usr/bin/expr ${STAGEDIR}${PREFIX}/bin/expr
	${LN} -sf ../usr/bin/test ${STAGEDIR}${PREFIX}/bin/test
	${LN} -sf ../usr/bin/uuidgen ${STAGEDIR}${PREFIX}/bin/uuidgen

.include <bsd.port.mk>
