# Created by: Marek Holienka <marekholienka@gmail.com>
# $FreeBSD$

PORTNAME=	mysqldumper
PORTVERSION=	1.24.4
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/MySQLDumper/
DISTNAME=	MySQLDumper${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool for backing up MySQL databases

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/ReadMe/license_english.txt

RUN_DEPENDS=	p5-DBI>=1.48:databases/p5-DBI

OPTIONS_DEFINE=	APACHE LIGHTTPD
OPTIONS_DEFAULT=APACHE

PORTSCOUT=	limit:^[0-9\.]*$$

IGNORE_WITH_PHP=71 72 73
NO_ARCH=	yes
NO_BUILD=	yes
USE_PHP=	ftp mysql session zlib
USES=		cpe mysql perl5 php zip

PLIST_SUB=	WWWGRP=${WWWGRP} WWWOWN=${WWWOWN}
WRKSRC=		${WRKDIR}/msd${PORTVERSION}

APACHE_USE=		APACHE_RUN=22+
LIGHTTPD_RUN_DEPENDS=	${LOCALBASE}/sbin/lighttpd:www/lighttpd

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
