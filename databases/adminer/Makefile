PORTNAME=	adminer
DISTVERSION=	5.3.0
PORTREVISION=	1
CATEGORIES=	databases www
MASTER_SITES=	https://github.com/vrana/${PORTNAME}/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${DISTVERSION}.php ${PORTNAME}-${DISTVERSION}.zip
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}.zip

MAINTAINER=	pkaipila@gmail.com
COMMENT=	Full-featured database management tool written in PHP
WWW=		https://www.adminer.org

LICENSE=	APACHE20

USES=		cpe php:build,flavors
USE_PHP=	phar session zlib

NO_ARCH=	yes

PLIST_SUB=	WWWGRP="${WWWGRP}" \
		WWWOWN="${WWWOWN}"

OPTIONS_DEFINE=		MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	MYSQL SQLITE

MYSQL_DESC=		MySQL and MariaDB driver
PGSQL_DESC=		PostgreSQL driver
SQLITE_DESC=		SQLite driver

MYSQL_USE=		PHP=mysqli
PGSQL_USE=		PHP=pgsql
SQLITE_USE=		PHP=sqlite3

do-build:
	${CP} ${DISTDIR}/${PORTNAME}-${DISTVERSION}.php ${WRKSRC}/${PORTNAME}.php
	${CP} ${FILESDIR}/makephar.php ${WRKSRC}
	${LOCALBASE}/bin/php -d phar.readonly=0 ${WRKSRC}/makephar.php

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/index.php ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
