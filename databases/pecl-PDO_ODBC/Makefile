# Ports collection makefile for:	pecl-PDO_ODBC
# Date created:				2005-10-03
# Whom:					Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	PDO_ODBC
DISTVERSION=	1.0.1
CATEGORIES=	databases www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	ODBC v3 Interface driver for PDO

BUILD_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo.so:${PORTSDIR}/databases/pecl-PDO
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	odbc.1:${PORTSDIR}/databases/unixODBC

USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=5
PHP_MODNAME=	pdo_odbc

CONFIGURE_ARGS+=--with-pdo-odbc=unixODBC,${LOCALBASE}
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"

.include <bsd.port.mk>
