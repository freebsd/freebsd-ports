# Created by: jamrich.majo@gmail.com
# $FreeBSD$

PORTNAME=	phpcollab
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	SF/phpcollab/final/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHPcollab is project management and collaboration over the internet

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
SHAREOWN=	${WWWOWN}
SHAREGRP=	${WWWGRP}

SUB_FILES=	pkg-message
PLIST_DIRSTRY=	%%WWWDIR%%

OPTIONS_DEFAULT=MYSQL APACHE
OPTIONS_SINGLE=	WEBSERVER DB
OPTIONS_SINGLE_WEBSERVER=	APACHE LIGHTTPD
OPTIONS_SINGLE_DB=	PGSQL MYSQL

MYSQL_USE=	PHP=mysql MYSQL=yes
PGSQL_USE=	PHP=pgsql,pdo_pgsql PGSQL=yes
APACHE_USE=	APACHE_RUN=22
LIGHTTPD_RUN_DEPENDS=	lighttpd:${PORTSDIR}/ww/lighttpd

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
