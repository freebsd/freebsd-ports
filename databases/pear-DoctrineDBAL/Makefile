PORTNAME=	DoctrineDBAL
PORTVERSION=	2.3.4
CATEGORIES=	databases pear
MASTER_SITES=	http://pear.doctrine-project.org/get/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Database abstraction layer used to power the ORM package
WWW=		https://www.doctrine-project.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream no longer serves through PEAR channel and has been moved to Composer
EXPIRATION_DATE=	2025-08-03

RUN_DEPENDS=	${PEARDIR}/Doctrine/Common/Version.php:databases/pear-DoctrineCommon@${PHP_FLAVOR} \
		${PEARDIR}/Symfony/Component/Console/Application.php:devel/pear-Symfony_Component_Console@${PHP_FLAVOR}

CONFLICTS_INSTALL=	php*-pear-doctrine-DoctrineDBAL

OPTIONS_DEFINE=	DBLIB MYSQL ODBC PGSQL SQLITE
OPTIONS_DEFAULT=MYSQL

DBLIB_DESC=	Install PHP DBO driver for DBLIB
MYSQL_DESC=	Install PHP DBO driver for MySQL
ODBC_DESC=	Install PHP DBO driver for ODBC
PGSQL_DESC=	Install PHP DBO driver for PostgreSQL
SQLITE_DESC=	Install PHP DBO driver for SQLite

USES=		pear php:cli
PEAR_CHANNEL=	doctrine

USE_PHP=	pdo

NO_ARCH=	yes

DBLIB_RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_dblib.so:databases/php${PHP_VER}-pdo_dblib
MYSQL_USE=	PHP=pdo_mysql
ODBC_RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_odbc.so:databases/php${PHP_VER}-pdo_odbc
PGSQL_USE=	PHP=pdo_pgsql
SQLITE_USE=	PHP=pdo_sqlite

.include <bsd.port.mk>
