# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	PHP_Timer
PORTVERSION=	1.0.9
CATEGORIES=	devel pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Utility class for timing

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT= sebastianbergmann
GH_PROJECT=	php-timer

NO_BUILD=	yes

PHP_DIR=	share/PHP

PLIST_FILES=	${PHP_DIR}/${PORTNAME}/Timer.php

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/src/Timer.php \
		${STAGEDIR}${PREFIX}/${PHP_DIR}/${PORTNAME}

.include <bsd.port.mk>
