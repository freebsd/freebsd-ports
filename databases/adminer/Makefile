PORTNAME=	adminer
DISTVERSION=	5.4.1
CATEGORIES=	databases www
MASTER_SITES=	https://github.com/vrana/${PORTNAME}/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${DISTVERSION}.zip

MAINTAINER=	pkaipila@gmail.com
COMMENT=	Full-featured database management tool in a single PHP file
WWW=		https://www.adminer.org

LICENSE=	APACHE20

DEPRECATED=     Project's poor security practices
EXPIRATION_DATE=2026-06-30

USES=		cpe php:build,flavors
USE_GITHUB=	nodefault
_FORCED_TAG=	1.2
_PEMATON_TAG=	99912d508a1b39db27910ef6c6dd07bab9368670
GH_TUPLE=	MirLach:adminer-forced-server:${_FORCED_TAG}:forcedserver \
		vrana:adminer-plugins-pematon:${_PEMATON_TAG}:pematon
USE_PHP=	phar session tokenizer zlib

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
	${MV} ${WRKDIR}/adminer-forced-server-${_FORCED_TAG}/adminer-plugins/forced-server.php \
	      ${WRKDIR}/adminer-plugins-pematon-${_PEMATON_TAG}/*.php \
		${WRKSRC}/plugins
	@(cd ${WRKSRC} && ${LOCALBASE}/bin/php ${WRKSRC}/compile.php)
	${MV} ${WRKSRC}/${PORTNAME}-${DISTVERSION}.php ${WRKSRC}/${PORTNAME}.php
	${CP} ${FILESDIR}/makephar.php ${WRKSRC}
	${LOCALBASE}/bin/php -d phar.readonly=0 ${WRKSRC}/makephar.php

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/index.php ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/adminer-plugins-example.php ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
