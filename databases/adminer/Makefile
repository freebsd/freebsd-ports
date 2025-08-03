PORTNAME=	adminer
DISTVERSION=	5.3.0
CATEGORIES=	databases www
MASTER_SITES=	https://github.com/vrana/adminer/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
EXTRACT_SUFX=	.php
EXTRACT_ONLY=

MAINTAINER=	pkaipila@gmail.com
COMMENT=	Full-featured database management tool written in PHP
WWW=		https://www.adminer.org

LICENSE=	APACHE20

USES=		cpe php:flavors
USE_PHP=	session

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PHPVER="${PHP_VER}"

PLIST_SUB=	WWWGRP="${WWWGRP}" \
		WWWOWN="${WWWOWN}"

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${WWWDIR}/index.php

.include <bsd.port.mk>
