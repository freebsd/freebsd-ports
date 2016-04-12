# Created by: gahr
# $FreeBSD$

PORTNAME=	cdash
PORTVERSION=	2.2.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.cdash.org/wp-content/uploads/2014/11/
DISTNAME=	CDash-2-2-3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web-based software testing server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		dos2unix cmake:outsource zip
DOS2UNIX_GLOB=	*.php *.xml *.xsl *.txt
CMAKE_ARGS=	-DCDASH_DB_NAME:STRING=cdash \
		-DCDASH_DB_LOGIN:STRING=cdash \
		-DCDASH_DB_TYPE:STRING=${DB_TYPE}
USE_PHP=	curl gd pdo session xsl zlib
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S/./-/g}
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message
SUB_LIST=	DB_TYPE=${DB_TYPE}

OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL
OPTIONS_DEFAULT=MYSQL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
USE_PHP+=	pdo_mysql
DB_TYPE=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
USE_PHP+=	pgsql pdo_pgsql
DB_TYPE=	pgsql
.endif

do-install:
	${MKDIR} ${WRKSRC}/rss
	${CP} ${WRKSRC}/backup/.htaccess ${WRKSRC}/rss/.htaccess
	${MKDIR} ${STAGEDIR}${PREFIX}/www/CDash
	${FIND} ${WRKSRC} -name "*.orig" -delete
	${MV} ${WRKSRC}/cdash/config.local.php ${WRKSRC}/cdash/config.local.sample.php
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/www/CDash

.include <bsd.port.mk>
