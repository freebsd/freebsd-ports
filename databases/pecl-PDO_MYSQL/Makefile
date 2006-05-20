# Ports collection makefile for:  pecl-PDO_MYSQL
# Date created:                   2005-09-10
# Whom:                           Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	PDO_MYSQL
PORTVERSION=	1.0.2
CATEGORIES=	databases www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	MySQL 3.x/4.0 driver for PDO

BUILD_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo.so:${PORTSDIR}/databases/pecl-PDO
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=5
PHP_MODNAME=	pdo_mysql

CONFIGURE_ARGS+=--with-pdo-mysql=${LOCALBASE}

USE_MYSQL=	yes

.include <bsd.port.mk>
