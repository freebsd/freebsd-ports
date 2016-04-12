# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DoctrineDBAL
PORTVERSION=	2.3.4
CATEGORIES=	databases pear
MASTER_SITES=	http://pear.doctrine-project.org/get/

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Database abstraction layer used to power the ORM package

LICENSE=	LGPL21

BUILD_DEPENDS=	${PEARDIR}/.channels/pear.doctrine-project.org.reg:devel/pear-channel-doctrine
RUN_DEPENDS=	${PEARDIR}/.channels/pear.doctrine-project.org.reg:devel/pear-channel-doctrine \
	${PEARDIR}/Doctrine/Common/Version.php:databases/pear-DoctrineCommon \
	${PEARDIR}/Symfony/Component/Console/Application.php:devel/pear-Symfony_Component_Console

OPTIONS_DEFINE=	DBLIB MYSQL ODBC PGSQL SQLITE
OPTIONS_DEFAULT=MYSQL

DBLIB_DESC=	Install PHP DBO driver for DBLIB
MYSQL_DESC=	Install PHP DBO driver for MySQL
ODBC_DESC=	Install PHP DBO driver for ODBC
PGSQL_DESC=	Install PHP DBO driver for PostgreSQL
SQLITE_DESC=	Install PHP DBO driver for SQLite

USES=		pear
PEAR_CHANNEL=	doctrine

USE_PHP=	pdo
WANT_PHP_CLI=	yes

DBLIB_RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_dblib.so:databases/php${PHP_VER}-pdo_dblib
MYSQL_USE=	PHP=pdo_mysql
ODBC_RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_odbc.so:databases/php${PHP_VER}-pdo_odbc
PGSQL_USE=	PHP=pdo_pgsql
SQLITE_USE=	PHP=pdo_sqlite

.include <bsd.port.mk>
