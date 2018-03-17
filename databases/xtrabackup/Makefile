# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	xtrabackup
DISTVERSION=	2.4.9
CATEGORIES=	databases
MASTER_SITES=	https://www.percona.com/downloads/XtraBackup/Percona-XtraBackup-${PORTVERSION}/source/tarball/:xtrabackup \
		SF/boost/boost/1.59.0/:boost
DISTFILES=	percona-${PORTNAME}-${PORTVERSION}.tar.gz:xtrabackup \
		boost_1_59_0.tar.bz2:boost

MAINTAINER=	aleks@twindb.com
COMMENT=	OpenSource version of InnoDB backup with support of Percona extensions

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

# quilt is required by build.sh
BUILD_DEPENDS=	bash:shells/bash \
		cmake:devel/cmake \
		xxd:editors/vim-console
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libev.so:devel/libev \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error
RUN_DEPENDS=	p5-DBD-mysql>=0:databases/p5-DBD-mysql \
		qpress:archivers/qpress

BROKEN_armv6=		fails to compile: cannot combine with previous 'type-name' declaration specifier
BROKEN_armv7=		fails to compile: cannot combine with previous 'type-name' declaration specifier
BROKEN_mips64=		fails to compile: 'fpsetmask' was not declared in this scope
BROKEN_powerpc64=	fails to link: ld: final link failed: Bad value

# autotool is in use for 5.1 builds
USES=		alias autoreconf:build bison cpe gettext cmake:noninja libtool perl5 shebangfix
CPE_VENDOR=	percona
SHEBANG_FILES=	storage/innobase/xtrabackup/xbcloud_osenv.sh
CMAKE_ARGS=	-DWITH_BOOST=${WRKDIR}/boost_1_59_0

WRKSRC=		${WRKDIR}/percona-${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/xtrabackup bin/xbstream bin/innobackupex bin/xbcrypt \
		bin/xbcloud bin/xbcloud_osenv

.include <bsd.port.mk>
