# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DoctrineDBAL
PORTVERSION=	2.3.4
CATEGORIES=	databases pear
MASTER_SITES=	http://pear.doctrine-project.org/get/

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Database abstraction layer used to power the ORM package

LICENSE=	LGPL21

BUILD_DEPENDS=	${PEARDIR}/.channels/pear.doctrine-project.org.reg:${PORTSDIR}/devel/pear-channel-doctrine
RUN_DEPENDS=	${PEARDIR}/.channels/pear.doctrine-project.org.reg:${PORTSDIR}/devel/pear-channel-doctrine \
	${PEARDIR}/Doctrine/Common/Version.php:${PORTSDIR}/databases/pear-DoctrineCommon \
	${PEARDIR}/Symfony/Component/Console/Application.php:${PORTSDIR}/devel/pear-Symfony_Component_Console

OPTIONSFILE?=	${PORT_DBDIR}/pear-${PORTNAME}/options
OPTIONS_DEFINE=	DBLIB MYSQL ODBC PGSQL SQLITE
OPTIONS_DEFAULT=MYSQL

DBLIB_DESC=	Install PHP DBO driver for DBLIB
MYSQL_DESC=	Install PHP DBO driver for MySQL
ODBC_DESC=	Install PHP DBO driver for ODBC
PGSQL_DESC=	Install PHP DBO driver for PostgreSQL
SQLITE_DESC=	Install PHP DBO driver for SQLite

PEAR_CHANNEL=	doctrine
PEAR_AUTOINSTALL=	yes

USE_PHP=	pdo
WANT_PHP_CLI=	yes

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDBLIB}
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_dblib.so:${PORTSDIR}/databases/php${PHP_VER}-pdo_dblib
.endif
.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	pdo_mysql
.endif
.if ${PORT_OPTIONS:MODBC}
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_odbc.so:${PORTSDIR}/databases/php${PHP_VER}-pdo_odbc
.endif
.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pdo_pgsql
.endif
.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=	pdo_sqlite
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
