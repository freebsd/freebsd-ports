# Created by: jamrich.majo@gmail.com
# $FreeBSD$

PORTNAME=	phpcollab
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	SF/phpcollab/final/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHPcollab is project management and collaboration over the internet

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

IGNORE_WITH_PHP=	71 72 73

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
SHAREOWN=	${WWWOWN}
SHAREGRP=	${WWWGRP}

SUB_FILES=	pkg-message

OPTIONS_DEFAULT=MYSQL APACHE
OPTIONS_RADIO=	WEBSERVER DB
OPTIONS_RADIO_WEBSERVER=	APACHE LIGHTTPD
OPTIONS_RADIO_DB=	PGSQL MYSQL

MYSQL_USE=	PHP=mysql MYSQL=yes
PGSQL_USE=	PHP=pgsql,pdo_pgsql
PGSQL_USES=	pgsql
APACHE_USE=	APACHE_RUN=22+
LIGHTTPD_RUN_DEPENDS=	lighttpd:ww/lighttpd

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
