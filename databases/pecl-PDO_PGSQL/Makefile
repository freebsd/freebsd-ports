# Ports collection makefile for:  pecl-PDO_PGSQL
# Date created:                   2005-09-10
# Whom:                           Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	PDO_PGSQL
DISTVERSION=	1.0.2
CATEGORIES=	databases www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	PostgreSQL driver for PDO

BUILD_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo.so:${PORTSDIR}/databases/pecl-PDO
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=5
PHP_MODNAME=	pdo_pgsql

CONFIGURE_ARGS+=--with-pdo-pgsql=${LOCALBASE}

USE_PGSQL=	yes

.include <bsd.port.mk>
