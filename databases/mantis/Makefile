# Created by: Sebastien Gioria <gioria@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mantis
PORTVERSION=	1.2.19
PORTREVISION=	1
CATEGORIES=	databases www
MASTER_SITES=	SF/${PORTNAME}bt/${PORTNAME}-stable/${PORTVERSION}
DISTNAME=	mantisbt-${PORTVERSION}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Bug tracking system written in PHP

BROKEN_powerpc64=	Does not build

NO_BUILD=	yes
USE_PHP=	hash pcre session xml

OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL

MYSQL_DESC=	MySQL support
PGSQL_DESC=	PostgreSQL support

OPTIONS_DEFAULT=	MYSQL

MYSQL_USE=	mysql=yes php=mysql
PGSQL_USE=	pgsql=yes php=pgsql

SUB_FILES=	pkg-message

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
