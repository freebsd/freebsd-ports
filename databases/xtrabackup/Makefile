PORTNAME=	xtrabackup
DISTVERSION=	2.4.28
CATEGORIES=	databases
MASTER_SITES=	https://www.percona.com/downloads/Percona-XtraBackup-${PORTVERSION:R}/Percona-XtraBackup-${PORTVERSION}/source/tarball/:xtrabackup \
		https://ftp.osuosl.org/pub/blfs/conglomeration/boost/:boost SF/boost/boost/1.59.0/:boost
DISTFILES=	percona-${PORTNAME}-${PORTVERSION}.tar.gz:xtrabackup \
		boost_1_59_0.tar.bz2:boost

MAINTAINER=	samm@FreeBSD.org
COMMENT=	OpenSource version of InnoDB backup with support of Percona extensions
WWW=		https://www.percona.com/doc/percona-xtrabackup/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv6=		fails to compile: cannot combine with previous 'type-name' declaration specifier
BROKEN_armv7=		fails to compile: cannot combine with previous 'type-name' declaration specifier
BROKEN_mips64=		fails to compile: 'fpsetmask' was not declared in this scope

# quilt is required by build.sh
BUILD_DEPENDS=	bash:shells/bash \
		cmake:devel/cmake-core
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libev.so:devel/libev \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error
RUN_DEPENDS=	qpress:archivers/qpress

USES=		alias autoreconf:build bison cmake:noninja compiler:c++11-lang \
		cpe gettext libtool perl5 shebangfix
USE_CXXSTD=	c++11

CONFLICTS_INSTALL=	${PORTNAME}8

CPE_VENDOR=	percona
SHEBANG_FILES=	storage/innobase/xtrabackup/xbcloud_osenv.sh
CMAKE_ARGS=	-DWITH_BOOST=${WRKDIR}/boost_1_59_0 -DWITH_VERSION_CHECK=OFF

WRKSRC=		${WRKDIR}/percona-${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/xtrabackup bin/xbstream bin/innobackupex bin/xbcrypt \
		bin/xbcloud bin/xbcloud_osenv

.include <bsd.port.pre.mk>

# Not sure why it's trying to install mysql client libraries now
post-install:
	${RM} -rf ${STAGEDIR}${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|__clang__|__undefined__|g' \
	    ${WRKDIR}/boost_1_59_0/boost/atomic/detail/ops_gcc_x86_dcas.hpp

.include <bsd.port.post.mk>
