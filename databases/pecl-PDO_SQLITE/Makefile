# Ports collection makefile for:  pecl-PDO_SQLITE
# Date created:                   2005-09-10
# Whom:                           Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	PDO_SQLITE
DISTVERSION=	1.0.1
CATEGORIES=	databases www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	SQLite v3 Interface driver for PDO

BUILD_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo.so:${PORTSDIR}/databases/pecl-PDO
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3

USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=5
PHP_MODNAME=	pdo_sqlite

CONFIGURE_ARGS+=--with-pdo-sqlite=${LOCALBASE}

.include <bsd.port.mk>
