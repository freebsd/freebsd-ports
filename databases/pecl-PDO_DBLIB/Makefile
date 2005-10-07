# Ports collection makefile for:	pecl-PDO_DBLIB
# Date created:				2005-10-03
# Whom:					Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	PDO_DBLIB
DISTVERSION=	1.0RC1
CATEGORIES=	databases www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	FreeTDS/Sybase/MSSQL driver for PDO

BUILD_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo.so:${PORTSDIR}/databases/pecl-PDO
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=5
PHP_MODNAME=	pdo_dblib

CONFIGURE_ARGS+=--with-pdo-dblib=${LOCALBASE}

OPTIONS=	MSSQL		"Enable Microsoft SQL Server support"	off

.include <bsd.port.pre.mk>

.if defined(WITH_MSSQL)
LIB_DEPENDS+=	sybdb.5:${PORTSDIR}/databases/freetds-msdblib
.else
LIB_DEPENDS+=	ct.3:${PORTSDIR}/databases/freetds
.endif

.include <bsd.port.post.mk>
